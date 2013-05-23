#ifndef dataH
#define dataH
/*
    Wszystkie informacje odnosnie calego planu lekcji(genotype).
    Zawieraj¹ 3 identyfikatory dla ka¿dego genu - nauczyciel, grupa, przedmiot.
    Na ka¿dym komputerze jest 1 obiekt tej klasy.
*/

//id i poziomy liczone s¹ od 1
//pozniej wejda jako static
short cl= 1;//Current_level poziom drzewa na ktorym jestesmy
short ci= 1;//current_id obecne id

class Data
{
public:
    Data(unsigned char numberOfGroups);
    ~Data();
	void Make_Forest( short *Dolans_t, knot *k );//pozniej

protected:
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