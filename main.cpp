#include "genotype.h"
#include "gene.h"
#include "information.h"
#include "data.h"
#include "genetic.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    Data d(900, 70, 90);
	/*
        Wczytywanie danych, tworzenie obiektow itd. -> Shockah
    */
    //50000 - ilosc osobnikow
    int* distributionOfGenotypes = new int[50000];
    //20 - ilosc komputerow
    k=-1;
    for(int i=0;i<50000;i++)
    {
        if(i%(50000/20)==0)
            k++;
        distributionOfGenotypes = k;
    }
    geneticAlgorithm(d, 100, 50000);
    system("pause");
    return 0;
}

