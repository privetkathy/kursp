// UnitLogin.h
#ifndef UnitLoginH
#define UnitLoginH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "UnitData.h"

class TFormUser;
class TFormAdmin;

class TFormLogin : public TForm
{
__published:
    TEdit *EditLogin;
    TEdit *EditPass;
    TButton *BtnLogin;
    TLabel *LblStatus;
    void __fastcall BtnLoginClick(TObject *Sender);
private:
public:
    __fastcall TFormLogin(TComponent* Owner);
};

extern PACKAGE TFormLogin *FormLogin;

#endif
