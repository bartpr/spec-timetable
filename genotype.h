#ifndef genotypeH
#define genotypeH
#include "gene.h"
/*
    Jest to jeden osobnik - caly plan lekcji.
    Zawiera ocen�, kar�, ilosc gen�w(grup) oraz tablic� wska�nik�w na wszystkie geny.
*/
class Genotype
{
public:
    Genotype(unsigned int numberOfGenes);
    ~Genotype();
    void Evaluation(); //Funkcja oceniaj�ca
protected:
    Gene **genes; //Tablica wszystkich przedmiot�w(po kolei wed�ug grup[klas])
    unsigned int numberOfGenes;
    double mark;
    bool penalty;
};
#endif
