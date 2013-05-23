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

  penalty+= tmpPenalty;
  return tmpPenalty;

}

bool Genotype::Mark(double &mark)
{
    mark = this->mark;
    return penalty;
}
