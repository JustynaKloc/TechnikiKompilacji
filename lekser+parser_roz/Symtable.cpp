#include "global.h"

Symtable::Symtable(){} 

Symtable::~Symtable(){
    symtable.clear();
}

void Symtable::clear_and_reset(){
    symtable.clear();
    IDlist.clear();
    current_address = 0; 
}

//sprawdzenie elementu
int Symtable::lookup(std::string s){   
    for (int i = 0; i < (int)symtable.size(); i++) {
        Entry entry = symtable.at(i);
        if (entry.name == s) {
            return i;
        }
    }
    return -1;
}
int Symtable::insertReal(string num){
    Entry entry;
    entry.vartype = VarType::REAL;
    entry.type = SymbolType::NUM;
    entry.name = num;
    symtable.push_back(entry);
    return symtable.size()-1;
}

//dodanie elementu
int Symtable::insert(std::string s)
{
    Entry entry;
    entry.type = SymbolType::ID;
    entry.name = s;
    symtable.push_back(entry);
    return symtable.size()-1;
}

int Symtable::insertNUM(string num){
    Entry entry;
    entry.vartype = VarType::INTEGER;
    entry.type = SymbolType::NUM;
    entry.name = num;
    symtable.push_back(entry);
    return symtable.size()-1;

}
void Symtable::printAll() {
    for (int i = 0; i < (int)symtable.size(); i++) {
        Entry entry = symtable.at(i);
        cout << "SymbolType: " << static_cast<int>(entry.type) 
            << ", Name / Value: " << entry.name.c_str() 
            << ", address: " << entry.address 
            << ", variableType: " << static_cast<int>(entry.vartype)
            << ", isGlobal: " << entry.isGlobal
            << ", isReference: " << entry.isRef
            << "\n";
    }
}

int Symtable::insertTempGlobal(int token){
    Entry entry;
    entry.type = SymbolType::ID;
    entry.name = "$t" + std::to_string(temp_variable);
    temp_variable++;
    entry.address = current_address;
    if (token == INTEGER){
        entry.vartype = VarType::INTEGER;
        current_address  += 4;
    }
    else {
        entry.vartype = VarType::REAL;
        current_address  += 8;
    }  
    symtable.push_back(entry);
    return symtable.size()-1;
}
int Symtable::insertTempLocal(int token){
    Entry entry;
    entry.type = SymbolType::ID;
    entry.name = "$t" + std::to_string(temp_variable);
    entry.isGlobal = false;
    temp_variable++;
    if (token == INTEGER){
        entry.vartype = VarType::INTEGER;
        negative_current_address  -= 4;
    }
    else if (token == REAL){
        entry.vartype = VarType::REAL;
        negative_current_address  -= 8;
    }  
    entry.address = negative_current_address;
    symtable.push_back(entry);
    return symtable.size()-1;
}

int Symtable::insertTempGlobal(VarType vartype){
    Entry entry;
    entry.type = SymbolType::ID;
    entry.name = "$t" + std::to_string(temp_variable);
    temp_variable++;
    entry.address = current_address;
    if (vartype == VarType::INTEGER){
        entry.vartype = VarType::INTEGER;
        current_address  += 4;
    }
    else {
        entry.vartype = VarType::REAL;
        current_address  += 8;
    }  
    symtable.push_back(entry);
    return symtable.size()-1;
}
int Symtable::insertTempLocal(VarType vartype){
    Entry entry;
    entry.type = SymbolType::ID;
    entry.isGlobal = false;
    entry.name = "$t" + std::to_string(temp_variable);
    temp_variable++;
    if (vartype == VarType::INTEGER){
        entry.vartype = VarType::INTEGER;
        negative_current_address  -= 4;
    }
    else if (vartype == VarType::REAL){
        entry.vartype = VarType::REAL;
        negative_current_address  -= 8;
    }  
    entry.address = negative_current_address;
    symtable.push_back(entry);
    return symtable.size()-1;
}

void Symtable::IDrecogized(int token){
    VarType vartype;
    if (token == INTEGER){
        vartype = VarType::INTEGER;
    }
    else if (token == REAL) {
        vartype = VarType::REAL;
    }  
    for(int i = 0; i < (int)IDlist.size(); i++){
        symtable.at(IDlist.at(i)).vartype = vartype;
        symtable.at(IDlist.at(i)).isGlobal = isGlobalScope;
        if (isGlobalScope == true){
            symtable.at(IDlist.at(i)).address = current_address;
            if (token == INTEGER){
                vartype = VarType::INTEGER;
                current_address  += 4;
            }
            else {
                vartype = VarType::REAL;
                current_address  += 8;
            }  
        }
        else {
            if (token == INTEGER){
                vartype = VarType::INTEGER;
                negative_current_address  -= 4;
            }
            else {
                vartype = VarType::REAL;
                negative_current_address  -= 8;
            }  
            symtable.at(IDlist.at(i)).address = negative_current_address;
         
        }

    }
}

void Symtable::IDrecogizedWOAdress(int token){
    VarType vartype;
    if (token == INTEGER){
        vartype = VarType::INTEGER;
    }
    else if (token == REAL) {
        vartype = VarType::REAL;
    }  
    for(int i = 0; i < (int)IDlist.size(); i++){
        symtable.at(IDlist.at(i)).vartype = vartype;
        symtable.at(IDlist.at(i)).isGlobal = isGlobalScope;

    }
}

int Symtable::insertLabel(){
    Entry entry;
    string s = "lab" + std::to_string(LabelCounter);
    LabelCounter++;
    entry.type = SymbolType::LABEL;
    entry.name = s;
    symtable.push_back(entry);
    return symtable.size()-1;
}