#ifndef genotypeH
#define genotypeH
#include "gene.h"
#include "data.h"
#include "information.h"
/*
    Jest to jeden osobnik - caly plan lekcji.
    Zawiera ocenê, karê, ilosc genów(grup) oraz tablicê wskaŸników na wszystkie geny.
*/
class Genotype
{
public:
    Genotype(const Data &data);
    ~Genotype();
    void Evaluation(); //Funkcja oceniaj¹ca
    bool Mark(double &mark);
    double termsCollision();//kolizja terminosal
    double teachersEvaluation();//kolizje i okienka nauczycieli
	double collisionsInClass(Data &d, Data::Node *p = 0, Data::Node *q = 0);
protected:
    Gene **genes; //Tablica wszystkich przedmiotów(po kolei wed³ug grup[klas])
    unsigned short numberOfGenes;
    unsigned char numberOfTerms;
    unsigned char numberOfRooms;
    unsigned char numberOfTeachers;
    double mark;
    bool penalty;
};
#endif
