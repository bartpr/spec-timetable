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
    geneticAlgorithm(d,100,50000);
    system("pause");
    return 0;
}

