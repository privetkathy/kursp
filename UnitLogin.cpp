// UnitLogin.cpp
#include <vcl.h>
#pragma hdrstop

#include "UnitLogin.h"
#include "UnitUser.h"
#include "UnitAdmin.h"
#include "UnitData.h"

// --- ”ƒјЋ»“№ ќ“сюда определение переменных (они теперь в UnitData.cpp) ---

#pragma package(smart_init)
#pragma resource "*.dfm"

TFormLogin *FormLogin;

__fastcall TFormLogin::TFormLogin(TComponent* Owner)
    : TForm(Owner)
{
    LoadDataFromFile();
}

void __fastcall TFormLogin::BtnLoginClick(TObject *Sender)
{
    UnicodeString login = EditLogin->Text;
    UnicodeString pass = EditPass->Text;
    UnicodeString passHash = XorEncrypt(pass);

    User *curr = g_UsersHead;
    bool found = false;

    while (curr != nullptr) {
        if (curr->login == login && curr->passwordHash == passHash) {
            g_CurrentUser = curr;
            found = true;
            break;
        }
        curr = curr->next;
    }

    if (found) {
        LblStatus->Caption = "”спешный вход!";
        if (g_CurrentUser->isAdmin) {
            FormAdmin->Show();
        } else {
            FormUser->Show();
        }
        this->Hide();
    } else {
        LblStatus->Caption = "Ќеверный логин или пароль";
        LblStatus->Font->Color = clRed;
    }
}
