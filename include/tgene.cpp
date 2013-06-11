#include "tgene.h"

void *prepareGene(Gene *gene, unsigned int *sPacket )
{
        uint32_t size = sizeof(*gene);


        uint32_t bSize = size+1;
        char *bufor = new char[bSize];
        memset(bufor,'\0',bSize);
        memcpy(bufor,gene,size);

        if(sPacket != NULL)
        {
         *sPacket = bSize;
        }


        return bufor;


}



void *prepareGenes(Gene **genes, unsigned int count, unsigned int *sPacket )
{
        uint32_t geneSize = sizeof(Gene);
        uint32_t bSize = (count * geneSize) + 1;

        char *bufor = new char[bSize];
        memset(bufor,'\0',bSize);

        for(unsigned int i = 0; i < count; i++)
        {
         Gene *gene = genes[i];
         memcpy(bufor+(i*geneSize),gene,geneSize);
        }

        if(sPacket != NULL)
        {
         *sPacket = bSize;
        }


        return bufor;



}