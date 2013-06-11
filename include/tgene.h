#ifndef tgene_h
#define tgene_h

#include <windows.h>
#include "gene.h"
#include <stdint.h>


void *prepareGenes(Gene **genes, unsigned int count, unsigned int *sPacket = NULL);
void *prepareGene(Gene *gene, unsigned int *sPacket = NULL);


#endif