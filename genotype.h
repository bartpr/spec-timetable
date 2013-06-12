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
	void Evaluation(Data &d); //Funkcja oceniaj¹ca
	bool Mark(double &mark); //zwraca, czy jest kara, przez referencje przekazujemy zmienna, do ktorej zostanie wpisana ocena
//protected:
	double termsCollision();//kolizja terminosal
	double teachersEvaluation(const Data &d); //kolizja nauczycieli + okienka + rozwojowo preferencje
	double collisionsInClass(Data &d, Data::Node *p = 0, Data::Node *q = 0); //kolizje w klasie + blokowanie przedmiotow
	void cleanVectors(Data::Node *p); //funkcja pomocnicza do czyszczenia wektorow w wezlach
	double eval(const Data &d, Data::Node *p = 0, unsigned short *tab = 0, int n = 0);
	double evalSubject(const Data &d, Data::Node *p); //ocena blokowania
	double evalSubject_( short int *plan ); //funkcja pomocnicza oceny blokowania
	double evalStudent( short int *tTable );
	Gene **genes; //Tablica wszystkich przedmiotów(po kolei wed³ug grup[klas])
	unsigned short numberOfGenes; //liczba genow
	unsigned char numberOfTerms; //liczba terminow
	unsigned char numberOfRooms; //liczba sal
	double mark; //ocena
	bool penalty; //flaga kary
};
#endif
