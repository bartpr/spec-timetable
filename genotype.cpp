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
    numberOfTerms = 23; //trzeba o skads wziac
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
  double const collision = 1; //wspolczynnik kolizji terminosal
  double tmpPenalty= 0;

  for( int i= 0; i< numberOfGenes; i++ )//sprawdzenia kazdej ts z kazda
    for( int j= i+1; j< numberOfGenes; j++ )
      if( genes[ i ]->term== genes[ j ]->term )
        if( genes[ i ]->room== genes[ j ]->room )
        {
          penalty= true;
          tmpPenalty-= collision;
        }

  mark+= tmpPenalty;
  return tmpPenalty;

}

double Genotype::teachersEvaluation()
{
  //do poprawki
  int nauczyciel = 22;//trzeba wyciagnac nauczyciela i zastpic kilka linijek nizej oznacznych ***
  ///////////////////////////////////////////

  double const window = 1; //wspolczynnik kary za okno
  double const collision = 2; //wspolczynnik kary za kolizje

  double tmpPenalty= 0;

  bool **tab = new bool*[numberOfTeachers];
  for (int i=0;i<numberOfTeachers;i++)
    tab[i] = new bool[numberOfTerms];

  for (int i=0;i<numberOfTeachers;i++)
    for (int j=0;j<numberOfTerms;j++)
      tab[i][j]=false;
  //zerowanie tablicy, tam gdzie lekcja bedzie true

  for( int i= 0; i< numberOfGenes; i++ )
  {
    if( tab[nauczyciel][genes[ i ]->term] ) //***
    {
      tmpPenalty -= 2; //kolizja nauczyciela
      penalty= true;
    }
    else
      tab[nauczyciel][genes[ i ]->term]=true; //***
  }

  int firstTerm, lastTerm, thisDayTerms;
  //pierwszy i ostatni termin, rozwojowo preferencje co do godzin nauczycieli (rano/wieczor)
  for (int i=0;i<numberOfTeachers;i++)
    for (int j=0;j<5;i++)//dzien tygodnia
    {
      firstTerm = lastTerm = -1;
      thisDayTerms = 0;
      for (int k=0;j<numberOfTerms/5;k++)//termin w dzien tygodnia
      {
        if(tab[i][j*(numberOfTerms/5)+k])
        {
          lastTerm = k;
          thisDayTerms++;
          if(firstTerm == -1)
            firstTerm = k;
        }
      } //znajdowanie dla danego dnia ilosci przedmiotow, pierwszej oraz ostatniej lekcji

      if (thisDayTerms>1)//jesli nie ma nawet 2 lekcji nie moze byc okienek
       tmpPenalty -= window * (lastTerm - thisDayTerms - firstTerm + 1); //okno nauczyciela
    }

  for (int i=0;i<numberOfTeachers;i++)
    delete [] tab[i];
  delete [] tab;
  //zwolnienie pamieci

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
  double const collision = 1; //wspolczynnik kary za kolizje
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
			tmpPenalty += collision*collisionsInClass(d, p, q->subgroups[i]);
		}
	}
	for(int i = 0; i < q->numberOfSubgroups; i++)
	{
		tmpPenalty += collision*collisionsInClass(d, q, q->subgroups[i]);
	}
	return tmpPenalty;
}
