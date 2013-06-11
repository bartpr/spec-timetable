#ifndef tgenotype_h
#define tgenotype_h

#include <genotype.h>

struct tgenotype
{
    unsigned short numberOfGenes;
    unsigned char numberOfTerms;
    unsigned char numberOfRooms;
    double mark;
    bool penalty;

    void setParameters(uint16_t nGenes, uint8_t nTerms, uint8_t nRooms);
    

    void setMark(double mark);
    

    void setPenalty(bool penalty);
    





};


//Dodanie friend do Genotype
void *prepareGenotype(Genotype *geno, unsigned int *sPacket = NULL);



#endif