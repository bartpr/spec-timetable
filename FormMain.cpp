//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#pragma hdrstop

#include "FormMain.h"
#include "FrmDialogText.h"
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
        FormGUI->dialogResultHasText = false;
}
//---------------------------------------------------------------------------


void __fastcall TFormGUI::Button1Click(TObject *Sender)
{
        FormGUI->dialogResultHasText = false;
        FormDialogText->ShowModal();
        if (FormGUI->dialogResultHasText) {
                Classroom c;
                c.id = FormGUI->dialogResultText;
                vClassrooms.push_back(c);
                LClassrooms->AddItem(FormGUI->dialogResultText,NULL);        
        }
}
//---------------------------------------------------------------------------

