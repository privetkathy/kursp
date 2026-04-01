// TourSystem.cpp
#include <vcl.h>
#pragma hdrstop
#pragma package(smart_init)


USEFORM("UnitAdmin.cpp", FormAdmin);
USEFORM("UnitLogin.cpp", FormLogin);
USEFORM("UnitUser.cpp", FormUser);
//---------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->MainFormOnTaskBar = true;
        Application->CreateForm(__classid(TFormLogin), &FormLogin);
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
