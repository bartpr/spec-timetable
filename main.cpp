#include "genotype.h"
#include "gene.h"
#include "information.h"
#include "data.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    Data d(80);
    fstream plik("pliczek.txt");
    for(int i = 0; i < 80; i++)
    {
         //plik << "d.tab[" << i << "].group = " << endl; - drukowanie tego nizej na wszelki wypadek
         d.tab[i].group = i / 40 + 1;//wpisywanie grup
//          cout << i << "---" << (int)d.tab[i].group << endl;
    }
    plik.close();

    //wpisywanie nauczycieli
    d.tab[0].teacher = 1;
    d.tab[1].teacher = 2;
    d.tab[2].teacher = 2;
    d.tab[3].teacher = 2;
    d.tab[4].teacher = 2;
    d.tab[5].teacher = 2;
    d.tab[6].teacher = 3;
    d.tab[7].teacher = 4;
    d.tab[8].teacher = 4;
    d.tab[9].teacher =  4;
    d.tab[10].teacher = 4;
    d.tab[11].teacher = 5;
    d.tab[12].teacher = 5;
    d.tab[13].teacher = 6;
    d.tab[14].teacher = 6;
    d.tab[15].teacher = 7;
    d.tab[16].teacher = 7;
    d.tab[17].teacher = 7;
    d.tab[18].teacher = 8;
    d.tab[19].teacher = 9;
    d.tab[20].teacher = 9;
    d.tab[21].teacher = 10;
    d.tab[22].teacher = 10;
    d.tab[23].teacher =  10;
    d.tab[24].teacher =  10;
    d.tab[25].teacher =  10;
    d.tab[26].teacher =  10;
    d.tab[27].teacher =  11;
    d.tab[28].teacher =  11;
    d.tab[29].teacher =  11;
    d.tab[30].teacher =  11;
    d.tab[31].teacher =  12;
    d.tab[32].teacher =  13;
    d.tab[33].teacher =  14;
    d.tab[34].teacher =  14;
    d.tab[35].teacher =  14;
    d.tab[36].teacher =  14;
    d.tab[37].teacher =  15;
    d.tab[38].teacher =  16;
    d.tab[39].teacher =  16;
    d.tab[40].teacher =  17;
    d.tab[41].teacher =  17;
    d.tab[42].teacher =  18;
    d.tab[43].teacher =  18;
    d.tab[44].teacher =  18;
    d.tab[45].teacher =  19;
    d.tab[46].teacher =  19;
    d.tab[47].teacher =  19;
    d.tab[48].teacher =  20;
    d.tab[49].teacher =  20;
    d.tab[50].teacher =  20;
    d.tab[51].teacher =  20;
    d.tab[52].teacher =  21;
    d.tab[53].teacher =  21;
    d.tab[54].teacher =  21;
    d.tab[55].teacher =  2;
    d.tab[56].teacher =  2;
    d.tab[57].teacher =  3;
    d.tab[58].teacher =  22;
    d.tab[59].teacher =  22;
    d.tab[60].teacher =  22;
    d.tab[61].teacher =  22;
    d.tab[62].teacher =  4;
    d.tab[63].teacher =  23;
    d.tab[64].teacher =  6;
    d.tab[65].teacher =  24;
    d.tab[66].teacher =  8;
    d.tab[67].teacher =  8;
    d.tab[68].teacher =  9;
    d.tab[69].teacher =  9;
    d.tab[70].teacher =  1;
    d.tab[71].teacher =  1;
    d.tab[72].teacher =  1;
    d.tab[73].teacher =  1;
    d.tab[74].teacher =   11;
    d.tab[75].teacher =    12;
    d.tab[76].teacher =    25;
    d.tab[77].teacher =    25;
    d.tab[78].teacher =    25;
    d.tab[79].teacher =    14;


    //wpisywanie przedmiotow
    d.tab[0].subject = 1;
    d.tab[1].subject = 2;
    d.tab[2].subject = 2;
    d.tab[3].subject = 2;
    d.tab[4].subject = 2;
    d.tab[5].subject = 2;
    d.tab[6].subject = 3;
    d.tab[7].subject = 4;
    d.tab[8].subject = 4;
    d.tab[9].subject =  4;
    d.tab[10].subject = 4;
    d.tab[11].subject = 5;
    d.tab[12].subject = 5;
    d.tab[13].subject = 6;
    d.tab[14].subject = 6;
    d.tab[15].subject = 7;
    d.tab[16].subject = 7;
    d.tab[17].subject = 7;
    d.tab[18].subject = 8;
    d.tab[19].subject = 9;
    d.tab[20].subject = 9;
    d.tab[21].subject = 10;
    d.tab[22].subject = 10;
    d.tab[23].subject =  10;
    d.tab[24].subject =  10;
    d.tab[25].subject =  10;
    d.tab[26].subject =  10;
    d.tab[27].subject =  11;
    d.tab[28].subject =  11;
    d.tab[29].subject =  11;
    d.tab[30].subject =  11;
    d.tab[31].subject =  12;
    d.tab[32].subject =  13;
    d.tab[33].subject =  14;
    d.tab[34].subject =  14;
    d.tab[35].subject =  14;
    d.tab[36].subject =  14;
    d.tab[37].subject =  15;
    d.tab[38].subject =  16;
    d.tab[39].subject =  16;
    d.tab[40].subject =  17;
    d.tab[41].subject =  17;
    d.tab[42].subject =  18;
    d.tab[43].subject =  18;
    d.tab[44].subject =  18;
    d.tab[45].subject =  19;
    d.tab[46].subject =  19;
    d.tab[47].subject =  19;
    d.tab[48].subject =  20;
    d.tab[49].subject =  20;
    d.tab[50].subject =  20;
    d.tab[51].subject =  20;
    d.tab[52].subject =  1;
    d.tab[53].subject = 1;
    d.tab[54].subject = 1;
    d.tab[55].subject = 1;
    d.tab[56].subject = 2;
    d.tab[57].subject = 2;
    d.tab[58].subject = 3;
    d.tab[59].subject = 4;
    d.tab[60].subject = 4;
    d.tab[61].subject = 4;
    d.tab[62].subject = 4;
    d.tab[63].subject = 5;
    d.tab[64].subject = 6;
    d.tab[65].subject = 7;
    d.tab[66].subject = 8;
    d.tab[67].subject = 8;
    d.tab[68].subject = 9;
    d.tab[69].subject = 9;
    d.tab[70].subject = 10;
    d.tab[71].subject = 10;
    d.tab[72].subject = 10;
    d.tab[73].subject = 10;
    d.tab[74].subject = 11;
    d.tab[75].subject = 12;
    d.tab[76].subject = 13;
    d.tab[77].subject = 13;
    d.tab[78].subject = 13;
    d.tab[79].subject = 14;

    for( int i=0; i< 80; i++)
      cout<< i<< ": "<< (int)d.tab[i].group<< ", "<< (int)d.tab[i].subject<< ", "<< (int)d.tab[i].teacher<< endl;

    system("pause");
    return 0;
}

