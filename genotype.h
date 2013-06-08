#ifndef genotypeH
#define genotypeH
#include "gene.h"
#include "data.h"
#include <fstream>
using namespace std;
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
	double collisionsInClass(Data &d, Data::Node *p = 0, Data::Node *q = 0);
	void cleanVectors(Data::Node *p);
//protected:
    Gene **genes; //Tablica wszystkich przedmiotów(po kolei wed³ug grup[klas])
    unsigned short numberOfGenes;
    unsigned char numberOfTerms;
    unsigned char numberOfRooms;
    double mark;
    bool penalty;

};
#endif
