#include "Symtable.hpp"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <sstream>
#include <algorithm>

extern int tokenval;
extern int lineno;
extern int yylex_destroy();
extern ofstream myfilesave;
extern stringstream myfile;
extern Symtable symtab;
void init();
void error(const char *m);
void parse();
void generateMathCode(string firstAddress, string secondAddress, string addressVar, string mathOperation);
void needToTypeChange(int &x1, int &x2);
void gencode(char type, int x1, int x2, int x3);
void changeTypeBeforeMove(int &x1, int &x3);
void forMove(int x1, int x2);
extern bool isGlobalScope;
void generate_relop(char command, int x1, int x2, int label);
string VarOutput(int x1);
void updateEnter(int v1);

