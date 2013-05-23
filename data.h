#ifndef dataH
#define dataH
/*
    Wszystkie informacje odnosnie calego planu lekcji(genotype).
    Zawieraj¹ 3 identyfikatory dla ka¿dego genu - nauczyciel, grupa, przedmiot.
    Na ka¿dym komputerze jest 1 obiekt tej klasy.
*/

<<<<<<< HEAD
#include <vector>
using namespace std;
=======
>>>>>>> ed2da4a22659cf0bf23886eb8659ac3d88add8d9
class Data
{
public:
    Data(unsigned char numberOfGroups);
 //   ~Data();


//protected:
    unsigned char numerOfGroups;
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
