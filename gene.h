#ifndef geneH
#define geneH
/*
    Jeden gen = jedna konkretna lekcja = konkretna grupa, przedmiot, termin, nauczyciel.
    Zawiera jedynie terminosalê. Obiekt Data zawiera wszystkie potrzebne informacje.
*/
class Gene
{
public:
    Gene();
    Gene(unsigned char term, unsigned char room);
    unsigned char Term();
    unsigned char Room();
protected:
    unsigned char term;
    unsigned char room;
};
#endif
