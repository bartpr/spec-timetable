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
	if(p== 0 && q == 0)
	{
		for(int i = 0; i < p->numberOfSubgroups; i++)
			tmpPenalty += collisionsInClass(d, d.k, d.k->subgroups[i]);
		return tmpPenalty;
	}
	if(p->numberOfLessons == 0)
	{
		p->checked.push_back(q->id);
		q->checked.push_back(p->id);
	}
	else
	{
		bool flag = false;
		for(int i = 0; i < p->checked.size(); i++)
			if(p->checked[i] == q->id)
			{
				flag = true;
				break;
			}
		if(!flag)
		{
			bool *tab = new bool[d.numberOfTerms];
			for(int i = 0; i < d.numberOfTerms; i++)
				tab[i] = false;
			for(int i = 0; i < p->numberOfLessons; i++)
				tab[genes[p->lessons[i]]->term] = true;
			for(int i = 0; i < q->numberOfLessons; i++)
				if(tab[genes[q->lessons[i]]->term])
					tmpPenalty++;
			p->checked.push_back(q->id);
			q->checked.push_back(p->id);
			delete tab;
		}
		for(int i = 0; i < q->numberOfSubgroups; i++)
		{
			tmpPenalty += collisionsInClass(d, p, q->subgroups[i]);
		}
	}
	for(int i = 0; i < q->numberOfSubgroups; i++)
	{
		tmpPenalty += collisionsInClass(d, q, q->subgroups[i]);
	}
	return tmpPenalty;
}
