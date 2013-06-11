#include "gene.h"

Gene::Gene()
{}
Gene::Gene(unsigned char t, unsigned char r) :term(t), room(r)
{}
unsigned char Gene::Term()
{
    return term;
}
unsigned char Gene::Room()
{
    return room;
}



