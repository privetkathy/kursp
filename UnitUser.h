// UnitUser.h
#ifndef UnitUserH
#define UnitUserH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include "UnitData.h"

class TFormUser : public TForm
{
__published:	// IDE-managed Components
    TStringGrid *StringGridTours;
    TEdit *EditCountry;
    TEdit *EditMaxPrice;
    TButton *BtnFilter;
    TButton *BtnSortPrice;
    TButton *BtnBook;
    TButton *BtnLogout;
    void __fastcall BtnFilterClick(TObject *Sender);
    void __fastcall BtnSortPriceClick(TObject *Sender);
    void __fastcall BtnBookClick(TObject *Sender);
    void __fastcall BtnLogoutClick(TObject *Sender);
private:	// User declarations
    void RefreshGrid(); // Вспомогательная функция обновления таблицы
public:		// User declarations
    __fastcall TFormUser(TComponent* Owner);
};

extern PACKAGE TFormUser *FormUser;

#endif
