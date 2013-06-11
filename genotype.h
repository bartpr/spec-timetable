#ifndef genotypeH
#define genotypeH
#include <stdlib.h>
#include <time.h>
#include "gene.h"
#include "data.h"
/*
    Jest to jeden osobnik - caly plan lekcji.
    Zawiera ocene, kare, ilosc genow(grup) oraz tablice wskaznikow na wszystkie geny.
*/
class Genotype
{
friend void crossover(Genotype* genotype1, Genotype* genotype2, int numberOfGenes);
friend Genotype** generateParents(Genotype** genotypes, int numberOfGenotypes);
friend void mutation(Genotype* genotype, int numberOfGenes);
public:
    Genotype& operator=(const Genotype &genotype);
    Genotype(const Data &data);
    Genotype::Genotype(const Genotype &genotype);
    ~Genotype();
    void Evaluation(); //Funkcja oceniaj¹ca
    bool Mark(double &mark);
protected:
    Gene **genes; //Tablica wszystkich przedmiotów(po kolei wed³ug grup[klas])
    unsigned short numberOfGenes;
    unsigned char numberOfTerms;
    unsigned char numberOfRooms;
    double mark;
    bool penalty;
};
#endif
