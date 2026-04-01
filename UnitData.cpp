// UnitData.cpp
#include <vcl.h>
#pragma hdrstop

#include "UnitData.h"

// --- Определение глобальных переменных (ТОЛЬКО ЗДЕСЬ) ---
Tour *g_ToursHead = nullptr;
User *g_UsersHead = nullptr;
User *g_CurrentUser = nullptr;
// ---------------------------------------------------------

// --- Реализация функций ---

UnicodeString XorEncrypt(UnicodeString text, char key) {
    UnicodeString result = "";
    for (int i = 0; i < text.Length(); i++) {
        result += (wchar_t)(text[i] ^ key);
    }
    return result;
}

void AddTourToList(int id, UnicodeString country, int price, int days, UnicodeString hotel) {
    Tour *newNode = new Tour;
    newNode->id = id;
    newNode->country = country;
    newNode->price = price;
    newNode->days = days;
    newNode->hotel = hotel;
    newNode->next = g_ToursHead;
    g_ToursHead = newNode;
}

void DeleteTourFromList(int id) {
    Tour *current = g_ToursHead;
    Tour *prev = nullptr;

    while (current != nullptr) {
        if (current->id == id) {
            if (prev == nullptr) {
                g_ToursHead = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void AddUserToList(UnicodeString login, UnicodeString pass, bool admin) {
    User *newNode = new User;
    newNode->login = login;
    newNode->passwordHash = XorEncrypt(pass);
    newNode->isAdmin = admin;
    newNode->next = g_UsersHead;
    g_UsersHead = newNode;
}

void SwapNodes(Tour* &a, Tour* &b) {
    Tour* temp = a;
    a = b;
    b = temp;
}

int Partition(std::vector<Tour*> &arr, int low, int high, bool byPrice, bool ascending) {
    Tour* pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        bool condition = false;
        if (byPrice) {
            if (ascending) condition = (arr[j]->price < pivot->price);
            else condition = (arr[j]->price > pivot->price);
        } else {
            if (ascending) condition = (arr[j]->days < pivot->days);
            else condition = (arr[j]->days > pivot->days);
        }

        if (condition) {
            i++;
            SwapNodes(arr[i], arr[j]);
        }
    }
    SwapNodes(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(std::vector<Tour*> &arr, int low, int high, bool byPrice, bool ascending) {
    if (low < high) {
        int pi = Partition(arr, low, high, byPrice, ascending);
        QuickSort(arr, low, pi - 1, byPrice, ascending);
        QuickSort(arr, pi + 1, high, byPrice, ascending);
    }
}

std::vector<Tour*> GetSortedTours(bool byPrice, bool ascending) {
    std::vector<Tour*> arr;
    Tour *curr = g_ToursHead;
    while (curr) {
        arr.push_back(curr);
        curr = curr->next;
    }
    if (!arr.empty())
        QuickSort(arr, 0, arr.size() - 1, byPrice, ascending);
    return arr;
}

std::vector<Tour*> FilterTours(UnicodeString countryFilter, int maxPrice, int minDays) {
    std::vector<Tour*> result;
    Tour *curr = g_ToursHead;

    while (curr != nullptr) {
        bool matchCountry = (countryFilter == "" || curr->country.Pos(countryFilter) > 0);
        bool matchPrice = (maxPrice == 0 || curr->price <= maxPrice);
        bool matchDays = (minDays == 0 || curr->days >= minDays);

        if (matchCountry && matchPrice && matchDays) {
            result.push_back(curr);
        }
        curr = curr->next;
    }
    return result;
}

void SaveDataToFile() {
    std::wofstream tFile("tours.dat");
    Tour *t = g_ToursHead;
    while(t) {
        tFile << IntToStr(t->id).c_str() << L";"
              << t->country.c_str() << L";"
              << t->price << L";"
              << t->days << L";"
              << t->hotel.c_str() << std::endl;
        t = t->next;
    }
    tFile.close();

    std::wofstream uFile("users.dat");
    User *u = g_UsersHead;
    while(u) {
        uFile << u->login.c_str() << L";"
              << u->passwordHash.c_str() << L";"
              << (u->isAdmin ? 1 : 0) << std::endl;
        u = u->next;
    }
    uFile.close();
}

void LoadDataFromFile() {
    g_ToursHead = nullptr;
    g_UsersHead = nullptr;

    std::wifstream tFile("tours.dat");
    if (!tFile.is_open()) {
        AddTourToList(1, "Египет", 50000, 7, "Red Sea");
        AddTourToList(2, "Турция", 45000, 10, "Antalya Beach");
        AddTourToList(3, "ОАЭ", 80000, 5, "Dubai Lux");
        AddUserToList("admin", "admin123", true);
        AddUserToList("user", "12345", false);
        SaveDataToFile();
        return;
    }
    tFile.close();
}
