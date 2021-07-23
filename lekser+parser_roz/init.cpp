#include "global.h"

using namespace std;

Symtable symtab;
ofstream myfilesave;
stringstream myfile;
bool isGlobalScope;

void init()
{
    isGlobalScope = true;

    myfilesave.open("output.txt");
}