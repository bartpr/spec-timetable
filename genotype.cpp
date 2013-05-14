#include "genotype.h"

Genotype::Genotype(unsigned int Genes) : numberOfGenes(Genes)
{
    genes = new Gene*[numberOfGenes];
    for(unsigned int i=0;i<numberOfGenes;i++)
        genes[i] = new Gene(10, 10);
}

Genotype::~Genotype()
{
    for(unsigned int i=0;i<this->numberOfGenes;i++)
    {
        delete genes[i];
    }
    delete genes;
}
