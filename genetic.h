#ifndef geneticH
#define geneticH
#include "data.h"
#include "gene.h"

void geneticAlgorithm(const Data &data, int numberOfGenerations, int numberOfGenotypes);
int* generateParents(double* tableOfMarks, int numberOfGenotypes);
void crossover(Genotype* genotype1, Genotype* genotype2, int numberOfGenes);
void mutation(Genotype* genotype, int numberOfGenes);
Genotype* copyGenotype(Genotype* genotype);

#endif
