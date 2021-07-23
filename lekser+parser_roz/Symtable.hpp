#include "string"
#include <vector>
#include <stack>
#pragma once
using namespace std;

enum class SymbolType {
    NUM,
    ID,
    FUNCTION,
    PROCEDURE,
    LABEL
};

enum class VarType {
    INTEGER,
    REAL,
    UNDEFINED
};

class Symtable {
    public:
        int negative_current_address = 0;
        int LabelCounter = 0;
        int current_address = 0; //zmienna do obecnego adresu
        int temp_variable = 0; //do zmiennych tymczasowych
        Symtable();
        ~Symtable(); //czyszczenie tablicy symboli 
        int lookup(string str); //pozycja elementu w tablicy symboli jeśli istnieje
        int insert(string str); // wsadzenie elementu
        int insertNUM(string num); // wsadzanie numa
        void printAll(); //wyrzuca wszystko
        void clear_and_reset(); //czyszczenie
        int insertReal(string num); //wsadzanie reala 
        void IDrecogized(int token); //obsługa ID real/integer
        void IDrecogizedWOAdress(int token);
        int insertTempLocal(int token);
        int insertTempGlobal(int token);
        int insertTempGlobal(VarType vartype);
        int insertTempLocal(VarType vartype);
        int insertLabel();  

        class Entry
        {
            public:
                SymbolType type;
                string name;
                int address =-1;
                VarType vartype = VarType::UNDEFINED;
                bool isGlobal = true;
                bool isRef = false;
                vector<VarType> function_types;
        };

        vector<Entry> symtable;
        vector<int> IDlist;
        vector<int> parameters;
        vector<int> expressions;
        stack<vector<int>> Stack;


};