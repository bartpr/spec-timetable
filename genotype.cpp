#include "genotype.h"

Genotype::Genotype(int numberOfGenes)
{
    this->numberOfGenes=numberOfGenes;
    this->genes = new Gene*[numberOfGenes];
    for(int i=0;i<numberOfGenes;i++)
        this->genes[i] = new Gene(10, 10);
}

Genotype::~Genotype()
{
    for(int i=0;i<this->numberOfGenes;i++)
    {
        delete genes[i];
    }
    delete genes;
}
