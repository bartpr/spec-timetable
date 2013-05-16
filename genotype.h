#ifndef genotypeH
#define genotypeH
#include "gene.h"
/*
    Jest to jeden osobnik - caly plan lekcji.
    Zawiera ocenê, karê, ilosc genów(grup) oraz tablicê wskaŸników na wszystkie geny.
*/
class Genotype
{
public:
    Genotype(unsigned int numberOfGenes);
    ~Genotype();
    void Evaluation(); //Funkcja oceniaj¹ca
protected:
    Gene **genes; //Tablica wszystkich przedmiotów(po kolei wed³ug grup[klas])
    unsigned int numberOfGenes;
    double mark;
    bool penalty;
};
#endif
