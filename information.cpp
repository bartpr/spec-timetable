#include "information.h"

Information::Information(unsigned char NumberOfGroups, unsigned char NumberOfTeachers,
                unsigned char NumberOfSubjects) : numberOfGroups(NumberOfGroups),
                numberOfTeachers(NumberOfTeachers), numberOfSubjects(NumberOfSubjects)
{
    groups = new char*[NumberOfGroups];
    for(unsigned char i=0;i<NumberOfGroups;i++)
        groups[i] = new char[10];
}
