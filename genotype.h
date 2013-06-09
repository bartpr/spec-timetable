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
  void Evaluation(); //Funkcja oceniaj¹ca
  bool Mark(double &mark);
  double termsCollision();//kolizja terminosal
  double teachersEvaluation(const Data &d, int numberOfTeachers);
  double evalSubject(Data &d, Data::Node *p);
	double collisionsInClass(Data &d, Data::Node *p = 0, Data::Node *q = 0);
  void cleanVectors(Data::Node *p);
  double Genotype::evalStudent(unsigned short *tab, int n);
	double eval(Data &d, Data::Node *p = 0, unsigned short *tab = 0, int n = 0);



//protected:
  double evalSubject_( short int *plan );
  Gene **genes; //Tablica wszystkich przedmiotów(po kolei wed³ug grup[klas])
  unsigned short numberOfGenes;
  unsigned char numberOfTerms;
  unsigned char numberOfRooms;
  double mark;
  bool penalty;
  template <class T>
  void bubble_sort(T* tab, int n)
  {
    bool swapped;
    do {
      swapped = false;
      for (int i = 0; i < n - 1; ++i) {
        if (tab[i] > tab[i + 1]) {
          swap(tab[i], tab[i + 1]);
          swapped = true;
        }
      }
    } while (swapped);
  }
  template<class T>
  T max(T a, T b)
  {
    return (a > b) ? a : b;
  }
};
#endif
