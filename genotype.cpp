#include <stdlib.h>
#include <time.h>
#include "genotype.h"

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
    

}//funkcja oceniaj¹ca

bool Genotype::Mark(double &mark)
{
    mark = this->mark;
    return penalty;
}
