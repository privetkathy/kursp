// UnitUser.cpp
#include <vcl.h>
#pragma hdrstop

#include "UnitUser.h"
#include "UnitData.h"
#include "UnitLogin.h"

#pragma package(smart_init)
#pragma resource "*.dfm"  // Обязательно для работы формы

TFormUser *FormUser;

__fastcall TFormUser::TFormUser(TComponent* Owner)
    : TForm(Owner)
{
    RefreshGrid();
}

void TFormUser::RefreshGrid() {
    StringGridTours->RowCount = 2;
    StringGridTours->Cells[0][0] = "ID";
    StringGridTours->Cells[1][0] = "Страна";
    StringGridTours->Cells[2][0] = "Цена";
    StringGridTours->Cells[3][0] = "Дни";
    StringGridTours->Cells[4][0] = "Отель";

    std::vector<Tour*> tours = FilterTours("", 0, 0);

    StringGridTours->RowCount = tours.size() + 1;
    for (int i = 0; i < tours.size(); i++) {
        StringGridTours->Cells[0][i+1] = IntToStr(tours[i]->id);
        StringGridTours->Cells[1][i+1] = tours[i]->country;
        StringGridTours->Cells[2][i+1] = IntToStr(tours[i]->price);
        StringGridTours->Cells[3][i+1] = IntToStr(tours[i]->days);
        StringGridTours->Cells[4][i+1] = tours[i]->hotel;
    }
}

void __fastcall TFormUser::BtnFilterClick(TObject *Sender) {
    UnicodeString country = EditCountry->Text;
    int maxPrice = StrToIntDef(EditMaxPrice->Text, 0);

    std::vector<Tour*> filtered = FilterTours(country, maxPrice, 0);

    StringGridTours->RowCount = filtered.size() + 1;
    for (int i = 0; i < filtered.size(); i++) {
        StringGridTours->Cells[0][i+1] = IntToStr(filtered[i]->id);
        StringGridTours->Cells[1][i+1] = filtered[i]->country;
        StringGridTours->Cells[2][i+1] = IntToStr(filtered[i]->price);
        StringGridTours->Cells[3][i+1] = IntToStr(filtered[i]->days);
        StringGridTours->Cells[4][i+1] = filtered[i]->hotel;
    }
}

void __fastcall TFormUser::BtnSortPriceClick(TObject *Sender) {
    std::vector<Tour*> sorted = GetSortedTours(true, true);

    StringGridTours->RowCount = sorted.size() + 1;
    for (int i = 0; i < sorted.size(); i++) {
        StringGridTours->Cells[0][i+1] = IntToStr(sorted[i]->id);
        StringGridTours->Cells[1][i+1] = sorted[i]->country;
        StringGridTours->Cells[2][i+1] = IntToStr(sorted[i]->price);
        StringGridTours->Cells[3][i+1] = IntToStr(sorted[i]->days);
        StringGridTours->Cells[4][i+1] = sorted[i]->hotel;
    }
}

void __fastcall TFormUser::BtnBookClick(TObject *Sender) {
    if (StringGridTours->Row > 0) {
        ShowMessage("Тур '" + StringGridTours->Cells[1][StringGridTours->Row] + "' забронирован!");
    }
}

void __fastcall TFormUser::BtnLogoutClick(TObject *Sender) {
    SaveDataToFile();
    FormUser->Hide();
    FormLogin->Show();
    FormLogin->EditLogin->Text = "";
    FormLogin->EditPass->Text = "";
}
