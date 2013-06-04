#ifndef dataH
#define dataH

/*
    Wszystkie informacje odnosnie calego planu lekcji(genotype).
    Zawieraj¹ 3 identyfikatory dla ka¿dego genu - nauczyciel, grupa, przedmiot.
    Na ka¿dym komputerze jest 1 obiekt tej klasy.
*/
#include <vector>
using namespace std;

struct knot
    {
      static unsigned short knots;//liczba utworzonych wezlow
      unsigned short id;
      knot **subgroups;//podzial grupy na podgrupy
      unsigned short *lessons;//lekcje jaka zawiera dana grupa
      vector<unsigned short> checked;//sprawdzane wezla
    };

class Data
{
public:
    Data(unsigned char numberOfGroups);
    //~Data();
	//void Make_Forest( short *Dolans_t );

protected:
	//void Make_Forest_p( short *Dolans_t, knot *k );
    unsigned char numerOfGroups;
    struct Lesson
    {
        unsigned char group, teacher, subject; //unikalne identyfikatory grupy, nauczyciela, przedmiotu
    } *tab; //wszystkie informacje o konkretnym genie
    knot *k; //korzen lasu, najbardziej ogolna grupa
};
#endif