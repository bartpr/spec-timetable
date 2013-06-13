#ifndef geneH
#define geneH
/*
    Jeden gen = jedna konkretna lekcja = konkretna grupa, przedmiot, termin, nauczyciel.
    Zawiera jedynie terminosalê. Obiekt Data zawiera wszystkie potrzebne informacje.
*/
struct Gene
{
    unsigned char term;
    unsigned char room;
};
#endif
