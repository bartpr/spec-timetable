//---------------------------------------------------------------------------

#ifndef FrmDialogComboH
#define FrmDialogComboH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormDialogCombo : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TComboBox *ComboBox1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ComboBox1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TFormDialogCombo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDialogCombo *FormDialogCombo;
//---------------------------------------------------------------------------
#endif
