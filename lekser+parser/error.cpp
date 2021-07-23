#include "global.h"

void error(const char *m)
{
  fprintf(stderr, "W linii %d masz %s\n", lineno, m);
  yylex_destroy();
  exit(1);
}
