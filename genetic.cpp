#include "genetic.h"
#include "genotype.h"
#include "data.h"
#include <iostream>

using namespace std;

void geneticAlgorithm(const Data &data, int numberOfGenerations, int numberOfGenotypes)
{
    //Stworzenie populacji poczatkowej
    Genotype** genotypes = new Genotype*[numberOfGenotypes];
    for(int i=0; i<numberOfGenotypes; i++)
    {
        genotypes[i] = new Genotype(data);
        genotypes[i]->Evaluation();
    }
    double* tableOfMarks = new double[numberOfGenotypes];
    bool* tableOfPenalty = new bool[numberOfGenotypes];
    //Pokolenia (petla glowna algorytmu genetycznego)
    for(int i=0; i<numberOfGenerations; i++)
    {
        cout<<"Pokolenie "<<i<<endl;
        for(int k=0; k>numberOfGenotypes; k++)
        {
            tableOfPenalty[k] = genotypes[k]->Mark(tableOfMarks[k]);
        }
        int* parents = new int[numberOfGenotypes];
        generateParents(tableOfMarks, numberOfGenotypes, parents);
        //Tworzenie nowego pokolenia
        for(int j=0; j<numberOfGenotypes; j += 2)
        {
            //Krzyzowanie
            crossover(genotypes[parents[j]], genotypes[parents[j+1]], data.numberOfAllLessons);
            genotypes[j]->Evaluation();
            genotypes[j+1]->Evaluation();
        }
        delete parents;
    }
    delete tableOfMarks;
    delete tableOfPenalty;
}

void generateParents(double* tableOfMarks, int numberOfGenotypes, int *parents)
{
    int sum=0;
    //Odejmowanie minumum jest opcjonalne - mozna usunac(zaleznie od efektywnosci)
    int min=tableOfMarks[0];
    for(int i=1;i<numberOfGenotypes;i++)
    {
        if(tableOfMarks[i]<min)
        {
            min=tableOfMarks[i];
        }
    }
    min--;

    for(int i=0;i<numberOfGenotypes;i++)
    {
        tableOfMarks[i]-=min;
        sum+=tableOfMarks[i];
        tableOfMarks[i]=sum;
    }
    for(int i=0;i<numberOfGenotypes;i++)
    {
        int random = rand()%sum;
        for(int j=0;j<numberOfGenotypes;j++)
        {
            if(tableOfMarks[j]>=random)
            {
                parents[i]=j;
            }
        }
    }
}

void crossover(Genotype* genotype1, Genotype* genotype2, int numberOfGenes)
{
    Gene* temp;
    int f=rand()%numberOfGenes; //Poczatek krzyzowania
    int l=rand()%(numberOfGenes-f)+f; //Koniec krzyzowania
    while(f<l)
    {
        temp = genotype1->genes[f];
        genotype1->genes[f] = genotype2->genes[f];
        genotype2->genes[f] = temp;
        f++;
    }
    mutation(genotype1, numberOfGenes);
    mutation(genotype2, numberOfGenes);
}

void mutation(Genotype* genotype, int numberOfGenes)
{
    if(rand()%1000<1)//szansa 0,1%
    {
        int k = rand()%numberOfGenes;
        delete genotype->genes[k];
        genotype->genes[k] = new Gene(rand()%genotype->numberOfTerms, rand()%genotype->numberOfRooms);
    }
}

Genotype* copyGenotype(Genotype* genotype)
{
    Genotype* newGenotype = new Genotype(genotype);
    for(int k=0; k<genotype->numberOfGenes;k++)
        newGenotype->genes[k]= new Gene(genotype->genes[k]->Term(), genotype->genes[k]->Room());
    return newGenotype;
}

