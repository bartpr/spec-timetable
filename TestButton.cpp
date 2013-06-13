//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TestButton.h"
#include "InterfejsWyjsc.h"
#include "GridForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTestForm *TestForm;
//---------------------------------------------------------------------------
__fastcall TTestForm::TTestForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTestForm::Button1Click(TObject *Sender)
{
    Tgrid * grid = new Tgrid(Owner);
    create_grid("Klasa X", *grid);
    grid->Show();
}
//---------------------------------------------------------------------------
