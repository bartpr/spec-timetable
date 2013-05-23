//---------------------------------------------------------------------------

#ifndef FormMainH
#define FormMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Tabs.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include "CGRID.h"
#include "CGAUGES.h"
#include "pies.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormGUI : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TTabSheet *TabSheet5;
        TCSpinEdit *CSpinEdit1;
        TLabel *Label1;
        TLabel *Label2;
        TCSpinEdit *CSpinEdit2;
        TListBox *LClassrooms;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TListBox *ListBox3;
        TButton *Button7;
        TButton *Button8;
        TButton *Button9;
        TLabel *Label3;
        TLabel *Label4;
        TButton *Button10;
        TButton *Button11;
        TListBox *ListBox4;
        TButton *Button12;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Newproject1;
        TMenuItem *Loadproject1;
        TMenuItem *Saveproject1;
        TMenuItem *Exit1;
        TMenuItem *Exit2;
        TMenuItem *Help1;
        TMenuItem *Generate1;
        TMenuItem *About1;
        TLabel *Label5;
        TLabel *Label6;
        TListBox *ListBox2;
        TListBox *ListBox5;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button13;
        TButton *Button14;
        TButton *Button15;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormGUI(TComponent* Owner);
        AnsiString dialogResultText;
        bool dialogResultHasText;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGUI *FormGUI;
//---------------------------------------------------------------------------
#endif
