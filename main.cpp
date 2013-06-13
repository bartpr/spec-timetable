#include "genotype.h"
#include "gene.h"
#include "information.h"
#include "data.h"
#include "genetic.h"
using namespace std;

int main(int argc, char* argv[])
{
    //Jesli serwer

    if(true)
    {
        Data d(900, 70, 90);
        /*
            Wczytywanie danych, tworzenie obiektow itd. -> Shockah
        */
        int iloscOsobnikow = 50000;
        int* distributionOfGenotypes = new int[iloscOsobnikow];
        int iloscKomputerow = 20;
        int k=0;
        for(int i=0;i<iloscOsobnikow;i++)
        {
            if(i%(iloscOsobnikow/iloscKomputerow)==0 && i!=0)
                k++;
            distributionOfGenotypes[i] = k;
        }
        geneticAlgorithm(d, 100, iloscOsobnikow, distributionOfGenotypes, iloscKomputerow);
    }else{
        /*
            Czekanie na rozkaz generowania osobnikow wraz z Data oraz iloscia
            genotypow do wygenerowania.
            if(order==1)
        */
        Data d(900, 70, 90);
        int iloscOsobnikow = 2500;
        workStation(d, iloscOsobnikow);
    }

    system("pause");
    return 0;
}

