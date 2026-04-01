// UnitAdminH
#ifndef UnitAdminH
#define UnitAdminH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include "UnitData.h"

class TFormAdmin : public TForm
{
__published:	// IDE-managed Components
    TStringGrid *StringGridAll;
    TEdit *EditNewCountry;
    TEdit *EditNewPrice;
    TEdit *EditNewDays;
    TEdit *EditNewHotel;
    TButton *BtnAdd;
    TButton *BtnDelete;
    TButton *BtnLogout;
    void __fastcall BtnAddClick(TObject *Sender);
    void __fastcall BtnDeleteClick(TObject *Sender);
    void __fastcall BtnLogoutClick(TObject *Sender);
private:	// User declarations
    void RefreshGrid();
public:		// User declarations
    __fastcall TFormAdmin(TComponent* Owner);
};

extern PACKAGE TFormAdmin *FormAdmin;

#endif
