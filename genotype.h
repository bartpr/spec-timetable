#ifndef genotypeH
#define genotypeH
#include "gene.h"
class Genotype //Jeden osobnik
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
