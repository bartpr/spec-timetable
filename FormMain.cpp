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
#include "Teacher.h"

TFormGUI *FormGUI;
vector<Classroom*> vClassrooms;
vector<Subject*> vSubjects;
vector<Teacher*> vTeachers;

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

                        for (unsigned int j = 0; j < vSubjects.size(); j++) {
                                Subject* s = vSubjects[j];
                                for (unsigned int k = 0; k < s->filters.size(); k++) {
                                        if (s->filters[k] == c) {
                                                s->filters.erase(s->filters.begin()+(k--));
                                        }
                                }
                        }

                        for (int j = 0; j < LSubjectFilters->Count; j++) {
                                if (LSubjectFilters->Items->operator[](j) == c->id) {
                                        LSubjectFilters->Clear();
                                        for (unsigned int i = 0; i < vSubjects.size(); i++) {
                                                Subject* s = vSubjects[i];
                                                if (s->name == LSubjects->Items->operator[](LSubjects->ItemIndex)) {
                                                        for (unsigned int j = 0; j < s->filters.size(); j++) {
                                                                LSubjectFilters->AddItem(s->filters[j]->id,NULL);
                                                        }
                                                        if (c != NULL) {
                                                                delete c;
                                                                c = NULL;
                                                        }
                                                        return;
                                                }
                                        }
                                }
                        }
                }
                if (c != NULL) {
                        delete c;
                        c = NULL;
                }
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
                        RSubjectFilterWhite->Checked = s->filterMode;
                        RSubjectFilterBlack->Checked = !s->filterMode;
                        for (unsigned int j = 0; j < s->filters.size(); j++) {
                                LSubjectFilters->AddItem(s->filters[j]->id,NULL);
                        }
                        return;
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormGUI::RSubjectFilterWhiteClick(TObject *Sender)
{
        if (LSubjects->ItemIndex == -1) {
            RSubjectFilterWhite->Checked = false;
            return;
        }
        for (unsigned int i = 0; i < vSubjects.size(); i++) {
                Subject* s = vSubjects[i];
                if (s->name == LSubjects->Items->operator[](LSubjects->ItemIndex)) {
                        s->filterMode = true;
                        return;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::RSubjectFilterBlackClick(TObject *Sender)
{
        if (LSubjects->ItemIndex == -1) {
            RSubjectFilterBlack->Checked = false;
            return;
        }
        for (unsigned int i = 0; i < vSubjects.size(); i++) {
                Subject* s = vSubjects[i];
                if (s->name == LSubjects->Items->operator[](LSubjects->ItemIndex)) {
                        s->filterMode = false;
                        return;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::BTeacherAddClick(TObject *Sender)
{
    FormGUI->dialogResultHasText = false;
    FormDialogText->ShowModal();
    if (FormGUI->dialogResultHasText && FormGUI->dialogResultText != "") {
            Teacher* t = new Teacher();
            t->name = FormGUI->dialogResultText;
            vTeachers.push_back(t);
            LTeachers->AddItem(FormGUI->dialogResultText,NULL);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::BTeacherRenameClick(TObject *Sender)
{
    if (LTeachers->ItemIndex == -1) return;

    AnsiString el = LTeachers->Items->operator[](LTeachers->ItemIndex);
    for (unsigned int i = 0; i < vTeachers.size(); i++) {
            Teacher* t = vTeachers[i];
            if (t->name == el) {
                    FormGUI->dialogResultHasText = true;
                    FormGUI->dialogResultText = t->name;
                    FormDialogText->ShowModal();
                    if (FormGUI->dialogResultHasText && FormGUI->dialogResultText != "") {
                            t->name = FormGUI->dialogResultText;
                            LTeachers->DeleteSelected();
                            LTeachers->AddItem(FormGUI->dialogResultText,NULL);
                    }
                    return;
            }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::BTeacherRemoveClick(TObject *Sender)
{
    if (LTeachers->ItemIndex == -1) return;

    AnsiString el = LTeachers->Items->operator[](LTeachers->ItemIndex);
    for (unsigned int i = 0; i < vTeachers.size(); i++) {
            Teacher* t = vTeachers[i];
            if (t->name == el) {
                    vTeachers.erase(vTeachers.begin()+i);
                    LTeachers->DeleteSelected();
                    return;
            }
            delete t;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormGUI::BTeacherSubjectAddClick(TObject *Sender)
{
    if (LTeachers->ItemIndex == -1) return;
    AnsiString str = LTeachers->Items->operator[](LTeachers->ItemIndex);
    Teacher* t = NULL;
    for (unsigned int i = 0; i < vTeachers.size(); i++) {
            if (vTeachers[i]->name == str) {
                    t = vTeachers[i];
                    break;
            }
    }
    if (t == NULL) return;

    dialogComboItems.clear();
    for (unsigned int i = 0; i < vSubjects.size(); i++) {
            for (unsigned int j = 0; j < t->teaches.size(); j++) {
                    if (t->teaches[j] == vSubjects[i]) {
                            goto L;
                    }
            }
            dialogComboItems.push_back(vSubjects[i]->name);
            L: {}
    }

    FormDialogCombo->ShowModal();
    if (FormGUI->dialogResultHasText && FormGUI->dialogResultText != "") {
            for (unsigned int i = 0; i < vSubjects.size(); i++) {
                    if (vSubjects[i]->name == FormGUI->dialogResultText) {
                            LTeacherSubjects->Items->Add(FormGUI->dialogResultText);
                            t->teaches.push_back(vSubjects[i]);
                            return;
                    }
            }
    }
}
//---------------------------------------------------------------------------


