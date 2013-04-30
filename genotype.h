#ifndef genotypeH
#define genotypeH
#include "gene.h"
class Genotype
{
protected:
    Gene **genes;
    int numberOfGenes;
public:
    Genotype(int numberOfGenes);
    ~Genotype();
};
#endif
