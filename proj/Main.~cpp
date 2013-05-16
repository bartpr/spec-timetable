//---------------------------------------------------------------------------

#include <vcl.h>
#include <../include/excel/libxl.h>
using namespace libxl;
using namespace std;
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   Book* book = xlCreateBook(); // xlCreateXMLBook() for xlsx
		/*if(book)
		{
			Sheet* sheet = book->addSheet("Sheet1");
			if(sheet)
			{
				sheet->writeStr(2, 1, "Hello, World !");
				sheet->writeNum(3, 1, 1000);
			}
			book->save("example.xls");
			book->release();
		} */        
}
//---------------------------------------------------------------------------

