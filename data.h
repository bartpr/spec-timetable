
#ifndef dataH
#define dataH
#include <vector>
//#include "genotype.h"
using namespace std;
/*
    Wszystkie informacje odnosnie calego planu lekcji(genotype).
    Zawieraj¹ 3 identyfikatory dla ka¿dego genu - nauczyciel, grupa, przedmiot.
    Na ka¿dym komputerze jest 1 obiekt tej klasy.
*/

#include <vector>
using namespace std;

class Data
{
public:

    Data(unsigned char NumberOfLessons, unsigned char NumberOfTerms,  unsigned char NumberOfRooms);
//    ~Data();

//protected:
    friend class Genotype;
    unsigned short numberOfLessons; //Ilosc genow
    unsigned char numberOfTerms; //Ilosc terminow w szkole np: 14*5 dni
    unsigned char numberOfRooms; //Ilosc sal

    struct Lesson
    {
        unsigned char group, teacher, subject; //unikalne identyfikatory grupy, nauczyciela, przedmiotu
    } *tab; //wszystkie informacje o konkretnym genie
    struct knot
    {
      static unsigned short knots;//liczba utworzonych wezlow
      unsigned short id;
      knot *subgroups;//podzial grupy na podgrupy
      unsigned short *lessons;//lekcje jaka zawiera dana grupa
      vector<unsigned short> checked;//sprawdzane wezla
    } *k; //korzen lasu, najbardziej ogolna grupa
};
#endif
