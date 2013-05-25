#ifndef geneticH
#define geneticH
#include "data.h"
#include "gene.h"

void geneticAlgorithm(const Data &data, int numberOfGenerations, int numberOfGenotypes);
void generateParents(Genotype** genotypes, int numberOfGenotypes);
void crossover(Genotype* genotype1, Genotype* genotype2);

#endif
