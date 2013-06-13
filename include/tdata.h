#ifndef tinformation_h
#define tinformation_h

#include "../include/data.h"
#include <stdint.h>





//Struktura transportowa dla tdata
struct tdata
{
        //Wartosci liczbowe tdata
        uint16_t numberOfAllLessons;
        uint8_t numberOfTerms;
        uint8_t numberOfRooms;

        //Ilosc wêz³ów
        uint16_t knots_count;



};



struct tknow
{
  uint16_t id, parent_id, lessons_count, checked_count;

};



//Pakiet:
/*
    Ca³y
    tdata
    Lessons char[] sizeof(Lesson) * numberOfAllLessons
    knot|knot|knot|knot


    Knot:
    uint32_t    - knot size   [if 0 - no knot more]
    -----------Struktura-------------
    uint16_t   - id
    uint16_t   - parent_id
    uint16_t   - n lessons
    uint16_r   - n checked
    --------Koniec struktury---------

    char*      - lessons - char*  - n lessons * 2b
    char*      - checked - char*  - n checked * 2b



*/
#endif