#ifndef geneticH
#define geneticH
#include "data.h"

void geneticAlgorithm(const Data &data, int numberOfGenerations, int numberOfGenotypes);
void generateParents(Genotype** genotypes, int numberOfGenotypes);

#endif
