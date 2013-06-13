//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "InterfejsWyjsc.h"
#include "GridForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tgrid *grid;
//---------------------------------------------------------------------------
__fastcall Tgrid::Tgrid(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
