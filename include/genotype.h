#ifndef genotypeH
#define genotypeH
#include <stdlib.h>
#include <time.h>
#include "gene.h"
#include "data.h"
/*
    Jest to jeden osobnik - caly plan lekcji.
    Zawiera ocen�, kar�, ilosc gen�w(grup) oraz tablic� wska�nik�w na wszystkie geny.
*/
class Genotype
{
friend void crossover(Genotype* genotype1, Genotype* genotype2, int numberOfGenes);
friend Genotype** generateParents(Genotype** genotypes, int numberOfGenotypes);
friend void mutation(Genotype* genotype, int numberOfGenes);
friend void *prepareGenotype(Genotype *geno, unsigned int *sPacket );
public:
    Genotype& operator=(const Genotype &genotype);
    Genotype(const Data &data);
    Genotype::Genotype(const Genotype &genotype);
    ~Genotype();
    void Evaluation(); //Funkcja oceniaj�ca
    bool Mark(double &mark);
protected:
    Gene **genes; //Tablica wszystkich przedmiot�w(po kolei wed�ug grup[klas])
    unsigned short numberOfGenes;
    unsigned char numberOfTerms;
    unsigned char numberOfRooms;
    double mark;
    bool penalty;
};
#endif
