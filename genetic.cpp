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
        genotypes = generateParents(genotypes, numberOfGenotypes);
        //Tworzenie nowego pokolenia
        for(int j=0; j<numberOfGenotypes; j += 2)
        {
            //Krzyzowanie
            crossover(genotypes[j], genotypes[j+1], data.numberOfAllLessons);
            genotypes[j]->Evaluation();
            genotypes[j+1]->Evaluation();
        }
    }
}

Genotype** generateParents(Genotype** genotypes, int numberOfGenotypes)
{
    Genotype** temp = new Genotype*[numberOfGenotypes];
    for(int i=0; i<numberOfGenotypes; i++)
    {
        temp[i] = new Genotype(genotypes[i]);
    }
    int sum=0;
    //Odejmowanie minumum jest opcjonalne - mozna usunac(zaleznie od efektywnosci)
    int min=genotypes[0]->mark;
    for(int i=1;i<numberOfGenotypes;i++)
    {
        if(genotypes[i]->mark<min)
        {
            min=genotypes[i]->mark;    
        }
    }
    min--;

    for(int i=0;i<numberOfGenotypes;i++)
    {
        genotypes[i]->mark-=min;
        sum+=genotypes[i]->mark;
        genotypes[i]->mark=sum;
    }
    for(int i=0;i<numberOfGenotypes;i++)
    {
        int random = rand()%sum;
        for(int j=0;j<numberOfGenotypes;j++)
        {
            if(genotypes[j]->mark>=random)
            {
                //"Kopiowanie" danych
                for(int k=0; k<genotypes[j]->numberOfGenes;k++)
                    temp[i]->genes[k]= new Gene(genotypes[j]->genes[k]->Term(), genotypes[j]->genes[k]->Room());
                break;
            }
        }
    }
    for(int i=0; i<numberOfGenotypes; i++)
        delete genotypes[i];
    delete genotypes;
    return temp;
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


