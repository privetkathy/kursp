// UnitData.h
#ifndef UnitDataH
#define UnitDataH

#include <System.hpp>
#include <fstream>
#include <vector>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>

struct Tour {
    int id;
    UnicodeString country;
    int price;
    int days;
    UnicodeString hotel;
    Tour *next;
};

struct User {
    UnicodeString login;
    UnicodeString passwordHash;
    bool isAdmin;
    User *next;
};

// Объявление переменных (extern)
extern Tour *g_ToursHead;
extern User *g_UsersHead;
extern User *g_CurrentUser;

// Объявления функций
UnicodeString XorEncrypt(UnicodeString text, char key = 'K');
void AddTourToList(int id, UnicodeString country, int price, int days, UnicodeString hotel);
void DeleteTourFromList(int id);
void AddUserToList(UnicodeString login, UnicodeString pass, bool admin);
std::vector<Tour*> GetSortedTours(bool byPrice, bool ascending);
std::vector<Tour*> FilterTours(UnicodeString countryFilter, int maxPrice, int minDays);
void SaveDataToFile();
void LoadDataFromFile();

#endif
