#ifndef Int_wyj_h
#define Int_wyj_h
#define f_kol 0
#define f_row 0

//#include data.h
#include <vector>
#include "genotype.h"
#include "data.h"
//#include <string>
#include "GridForm.h"

using namespace std;

class Inter_W
{
 friend void create_grid(const char * gridName, Tgrid & grid, Genotype * g_type);
private:
	const unsigned int d_count;
        const int l_per_day;
	vector <AnsiString> s_days; //ciagi znaków, nazwy dni
	vector <AnsiString> s_terms; //ci¹gi znaków, przedzia³y terminów
        Data * date;
protected:

public:
        //------------------ do celow testowych
            Genotype * test_gtype;
	//------------------ do celow testowych
	Inter_W();
        ~Inter_W();
};


void create_grid(const char * gridName, Tgrid & grid, Genotype * g_type = 0); //nazwa pliku oraz struktura w argumentach
#endif
