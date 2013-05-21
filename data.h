
#ifndef dataH
#define dataH
/*
    Wszystkie informacje odnosnie calego planu lekcji(genotype).
    Zawieraj¹ 3 identyfikatory dla ka¿dego genu - nauczyciel, grupa, przedmiot.
    Na ka¿dym komputerze jest 1 obiekt tej klasy.
*/
class Data
{
public:
    Data(unsigned char NumberOfLessons);
//    ~Data();

protected:
    unsigned char numberOfLessons;
    struct Lesson
    {
        unsigned char group, teacher, subject; //unikalne identyfikatory grupy, nauczyciela, przedmiotu
    } *tab; //wszystkie informacje o konkretnym genie
};
#endif
