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
public:
  Genotype(const Data &data);
  ~Genotype();
  void Evaluation(const Data &d); //Funkcja oceniaj¹ca
  bool Mark(double &mark);
  double termsCollision();//kolizja terminosal
  double teachersEvaluation(const Data &d);
	double collisionsInClass(Data &d, Data::Node *p = 0, Data::Node *q = 0);
  void cleanVectors(Data::Node *p);
	double eval(const Data &d, Data::Node *p = 0, unsigned short *tab = 0, int n = 0);
//  double termsCollision1();


//protected:
  double evalSubject(const Data &d, Data::Node *p);
  double evalSubject_( short int *plan );
  double evalStudent( short int *tTable );
  Gene **genes; //Tablica wszystkich przedmiotów(po kolei wed³ug grup[klas])
  unsigned short numberOfGenes;
  unsigned char numberOfTerms;
  unsigned char numberOfRooms;
  double mark;
  bool penalty;
};
#endif
