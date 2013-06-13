//---------------------------------------------------------------------------

#pragma hdrstop

//Basic headers
#include <iostream>
#include <stdio.h>
#include <winsock2.h>

//Daneos headers
#include <ttproto.h>
#include <distributor.h>
#include <clientqueue.h>
#include <tsocket.h>

//RdStein headers
#include <GenPacket.h>
#include "../include/tgenotype.h"
#include "../include/tgene.h"
#include "../include/tinformation.h"
#include "../include/tdata.h"


//Raf0 headers
#include <genotype.h>
#include "../include/gene.h"
#include <information.h>
#include <genetic.h>
#include "../include/data.h"



using namespace std;

//---------------------------------------------------------------------------
//Damian G³adys - RdStein
//Scalanie
//Czêsc odpowiedzialna za komunikacje miêdzy komputerami
//Wysy³anie pakietów na bazie protoko³u
/*
  11 czerwca 2013, 12:39:
  Zrealizowano biblioteki
  * GenPacket.h
        s³uzaca do zarzadzania pakietem, tworzenia i odczytywania go
  * tgenotype.h
        funkcje do serializacji calego genotypu do formy, w ktorej moze zostac wyslany
  * tgene.h
        funkcje do serializacji genu do formy bajtowej
  * tinformation.h
        funkcje do serializacji obiektu information do formy bajtowej umozliwiajacej transmisje



*/

//Inicjalizacja winsock'a
bool WinsockInit();













#pragma argsused
int main(int argc, char* argv[])
{
        WinsockInit();


        GenPacket *gg = new GenPacket;
        header *h = new header;


        Gene *g;
        g = new Gene();

        unsigned int s = 0;
        void *pGene = prepareGene(g,&s);
        cout << "Packet size: "<< s;


        char **str = new char* [5];
        for(unsigned int i = 0; i < 5; i++ )
        {
         str[i] = new char[10];
         memset(str[i],'\0',10);
         str[i] = "lol";
        }


        delete []str;


        header hd;
        hd.len = 3;
        hd.code = 13;


        header *hg = new header;
        GenPacket *ggs = new GenPacket;

        printf("GenPacket size: %d\n", sizeof(GenPacket));

        getchar();
        return 0;
}
//---------------------------------------------------------------------------






bool WinsockInit()
{
  WSADATA WSAData;
  if (WSAStartup(MAKEWORD(2,2),&WSAData) != 0)
  {
      return FALSE;
  }
  else
  {
      return TRUE;
  }
}