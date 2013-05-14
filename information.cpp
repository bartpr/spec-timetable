#include "information.h"

Information::Information(unsigned char NumberOfGroups, unsigned char NumberOfTeachers,
                unsigned char NumberOfSubjects)
{
    groups = new char*[NumberOfGroups];
    for(unsigned int i=0;i<NumberOfGroups;i++)
        groups[i] = new char[10]
}
