#include "genetic.h"
#include "genotype.h"
#include "data.h"

void geneticAlgorithm(const Data &data, int numberOfGenerations, int numberOfGenotypes)
{
    //Stworzenie populacji poczatkowej
    Genotype** genotypes = new Genotype*[numberOfGenotypes];
    for(int i=0; i<numberOfGenotypes; i++)
    {
        genotypes[i] = new Genotype(data);
        genotypes[i]->Evaluation();
    }
    //Pokolenia (petla glowna algorytmu genetycznego)
    for(int i=0; i<numberOfGenerations; i++)
    {
        generateParents(genotypes, numberOfGenotypes);
        //Tworzenie nowego pokolenia
        for(int i=0; i<numberOfGenotypes; i++)
        {
        
        }
    }
}

void generateParents(Genotype** genotypes, int numberOfGenotypes)
{
    
}

