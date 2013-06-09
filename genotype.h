#ifndef genotypeH
#define genotypeH
#include "gene.h"
#include "data.h"
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
    double teachersEvaluation(const Data &d, int numberOfTeachers);
	double collisionsInClass(Data &d, Data::Node *p = 0, Data::Node *q = 0);
  void cleanVectors(Data::Node *p);
	double eval(Data &d, Data::Node *p = 0, unsigned short *tab = 0, int n = 0);

//protected:
    Gene **genes; //Tablica wszystkich przedmiot�w(po kolei wed�ug grup[klas])
    unsigned short numberOfGenes;
    unsigned char numberOfTerms;
    unsigned char numberOfRooms;
    double mark;
    bool penalty;
};
#endif
