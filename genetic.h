#ifndef geneticH
#define geneticH
#include "data.h"
#include "gene.h"

void geneticAlgorithm(const Data &data, int numberOfGenerations, int numberOfGenotypes, int* distributionOfGenotypes, int numberOfComputers);
void workStation(const Data &data, int numberOfGenotypes);
void generateParents(double* tableOfMarks, bool* tableOfPenalty, int numberOfGenotypes, int *parents);
void crossover(Genotype* genotype1, Genotype* genotype2, int numberOfGenes);
void mutation(Genotype* genotype, int numberOfGenes);
void createPopulation(Genotype** genotypes, Data data, int numberOfGenotypes);
Genotype* copyGenotype(Genotype* genotype);

#endif
