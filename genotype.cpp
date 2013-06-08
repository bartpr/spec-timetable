#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "genotype.h"
using namespace std;


Genotype::Genotype(const Data &data)
{
    numberOfGenes = data.numberOfLessons;
    numberOfRooms = data.numberOfRooms;
    numberOfTerms = data.numberOfTerms;
    genes = new Gene*[numberOfGenes];
    srand(time(NULL));
    for(unsigned int i=0;i<numberOfGenes;i++)
    {
        int terms = rand()%data.numberOfTerms;
        int rooms = rand()%data.numberOfRooms;
        genes[i] = new Gene(terms, rooms);
    }
}

Genotype::~Genotype()
{
    for(unsigned int i=0;i<this->numberOfGenes;i++)
    {
        delete genes[i];
    }
    delete genes;
}

void Genotype::Evaluation()
{
  //zalozenia przed ocena
  penalty = false;
  mark = 0;

  termsCollision();


}//funkcja oceniaj¹ca

double Genotype::termsCollision()
{

  double tmpPenalty= 0;
  
  for( int i= 0; i< numberOfGenes; i++ )//sprawdzenia kazdej ts z kazda
    for( int j= i+1; j< numberOfGenes; j++ )
      if( genes[ i ]->term== genes[ j ]->term )
        if( genes[ i ]->room== genes[ j ]->room )
        {
          penalty= true;
          tmpPenalty--;
        }

  mark+= tmpPenalty;
  return tmpPenalty;

}

bool Genotype::Mark(double &mark)
{
    mark = this->mark;
    return penalty;
}

double Genotype::collisionsInClass(Data &d, Data::Node *p, Data::Node *q)
{
	double tmpPenalty = 0;
	if(p == 0 && q == 0) //pierwsze wywolanie
	{
		for(int i = 0; i < d.k->numberOfSubgroups; i++) //sprawdzamy kolizje korzenia z kazda podgrupa
			tmpPenalty += collisionsInClass(d, d.k, d.k->subgroups[i]);
		cleanVectors(d.k);
		return tmpPenalty;
	}
	if(p->numberOfLessons == 0) //p = d.k, (korzen nie ma lekcji)
	{
		p->checked.push_back(q->id);
		p->checked.push_back(p->id);
	}
	else
	{
		bool betweenGroups = false, inGroupP = false, inGroupQ = false;
		for(int i = 0; i < p->checked.size(); i++) 
		{
			if(p->checked[i] == q->id) //czy kolizje miêdzy grupami p i q byly sprawdzane
				betweenGroups = true;
			if(p->checked[i] == p->id) //czy byly sprawdzane kolizje wewnetrzne w grupie p
				inGroupP = true;
		}
		for(int i = 0; i < q->checked.size(); i++)
			if(q->checked[i] == q->id) //czy byly sprawdzane kolizje wewnetrzne w grupie q
				inGroupQ = true;
		if(!betweenGroups)
		{
			bool *tab = new bool[d.numberOfTerms];
			for(int i = 0; i < d.numberOfTerms; i++)
				tab[i] = false;
			for(int i = 0; i < p->numberOfLessons; i++) 
				if(!tab[genes[p->lessons[i]]->term])
					tab[genes[p->lessons[i]]->term] = true;
				else if(!inGroupP) //kolizja w grupie p
					tmpPenalty++;
			for(int i = 0; i < q->numberOfLessons; i++)
				if(tab[genes[q->lessons[i]]->term]) //kolizja miedzy p i q
					tmpPenalty++;
				else if(!inGroupQ) //kolizja w q
					tab[genes[q->lessons[i]]->term] = true;
			p->checked.push_back(q->id);
			p->checked.push_back(p->id);
			q->checked.push_back(q->id);
			delete[] tab;
		}
		for(int i = 0; i < q->numberOfSubgroups; i++) //sprawdzamy kolizje p ze wszystkimi podgrupami q
			tmpPenalty += collisionsInClass(d, p, q->subgroups[i]);
	}
	for(int i = 0; i < q->numberOfSubgroups; i++) //sprawdzamy kolizje q ze wszystkimi podgrupami q
		tmpPenalty += collisionsInClass(d, q, q->subgroups[i]);
	return tmpPenalty;
}

void Genotype::cleanVectors(Data::Node *p)
{
	p->checked.clear();
	for(int i = 0; i < p->numberOfSubgroups; i++)
		cleanVectors(p->subgroups[i]);
}
