//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#pragma hdrstop

#include "FormMain.h"
#include "FrmDialogText.h"
#include "FrmDialogCombo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "CGRID"
#pragma link "CGAUGES"
#pragma link "pies"
#pragma resource "*.dfm"

using namespace std;

#include "Classroom.h"
#include "Subject.h"

TFormGUI *FormGUI;
vector<Classroom*> vClassrooms;
vector<Subject*> vSubjects;

//---------------------------------------------------------------------------
__fastcall TFormGUI::TFormGUI(TComponent* Owner)
        : TForm(Owner)
{
        FormGUI->dialogResultHasText = false;
}
//---------------------------------------------------------------------------


void __fastcall TFormGUI::BClassroomAddClick(TObject *Sender)
{
        FormGUI->dialogResultHasText = false;
        FormDialogText->ShowModal();
        if (FormGUI->dialogResultHasText && FormGUI->dialogResultText != "") {
                Classroom* c = new Classroom();
                c->id = FormGUI->dialogResultText;
                vClassrooms.push_back(c);
                LClassrooms->AddItem(FormGUI->dialogResultText,NULL);
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::BClassroomRemoveClick(TObject *Sender)
{
        if (LClassrooms->ItemIndex == -1) return;

        AnsiString el = LClassrooms->Items->operator[](LClassrooms->ItemIndex);
        for (unsigned int i = 0; i < vClassrooms.size(); i++) {
                Classroom* c = vClassrooms[i];
                if (c->id == el) {
                        vClassrooms.erase(vClassrooms.begin()+i);
                        LClassrooms->DeleteSelected();
                        return;
                }
                for (unsigned int i = 0; i < vSubjects.size(); i++) {
                        Subject* s = vSubjects[i];
                        for (unsigned int i = 0; i < s->filters.size(); i++) {
                                if (s->filters[i] == c) {
                                        s->filters.erase(s->filters.begin()+(i--));
                                }
                        }
                }
                delete c;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::BClassroomRenameClick(TObject *Sender)
{
        if (LClassrooms->ItemIndex == -1) return;

        AnsiString el = LClassrooms->Items->operator[](LClassrooms->ItemIndex);
        for (unsigned int i = 0; i < vClassrooms.size(); i++) {
                Classroom* c = vClassrooms[i];
                if (c->id == el) {
                        FormGUI->dialogResultHasText = true;
                        FormGUI->dialogResultText = c->id;
                        FormDialogText->ShowModal();
                        if (FormGUI->dialogResultHasText && FormGUI->dialogResultText != "") {
                                c->id = FormGUI->dialogResultText;
                                LClassrooms->DeleteSelected();
                                LClassrooms->AddItem(FormGUI->dialogResultText,NULL);
                        }
                        return;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::BSubjectAddClick(TObject *Sender)
{
        FormGUI->dialogResultHasText = false;
        FormDialogText->ShowModal();
        if (FormGUI->dialogResultHasText && FormGUI->dialogResultText != "") {
                Subject* s = new Subject();
                s->name = FormGUI->dialogResultText;
                vSubjects.push_back(s);
                LSubjects->AddItem(FormGUI->dialogResultText,NULL);
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::BSubjectRenameClick(TObject *Sender)
{
        if (LSubjects->ItemIndex == -1) return;

        AnsiString el = LSubjects->Items->operator[](LSubjects->ItemIndex);
        for (unsigned int i = 0; i < vSubjects.size(); i++) {
                Subject* s = vSubjects[i];
                if (s->name == el) {
                        FormGUI->dialogResultHasText = true;
                        FormGUI->dialogResultText = s->name;
                        FormDialogText->ShowModal();
                        if (FormGUI->dialogResultHasText && FormGUI->dialogResultText != "") {
                                s->name = FormGUI->dialogResultText;
                                LSubjects->DeleteSelected();
                                LSubjects->AddItem(FormGUI->dialogResultText,NULL);
                        }
                        return;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::BSubjectRemoveClick(TObject *Sender)
{
        if (LSubjects->ItemIndex == -1) return;

        AnsiString el = LSubjects->Items->operator[](LSubjects->ItemIndex);
        for (unsigned int i = 0; i < vSubjects.size(); i++) {
                Subject* s = vSubjects[i];
                if (s->name == el) {
                        vSubjects.erase(vSubjects.begin()+i);
                        LSubjects->DeleteSelected();
                        return;
                }
                delete s;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::LClassroomsKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (!LClassrooms->Focused()) return;
        switch (Key) {
                case VK_INSERT: BClassroomAdd->Click(); break;
                case VK_DELETE: BClassroomRemove->Click(); break;
                case VK_F2: BClassroomRename->Click(); break;
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormGUI::LSubjectsKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (!LSubjects->Focused()) return;
        switch (Key) {
                case VK_INSERT: BSubjectAdd->Click(); break;
                case VK_DELETE: BSubjectRemove->Click(); break;
                case VK_F2: BSubjectRename->Click(); break;
        }        
}
//---------------------------------------------------------------------------


void __fastcall TFormGUI::BSubjectFilterAddClick(TObject *Sender)
{
        if (LSubjects->ItemIndex == -1) return;
        AnsiString str = LSubjects->Items->operator[](LSubjects->ItemIndex);
        Subject* s = NULL;
        for (unsigned int i = 0; i < vSubjects.size(); i++) {
                if (vSubjects[i]->name == str) {
                        s = vSubjects[i];
                        break;
                }
        }
        if (s == NULL) return;

        dialogComboItems.clear();
        for (unsigned int i = 0; i < vClassrooms.size(); i++) {
                for (unsigned int j = 0; j < s->filters.size(); j++) {
                        if (s->filters[j] == vClassrooms[i]) {
                                goto L;
                        }
                }
                dialogComboItems.push_back(vClassrooms[i]->id);
                L: {}
        }
        
        FormDialogCombo->ShowModal();
        if (FormGUI->dialogResultHasText && FormGUI->dialogResultText != "") {
                for (unsigned int i = 0; i < vClassrooms.size(); i++) {
                        if (vClassrooms[i]->id == FormGUI->dialogResultText) {
                                LSubjectFilters->Items->Add(FormGUI->dialogResultText);
                                s->filters.push_back(vClassrooms[i]);
                                return;
                        }
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormGUI::LSubjectsClick(TObject *Sender)
{
        LSubjectFilters->Clear();
        if (LSubjects->ItemIndex == -1) return;

        for (unsigned int i = 0; i < vSubjects.size(); i++) {
                Subject* s = vSubjects[i];
                if (s->name == LSubjects->Items->operator[](LSubjects->ItemIndex)) {
                        for (unsigned int j = 0; j < s->filters.size(); j++) {
                                LSubjectFilters->AddItem(s->filters[j]->id,NULL);
                        }
                        return;
                }
        }
}
//---------------------------------------------------------------------------

