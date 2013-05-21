#include "genotype.h"
#include "gene.h"
#include "information.h"
#include "data.h"
#include "genetic.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    Data d(10);
    geneticAlgorithm(d);
    system("pause");
    return 0;
}

