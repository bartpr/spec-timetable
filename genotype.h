#ifndef genotypeH
#define genotypeH
#include "gene.h"
#include "data.h"
/*
    Jest to jeden osobnik - caly plan lekcji.
    Zawiera ocenê, karê, ilosc genów(grup) oraz tablicê wskaŸników na wszystkie geny.
*/
class Genotype
{
friend void crossover(Genotype* genotype1, Genotype* genotype2);
public:
    Genotype(const Data &data);
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
