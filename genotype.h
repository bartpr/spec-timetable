#ifndef genotypeH
#define genotypeH
#include "gene.h"
class Genotype //Jeden osobnik
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
