#include "Symtable.hpp"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
extern int tokenval;
extern int lineno;
extern int yylex_destroy();
extern ofstream myfile;
extern Symtable symtab;
void init();
void error(const char *m);
void parse();
void generateMathCode(string firstAddress, string secondAddress, string addressVar, string mathOperation);
void gencode(char type, int x1, int x2, int x3);
