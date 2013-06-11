#ifndef tinformation_h
#define tinformation_h

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <information.h>

char *prepareStrings(char **strs, uint32_t n, unsigned int *sPacket = NULL);

//struktura informacyjna dla tinformation
struct tinformation
{
    uint8_t numberOfGroups;
    uint8_t numberOfTeachers;
    uint8_t numberOfSubjects;
    tinformation(uint8_t nGroups,uint8_t nTeachers, uint8_t nSubjects) : numberOfGroups(nGroups),  numberOfTeachers(nTeachers), numberOfSubjects(nSubjects){}
};

void* prepareInformation(Information *inf);


#endif