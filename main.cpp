#include "genotype.h"
#include "gene.h"
#include "information.h"
#include "data.h"
#include "genetic.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    Data d(200,200,200);

    /* //wpisywanie do pliku
    fstream plik("pliczek.txt");
    for(int i = 0; i < 80; i++)
    {
         plik << "d.tab[" << i << "].group = " << endl; - drukowanie tego nizej na wszelki wypadek
         cout << i << "---" << (int)d.tab[i].group << endl;
    }
    plik.close();*/

    /*
        Wczytywanie danych, tworzenie obiektow itd. -> Shockah
    */

    for(int i = 0; i < 80; i++)
        d.tab[i].group = i / 40 + 1;//wpisywanie grup

    //wpisywanie nauczycieli

    //klasa I
    int i = 0;
    d.tab[i++].teacher = 1;
    d.tab[i++].teacher = 2;
    d.tab[i++].teacher = 2;
    d.tab[i++].teacher = 2;
    d.tab[i++].teacher = 2;
    d.tab[i++].teacher = 2;
    d.tab[i++].teacher = 3;
    d.tab[i++].teacher = 4;
    d.tab[i++].teacher = 4;
    d.tab[i++].teacher = 4;
    d.tab[i++].teacher = 4;
    d.tab[i++].teacher = 5;
    d.tab[i++].teacher = 5;
    d.tab[i++].teacher = 6;
    d.tab[i++].teacher = 6;
    d.tab[i++].teacher = 7;
    d.tab[i++].teacher = 7;
    d.tab[i++].teacher = 7;
    d.tab[i++].teacher = 8;
    d.tab[i++].teacher = 9;
    d.tab[i++].teacher = 9;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher =  10;
    d.tab[i++].teacher =  10;
    d.tab[i++].teacher =  10;
    d.tab[i++].teacher =  10;
    d.tab[i++].teacher =  11;
    d.tab[i++].teacher =  11;
    d.tab[i++].teacher =  12;
    d.tab[i++].teacher =  13;
    d.tab[i++].teacher =  14;
    d.tab[i++].teacher =  14;
    d.tab[i++].teacher =  14;
    d.tab[i++].teacher =  14;
    d.tab[i++].teacher =  15;
    d.tab[i++].teacher =  16;
    d.tab[i++].teacher =  16;
    d.tab[i++].teacher =  17;
    d.tab[i++].teacher =  17;
    d.tab[i++].teacher =  18;
    d.tab[i++].teacher =  18;
    d.tab[i++].teacher =  18;
    //klasa I
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    //specki klasa I



    //klasa II
    d.tab[i++].teacher = 1;
    d.tab[i++].teacher = 2;
    d.tab[i++].teacher = 2;
    d.tab[i++].teacher = 2;
    d.tab[i++].teacher = 2;
    d.tab[i++].teacher = 2;
    d.tab[i++].teacher = 3;
    d.tab[i++].teacher = 4;
    d.tab[i++].teacher = 4;
    d.tab[i++].teacher = 4;
    d.tab[i++].teacher = 4;
    d.tab[i++].teacher = 5;
    d.tab[i++].teacher = 5;
    d.tab[i++].teacher = 6;
    d.tab[i++].teacher = 6;
    d.tab[i++].teacher = 7;
    d.tab[i++].teacher = 7;
    d.tab[i++].teacher = 7;
    d.tab[i++].teacher = 8;
    d.tab[i++].teacher = 9;
    d.tab[i++].teacher = 9;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher =  10;
    d.tab[i++].teacher =  10;
    d.tab[i++].teacher =  10;
    d.tab[i++].teacher =  10;
    d.tab[i++].teacher =  11;
    d.tab[i++].teacher =  11;
    d.tab[i++].teacher =  12;
    d.tab[i++].teacher =  13;
    d.tab[i++].teacher =  14;
    d.tab[i++].teacher =  14;
    d.tab[i++].teacher =  14;
    d.tab[i++].teacher =  14;
    d.tab[i++].teacher =  15;
    d.tab[i++].teacher =  16;
    d.tab[i++].teacher =  16;
    d.tab[i++].teacher =  17;
    d.tab[i++].teacher =  17;
    d.tab[i++].teacher =  18;
    d.tab[i++].teacher =  18;
    d.tab[i++].teacher =  18;
    //klasa II
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher =  19;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 21;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 22;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    d.tab[i++].teacher = 23;
    //specki klasa II

    cout<<i;


    //wpisywanie przedmiotow

    //klasa I
    i=0;
    d.tab[i++].subject = 1; //biologia
    d.tab[i++].subject = 2; //matema
    d.tab[i++].subject = 2;
    d.tab[i++].subject = 2;
    d.tab[i++].subject = 2;
    d.tab[i++].subject = 2;
    d.tab[i++].subject = 3;  //pp
    d.tab[i++].subject = 4; //pol
    d.tab[i++].subject = 4;
    d.tab[i++].subject = 4;
    d.tab[i++].subject = 4;
    d.tab[i++].subject = 5; //rel
    d.tab[i++].subject = 5;
    d.tab[i++].subject = 6; //niem II
    d.tab[i++].subject = 6;
    d.tab[i++].subject = 7;  //wf
    d.tab[i++].subject = 7;
    d.tab[i++].subject = 7;
    d.tab[i++].subject = 8;   //geo
    d.tab[i++].subject = 9;   //hist
    d.tab[i++].subject = 9;
    d.tab[i++].subject =  11;  //niemiecki I
    d.tab[i++].subject =  11;
    d.tab[i++].subject =  12;  //fizyka
    d.tab[i++].subject =  13;   //zwo
    d.tab[i++].subject =  14;   //progr  I
    d.tab[i++].subject =  14;
    d.tab[i++].subject =  14;
    d.tab[i++].subject =  14;
    d.tab[i++].subject =  15;   //chemia
    d.tab[i++].subject =  16;   //j ang I
    d.tab[i++].subject =  16;
    d.tab[i++].subject =  17;   //j ang II
    d.tab[i++].subject =  17;
    d.tab[i++].subject =  18;   //sois
    d.tab[i++].subject =  18;
    d.tab[i++].subject =  18;
    d.tab[i++].subject =  19;  //sois II
    d.tab[i++].subject =  19;
    d.tab[i++].subject =  19;
    d.tab[i++].subject =  20;   //progr II
    d.tab[i++].subject =  20;
    d.tab[i++].subject =  20;
    d.tab[i++].subject =  20;  //nauczyciele klasa I

    d.tab[i++].subject = 10;
    d.tab[i++].subject = 10;
    d.tab[i++].subject =  10;
    d.tab[i++].subject =  10;
    d.tab[i++].subject =  10;
    d.tab[i++].subject =  10;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 23;
    d.tab[i++].subject = 23;
    d.tab[i++].subject = 23;
    d.tab[i++].subject = 23;
    d.tab[i++].subject = 23;
    d.tab[i++].subject = 23;
        //specki klasa I



    //klasa II
    d.tab[i++].subject = 1;
    d.tab[i++].subject = 2;
    d.tab[i++].subject = 2;
    d.tab[i++].subject = 2;
    d.tab[i++].subject = 2;
    d.tab[i++].subject = 2;
    d.tab[i++].subject = 3;
    d.tab[i++].subject = 4;
    d.tab[i++].subject = 4;
    d.tab[i++].subject =  4;
    d.tab[i++].subject = 4;
    d.tab[i++].subject = 5;
    d.tab[i++].subject = 5;
    d.tab[i++].subject = 6;
    d.tab[i++].subject = 6;
    d.tab[i++].subject = 7;
    d.tab[i++].subject = 7;
    d.tab[i++].subject = 7;
    d.tab[i++].subject = 8;
    d.tab[i++].subject = 9;
    d.tab[i++].subject = 9;
    d.tab[i++].subject =  11;
    d.tab[i++].subject =  11;
    d.tab[i++].subject =  12;
    d.tab[i++].subject =  13;
    d.tab[i++].subject =  14;
    d.tab[i++].subject =  14;
    d.tab[i++].subject =  14;
    d.tab[i++].subject =  14;
    d.tab[i++].subject =  15;
    d.tab[i++].subject =  16;
    d.tab[i++].subject =  16;
    d.tab[i++].subject =  17;
    d.tab[i++].subject =  17;
    d.tab[i++].subject =  18;
    d.tab[i++].subject =  18;
    d.tab[i++].subject =  18;
    d.tab[i++].subject =  19;
    d.tab[i++].subject =  19;
    d.tab[i++].subject =  19;
    d.tab[i++].subject =  20;
    d.tab[i++].subject =  20;
    d.tab[i++].subject =  20;
    d.tab[i++].subject =  20;
    //nauczyciele klasa II

    d.tab[i++].subject = 10;
    d.tab[i++].subject = 10;
    d.tab[i++].subject =  10;
    d.tab[i++].subject =  10;
    d.tab[i++].subject =  10;
    d.tab[i++].subject =  10;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 21;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 22;
    d.tab[i++].subject = 23;
    d.tab[i++].subject = 23;
    d.tab[i++].subject = 23;
    d.tab[i++].subject = 23;
    d.tab[i++].subject = 23;
    d.tab[i++].subject = 23;
    //specki klasa II
    cout<<i;

    system("pause");
    }

