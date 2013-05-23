#include "genotype.h"
#include "gene.h"
#include "information.h"
#include "data.h"
#include "genetic.h"
#include <iostream>
using namespace std;
int main()
{
    /*
        Wczytywanie danych, tworzenie obiektow itd. -> Shockah
    */
    Data d(10, 5, 5);
    geneticAlgorithm(d,10,100);
    system("pause");
    return 0;
}

