#ifndef genotypeH
#define genotypeH
#include "gene.h"
#include "data.h"
#include "information.h"
/*
    Jest to jeden osobnik - caly plan lekcji.
    Zawiera ocen�, kar�, ilosc gen�w(grup) oraz tablic� wska�nik�w na wszystkie geny.
*/
class Genotype
{
public:
    Genotype(const Data &data);
    ~Genotype();
    void Evaluation(); //Funkcja oceniaj�ca
    bool Mark(double &mark);
    double termsCollision();//kolizja terminosal
    double teachersEvaluation();//kolizje i okienka nauczycieli
	double collisionsInClass(Data &d, Data::Node *p = 0, Data::Node *q = 0);
protected:
    Gene **genes; //Tablica wszystkich przedmiot�w(po kolei wed�ug grup[klas])
    unsigned short numberOfGenes;
    unsigned char numberOfTerms;
    unsigned char numberOfRooms;
    unsigned char numberOfTeachers;
    double mark;
    bool penalty;
};
#endif
