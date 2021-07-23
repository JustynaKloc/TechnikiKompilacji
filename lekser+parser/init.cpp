#include "global.h"

using namespace std;

Symtable symtab;
ofstream myfile;

void init()
{
    myfile.open("output.txt");
}