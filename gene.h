#ifndef geneH
#define geneH
/*
    Jeden gen = jedna konkretna lekcja = konkretna grupa, przedmiot, termin, nauczyciel.
    Zawiera jedynie terminosalÍ. Obiekt Data zawiera wszystkie potrzebne informacje.
*/
class Gene
{
public:
    Gene();
    Gene(unsigned char term, unsigned char room);
    ~Gene();
    unsigned char Term();
    unsigned char Room();
protected:
    unsigned char term;
    unsigned char room;
};
#endif
