#ifndef geneticH
#define geneticH
#include "data.h"
#include "gene.h"

void geneticAlgorithm(const Data &data, int numberOfGenerations, int numberOfGenotypes);
void generateParents(double* tableOfMarks, int numberOfGenotypes, int *parents);
void crossover(Genotype* genotype1, Genotype* genotype2, int numberOfGenes);
void mutation(Genotype* genotype, int numberOfGenes);
Genotype* copyGenotype(Genotype* genotype);

#endif
