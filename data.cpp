#include "data.h"
unsigned short Data::knot::knots = 0;



Data::Data(unsigned char numberOfLessons)
{
    tab = new Lesson[numberOfLessons];
}


