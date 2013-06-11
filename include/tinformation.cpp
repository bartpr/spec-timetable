#include <tinformation.h>

char *prepareStrings(char **strs, uint32_t n, unsigned int *sPacket )
{
        //Obliczenie rozmiaru dla bufora
        uint32_t bSize = 0;
        for(uint32_t i = 0; i < n; i++)
        {
          bSize = strlen(strs[i]);
        }

        char div_char = '\n';

        //Dla znaku oddzielajacego stringi
        bSize += n - 1;
        //Dla znaku konca NULL
        bSize += 1;


        //Bufor cstring'ów
        char *bufor = new char[bSize];
        memset(bufor,'\0',bSize);

        unsigned int o = 0;
        for(uint32_t i = 0; i < n; i++)
        {
          strcpy(bufor + o, strs[i] );
          o += strlen(strs[i]);
          if(i != n -1)
          {
                memset(bufor+o,div_char,1);
          }
          else
          {
                memset(bufor+o,'\0',1);
          }
          o += 1;

        }

        if(sPacket != NULL)
        {
         *sPacket = bSize;
        }

        return bufor;






}



void* prepareInformation(Information *inf)
{
    tinformation *tinf = new tinformation(inf->numberOfGroups, inf->numberOfTeachers, inf->numberOfSubjects);



    char div_char = '\r';

    //Deserializacja stringow
    unsigned int s1 = 0;
    char *b1 = prepareStrings(inf->groups, inf->numberOfGroups,&s1);
    unsigned int s2 = 0;
    char *b2 = prepareStrings(inf->groups, inf->numberOfTeachers,&s2);
    unsigned int s3 = 0;
    char *b3 = prepareStrings(inf->groups, inf->numberOfSubjects,&s3);

    //Inicjalizacja bufora
    size_t bSize = sizeof(tinformation) + s1 + s2 + s3;
    char *bufor = new char[bSize];
    memset(bufor,'\0',bSize);

    //Skopiowanie struktury tinf
    memcpy(bufor,tinf,sizeof(tinformation));

    char *pBufor = bufor + sizeof(tinformation);
    strcpy(pBufor, b1);
    pBufor += s1;
    *(pBufor-1) = div_char;

    strcpy(pBufor, b2);
    pBufor += s2;
    *(pBufor-1) = div_char;

    strcpy(pBufor, b3);
    pBufor += s3;

    return bufor;

}