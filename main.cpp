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
    Data d(80, 70, 80);
	/*
        Wczytywanie danych, tworzenie obiektow itd. -> Shockah
    */
    geneticAlgorithm(d,10,100);
    system("pause");
    return 0;
}

