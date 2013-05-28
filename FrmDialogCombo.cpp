//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#pragma hdrstop

using namespace std;

#include "FrmDialogCombo.h"
#include "FormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDialogCombo *FormDialogCombo;

//---------------------------------------------------------------------------
__fastcall TFormDialogCombo::TFormDialogCombo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormDialogCombo::FormShow(TObject *Sender)
{
        ComboBox1->Items->Clear();
        for (unsigned int i = 0; i < FormGUI->dialogComboItems.size(); i++) {
                ComboBox1->Items->Add(FormGUI->dialogComboItems[i]);
        }

        FormGUI->Enabled = false;
        FormGUI->dialogResultHasText = false;
        ComboBox1->Text = "";
        ComboBox1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFormDialogCombo::ComboBox1Change(TObject *Sender)
{
        AnsiString str = ComboBox1->Items->operator[](ComboBox1->ItemIndex);
        for (unsigned int i = 0; i < FormGUI->dialogComboItems.size(); i++) {
                if (FormGUI->dialogComboItems[i] == str) return;
        }
        ComboBox1->Items->Delete(ComboBox1->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TFormDialogCombo::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        FormGUI->dialogResultText = ComboBox1->Items->operator[](ComboBox1->ItemIndex);
	FormGUI->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormDialogCombo::Button1Click(TObject *Sender)
{
        FormGUI->dialogResultHasText = true;
        FormDialogCombo->Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormDialogCombo::Button2Click(TObject *Sender)
{
        FormDialogCombo->Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormDialogCombo::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_ESCAPE) Button2->Click();        
}
//---------------------------------------------------------------------------
