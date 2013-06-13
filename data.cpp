#include "data.h"
unsigned short Data::knot::knots = 0;
//Kontruktor do edycji przez Shockah
Data::Data(unsigned char NumberOfAllLessons, unsigned char NumberOfTerms,  unsigned char NumberOfRooms)
 : numberOfAllLessons(NumberOfAllLessons), numberOfTerms(NumberOfTerms), numberOfRooms(NumberOfRooms)
{
    tab = new Lesson[numberOfAllLessons];
}


