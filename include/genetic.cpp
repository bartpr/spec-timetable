#include "genetic.h"
#include "genotype.h"
#include "data.h"
#include <iostream>

using namespace std;

void geneticAlgorithm(const Data &data, int numberOfGenerations, int numberOfGenotypes, int* distributionOfGenotypes, int numberOfComputers)
{
    srand(time(NULL));

    //Wyslanie rozkazu generowania osobnikow do kazdej stacji
    for(int i=0; i<numberOfComputer; i++)
    {
        //Rozkaz(orderCreatePopulation(1), data, computerNumber(i), numberOfGenotypes/numberOfComputers);
    }
    double* tableOfMarks = new double[numberOfGenotypes];
    bool* tableOfPenalty = new bool[numberOfGenotypes];

    
    //Pokolenia (petla glowna algorytmu genetycznego)
    for(int i=0; i<numberOfGenerations; i++)
    {
        cout<<"Pokolenie "<<i<<endl;
        /*
            Wypelnienie tablic tableOfMarks i tableOfPenalty danymi otrzymanymi
            ze stacji roboczych.
        */
        int* parents = new int[numberOfGenotypes];
        generateParents(tableOfMarks, tableOfPenalty, numberOfGenotypes, parents);
        //Tworzenie nowego pokolenia
        /*
            Wysylanie rozkazow przesylania oraz krzyzowania do poszczegolnych
            stacji roboczych oraz edycja tablicy distributionOfGenotypes.
            np:                                   '
            kazdy komputer 1000 osobnikow

            tablica parents[0] = 8000;
            8000-> osobnik[0] na komputerze 8(liczenie od 0)
            wysylanie do komputera 8 komendy: Przeslij(0, 0);
            Komputer 8 - Wysylanie(Osobnik[0], 0) do komputer 0;

            tablica parents[1245] = 3200;
            3200-> osobnik[200] na komputerze 3(liczenie od 0)
            wysylanie do komputera 3 komendy: Przeslij(200, 1245);
            Komputer 3 - Wysylanie(Osobnik[200], 245) do komputer 1;

            tablica parents[3585] = 2320;
            2320-> osobnik[320] na komputerze 2(liczenie od 0)
            wysylanie do komputera 2 komendy: Przeslij(320, 3585);
            Komputer 2 - Wysylanie(Osobnik[320], 585) do komputer 3;
        */
        for(int p=0; p<numberOfGenotypes; p++)
        {
            /*
                Wysylamy komende Przeslij(parents[p]%(numberOfGenotypes/numberOfComputers),
                p); na int(parents[p]/(numberOfGenotypes/numberOfComputers))
            */
        }
        for(int i=0; i<numberOfComputer; i++)
        {
            //Wysylamy komende ZakonczenieWysylania na kazdy komputer;
        }
        /*
            Czekamy na otrzymanie wszystkich ocen
        */

        delete parents;
    }
    delete tableOfMarks;
    delete tableOfPenalty;
}

void workStation(const Data &data, int numberOfGenotypes)
{
    Genotype** genotypes;
    createPopulation(genotypes, data, numberOfGenotypes);
    int order = 3; //Komenda - nic
    while(order != 0)
    {
        //Watek odpowiedzialny za otrzymywanie komend i danych
        switch(order)
        {
            case 1:
                /*
                    Otrzymalismy a i b.
                    Przeslij genotypy na inna stacje - Wyslij(genotypes[a], b%numberOfGenotypes)
                    na komputer int(b/numberOfGenotypes)
                */
                break;
            case 2:
                /*
                    Przesylanie zakonczone - wczytuje dane z bufora i krzyzuju
                    swoja populacje po kolei
                */
                int* parents = new int[numberOfGenotypes]; //Zamienic na otrzymywanie
                for(int j=0; j<numberOfGenotypes; j += 2)
                {
                    //Krzyzowanie
                    crossover(genotypes[j]], genotypes[j+1], data.numberOfAllLessons);
                    genotypes[j]->Evaluation();
                    genotypes[j+1]->Evaluation();
                }
                //Wyslanie tablicy z ocenami
                break;
        }
        //Oczekiwanie na otrzymanie rozkazu
    }
}

/*

*/

void createPopulation(Genotype** genotypes, Data data, int numberOfGenotypes)
{
    //Stworzenie populacji poczatkowej
    genotypes = new Genotype*[numberOfGenotypes];
    for(int i=0; i<numberOfGenotypes; i++)
    {
        genotypes[i] = new Genotype(data);
        genotypes[i]->Evaluation();
    }
}

void generateParents(double* tableOfMarks, bool* tableOfPenalty, int numberOfGenotypes, int *parents)
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


