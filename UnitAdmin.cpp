// UnitAdmin.cpp
#include <vcl.h>
#pragma hdrstop

#include "UnitAdmin.h"
#include "UnitData.h"
#include "UnitLogin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"  // Обязательно для работы формы

TFormAdmin *FormAdmin;

__fastcall TFormAdmin::TFormAdmin(TComponent* Owner)
    : TForm(Owner)
{
    RefreshGrid();
}

void TFormAdmin::RefreshGrid() {
    StringGridAll->RowCount = 2;
    StringGridAll->Cells[0][0] = "ID";
    StringGridAll->Cells[1][0] = "Страна";
    StringGridAll->Cells[2][0] = "Цена";

    Tour *curr = g_ToursHead;
    int count = 0;
    while(curr) {
        count++;
        curr = curr->next;
    }
    StringGridAll->RowCount = count + 1;

    curr = g_ToursHead;
    int row = 1;
    while(curr) {
        StringGridAll->Cells[0][row] = IntToStr(curr->id);
        StringGridAll->Cells[1][row] = curr->country;
        StringGridAll->Cells[2][row] = IntToStr(curr->price);
        curr = curr->next;
        row++;
    }
}

void __fastcall TFormAdmin::BtnAddClick(TObject *Sender) {
    static int nextId = 100;
    UnicodeString country = EditNewCountry->Text;
    int price = StrToIntDef(EditNewPrice->Text, 0);
    int days = StrToIntDef(EditNewDays->Text, 0);
    UnicodeString hotel = EditNewHotel->Text;

    if (country != "" && price > 0) {
        AddTourToList(nextId++, country, price, days, hotel);
        RefreshGrid();
        SaveDataToFile();
        ShowMessage("Тур добавлен");
    } else {
        ShowMessage("Заполните поля корректно");
    }
}

void __fastcall TFormAdmin::BtnDeleteClick(TObject *Sender) {
    if (StringGridAll->Row > 0) {
        int idToDelete = StrToInt(StringGridAll->Cells[0][StringGridAll->Row]);
        DeleteTourFromList(idToDelete);
        RefreshGrid();
        SaveDataToFile();
    }
}

void __fastcall TFormAdmin::BtnLogoutClick(TObject *Sender) {
    FormAdmin->Hide();
    FormLogin->Show();
}
