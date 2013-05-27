#include "data.h"
unsigned short Data::Node::nodes = 0;



//Kontruktor do edycji przez Shockah
Data::Data(unsigned char NumberOfLessons, unsigned char NumberOfTerms,  unsigned char NumberOfRooms)
 : numberOfLessons(NumberOfLessons), numberOfTerms(NumberOfTerms), numberOfRooms(NumberOfRooms)
{
    tab = new Lesson[numberOfLessons];
}


