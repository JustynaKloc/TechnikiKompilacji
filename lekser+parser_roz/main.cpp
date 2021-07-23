#include "global.h"
int main()
{
  init();
  parse();
  symtab.printAll();
  myfilesave << myfile.rdbuf();
  myfilesave.close();
  yylex_destroy();
  return 0;
}