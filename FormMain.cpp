//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#pragma hdrstop

#include "FormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "CGRID"
#pragma link "CGAUGES"
#pragma link "pies"
#pragma resource "*.dfm"

using namespace std;

#include "Classroom.h"

TFormGUI *FormGUI;
vector<Classroom> vClassrooms;

//---------------------------------------------------------------------------
__fastcall TFormGUI::TFormGUI(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------




