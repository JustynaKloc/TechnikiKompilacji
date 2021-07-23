#include "global.h"

Symtable::Symtable(){} 

Symtable::~Symtable(){
    symtable.clear();
}

void Symtable::clear_and_reset(){
    symtable.clear();
    current_address = 0; 
}

//sprawdzenie ostatniego elementu
int Symtable::lookup(std::string s){
    for (int i = 0; i < (int)symtable.size(); i++) {
        Entry entry = symtable.at(i);
        if (entry.name == s) {
            return i;
        }
    }
    return -1;
}

//dodanie elementu
int Symtable::insert(std::string s)
{
    Entry entry;
    entry.type = SymbolType::ID;
    entry.name = s;
    entry.address = current_address;
    current_address += 4;
    symtable.push_back(entry);
    return symtable.size()-1;
}

int Symtable::insertNUM(int num){
    Entry entry;
    entry.type = SymbolType::NUM;
    entry.value = num;
    symtable.push_back(entry);
    return symtable.size()-1;

}
void Symtable::printAll() {
    for (int i = 0; i < (int)symtable.size(); i++) {
        Entry entry = symtable.at(i);
        if (entry.type == SymbolType::ID) {
            printf("ID: %s, ADDRESS: %d\n", entry.name.c_str(), entry.address);
        } else {
            printf("NUM: %d \n", entry.value);
        }
    }
}

int Symtable::insertTemp(){
    Entry entry;
    entry.type = SymbolType::ID;
    entry.name = "$t" + std::to_string(temp_variable);
    temp_variable++;
    entry.address = current_address;
    current_address += 4;
    symtable.push_back(entry);
    return symtable.size()-1;
}
