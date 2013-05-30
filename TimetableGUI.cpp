//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("FormMain.cpp", FormGUI);
USEFORM("FrmDialogText.cpp", FormDialogText);
USEFORM("FrmDialogCombo.cpp", FormDialogCombo);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormGUI), &FormGUI);
         Application->CreateForm(__classid(TFormDialogText), &FormDialogText);
         Application->CreateForm(__classid(TFormDialogCombo), &FormDialogCombo);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
