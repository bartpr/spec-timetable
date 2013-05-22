//---------------------------------------------------------------------------

#ifndef forestH
#define forestH
#include <vector> //ewentualnie zamienic na liste
using namespace std
class forest
{
  public:

  private:
    class knot
    {
      public:

      private:
        static unsigned short knots;//liczba utworzonych wezlow
        unsigned short id;
        knot** subgroups;//podzial grupy na pod grupy
        unsigned short* lessons;//lekcje jaka zawiera dana grupa
        vector<unsigned short> checked;//sprawdzane wezly

    }

};
//---------------------------------------------------------------------------
#endif
 