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

#include <vector>
using namespace std;
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
        TButton *BClassroomAdd;
        TButton *BClassroomRename;
        TButton *BClassroomRemove;
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
        TListBox *LSubjects;
        TListBox *LSubjectFilters;
        TButton *BSubjectAdd;
        TButton *BSubjectRename;
        TButton *BSubjectRemove;
        TButton *BSubjectFilterAdd;
        TButton *BSubjectFilterRemove;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        void __fastcall BClassroomAddClick(TObject *Sender);
        void __fastcall BClassroomRemoveClick(TObject *Sender);
        void __fastcall BClassroomRenameClick(TObject *Sender);
        void __fastcall BSubjectAddClick(TObject *Sender);
        void __fastcall BSubjectRenameClick(TObject *Sender);
        void __fastcall BSubjectRemoveClick(TObject *Sender);
        void __fastcall LClassroomsKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall LSubjectsKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall BSubjectFilterAddClick(TObject *Sender);
        void __fastcall LSubjectsClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormGUI(TComponent* Owner);
        AnsiString dialogResultText;
        bool dialogResultHasText;
		vector<AnsiString> dialogComboItems;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGUI *FormGUI;
//---------------------------------------------------------------------------
#endif
