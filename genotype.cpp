#include "genotype.h"

Genotype::Genotype(const Genotype* genotype)
{
    numberOfGenes = genotype->numberOfGenes;
    numberOfRooms = genotype->numberOfRooms;
    numberOfTerms = genotype->numberOfTerms;
    genes = new Gene*[numberOfGenes];
}

Genotype::Genotype(const Data &data)
{
    numberOfGenes = data.numberOfAllLessons;
    numberOfRooms = data.numberOfRooms;
    numberOfTerms = data.numberOfTerms;
    genes = new Gene*[numberOfGenes];
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
  penalty = false;
  mark = 0;
  //zalozenia przed ocena
}//funkcja oceniaj¹ca

bool Genotype::Mark(double &mark)
{
    mark = this->mark;
    return penalty;
}
