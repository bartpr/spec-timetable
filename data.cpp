#include "data.h"

Data::Data(unsigned char NumberOfLessons) : numberOfLessons(NumberOfLessons)
{
    tab = new Lesson[numberOfLessons];
}
