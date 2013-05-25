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
            //Krzyzowanie
            crossover(genotypes[i], genotypes[i+1]);
        }
    }
}

void generateParents(Genotype** genotypes, int numberOfGenotypes)
{

}

void crossover(Genotype* genotype1, Genotype* genotype2)
{
    //Ocena nowych osobnikow
    Gene *temp;


    int i=0; //Tutaj bedzie petla for, losowanie przedzialu (k) itd.
    temp = genotype1->genes[i];
    genotype1->genes[i] = genotype2->genes[i];
    genotype2->genes[i] = temp;
    //Tutaj zakonczy sie petla
    delete temp;
    genotype1->Evaluation();
    genotype2->Evaluation();
}


