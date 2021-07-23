#include "global.h"
int main()
{
  init();
  parse();
  symtab.printAll();
  yylex_destroy();
  return 0;
}