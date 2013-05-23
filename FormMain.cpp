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

void __fastcall TFormGUI::Button3Click(TObject *Sender)
{
        if (LClassrooms->ItemIndex == -1) return;

        AnsiString el = LClassrooms->Items->operator[](LClassrooms->ItemIndex);
        for (unsigned int i = 0; i < vClassrooms.size(); i++) {
                Classroom c = vClassrooms[i];
                if (c.id == el) {
                        vClassrooms.erase(vClassrooms.begin()+i);
                        LClassrooms->DeleteSelected();
                        return;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::Button2Click(TObject *Sender)
{
        if (LClassrooms->ItemIndex == -1) return;

        AnsiString el = LClassrooms->Items->operator[](LClassrooms->ItemIndex);
        for (unsigned int i = 0; i < vClassrooms.size(); i++) {
                Classroom c = vClassrooms[i];
                if (c.id == el) {
                        FormGUI->dialogResultHasText = true;
                        FormGUI->dialogResultText = c.id;
                        FormDialogText->ShowModal();
                        if (FormGUI->dialogResultHasText) {
                                c.id = FormGUI->dialogResultText;
                                LClassrooms->DeleteSelected();
                                LClassrooms->AddItem(FormGUI->dialogResultText,NULL);
                        }
                        return;
                }
        }
}
//---------------------------------------------------------------------------

