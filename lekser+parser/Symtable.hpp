#include "string"
#include <vector>
#pragma once
using namespace std;

enum class SymbolType {
    NUM,
    ID
};

class Symtable {
    public:
        Symtable();
        ~Symtable(); //czyszczenie tablicy symboli 
        int lookup(string str); //pozycja elementu w tablicy symboli jeśli istnieje
        int insert(string str); // wsadzenie elementu
        int insertNUM(int num); // wsadzanie numa
        void printAll(); //wyrzuca wszystko
        int current_address = 0; //zmienna do obecnego adresu
        int temp_variable = 0; //do zmiennych tymczasowych
        void clear_and_reset(); //czyszczenie
        int insertTemp(); //wsadzanie zmiennej tymczasowej 

        class Entry
        {
            public:
                SymbolType type;
                string name;
                int value;
                unsigned address;
        };

        vector<Entry> symtable;
};