%{
  #include "global.h"
  #include <iostream>
  extern Symtable symtab;
  
  extern int yylex();

  void yyerror (char const *s)
  {
    error((char *)s);
  }

%}
%token PROGRAM 
%token NUM           
%token ID
%token VAR
%token DIV
%token MODULO
%token MUL
%token M_DIV
%token INTEGER
%token BEGIN_TOKEN
%token END_TOKEN
%token OPERATOR
%token ASSIGNOP
%token READ
%token WRITE
%token REAL
%token ARRAY 
%token OF
%token FUNCTION
%token PROCEDURE
%token IF
%token THEN
%token ELSE
%token WHILE
%token DO
%token RELOP
%token OR
%token t_PLUS
%token t_MINUS
%token AND
%token NOT
%token NONE

%start program
%%

program:
  PROGRAM ID '(' identifier_list ')' ';' {
    symtab.clear_and_reset();
    myfile << "lab0: \n";
  }
  declarations
  subprogram_declarations
  compound_statement 
  '.'{
    myfile << "\texit";
  }
  ;

identifier_list:
  ID
  | identifier_list ',' ID
  ;

declarations:       
  declarations VAR identifier_list ':' type ';'
  | %empty
  ;

type:               
  standard_type
  | ARRAY '[' NUM '.' '.' NUM ']' OF standard_type
  ;

standard_type:
  INTEGER
  | REAL
  ;

subprogram_declarations:
  subprogram_declarations subprogram_declaration ';'
  | %empty
  ;

subprogram_declaration:
  subprogram_head declarations compound_statement
  ;

subprogram_head:
  FUNCTION ID arguments ':' standard_type ';'
  | PROCEDURE ID arguments ';'
  ;

arguments:
  '(' parameter_list ')'
  | %empty
  ;

parameter_list:     
  identifier_list ':' type
  | parameter_list ',' identifier_list ':' type
  | parameter_list ';' identifier_list ':' type
  ;

compound_statement: 
  BEGIN_TOKEN 
  optional_statements 
  END_TOKEN
  ;

optional_statements: 
  statement_list
  | %empty
  ;

statement_list:     
  statement
  | statement_list ';' statement
  ;

statement:
  variable ASSIGNOP expression
  {
      string firstVar = "";
      if (symtab.symtable.at($3).type == SymbolType::ID){
      firstVar = std::to_string(symtab.symtable.at($3).address);
    }
    else{
      firstVar = "#" + std::to_string(symtab.symtable.at($3).value);
    }

    myfile << "\tmov.i \t" + firstVar + ", " + std::to_string(symtab.symtable.at($1).address) + "\n";
  }
  | procedure_statement
  | compound_statement
  | IF expression THEN statement ELSE statement
  | WHILE expression DO statement
  | WRITE '(' ID ')' {
    myfile << "\twrite.i\t" + std::to_string(symtab.symtable.at($3).address) + "\n";
  }
  ;

variable:
  ID
  | ID '[' expression ']'
  ;

procedure_statement:
  ID
  | ID '(' expression_list ')'
  ;

expression_list:
  expression
  | expression_list ',' expression
  ;

expression:
  simple_expression
  | simple_expression RELOP simple_expression
  ;

simple_expression:
  term
  | t_PLUS term
  {
    $$ = $2;
  }
  | t_MINUS term
  {
    int temp_num_pos  = symtab.insertNUM(0);
    int temp_pos = symtab.insertTemp();
    gencode('-', temp_num_pos, $2, temp_pos);
    $$ = temp_pos;
  }
  | simple_expression t_PLUS term
  {
    int temp_variable_pos = symtab.insertTemp();
    gencode('+', $1, $3, temp_variable_pos);
    $$ = temp_variable_pos;
  }
  | simple_expression t_MINUS term
    {
    int temp_variable_pos = symtab.insertTemp();
    gencode('-', $1, $3, temp_variable_pos);
    $$ = temp_variable_pos;
  }
  | simple_expression OR term
  | simple_expression AND term
  ;
        
term:
  factor
  | term MODULO factor{
    int temp_variable_pos = symtab.insertTemp();
    gencode('%', $1, $3, temp_variable_pos);
    $$ = temp_variable_pos;
  }
  | term MUL factor
  {
    int temp_variable_pos = symtab.insertTemp();
    gencode('x', $1, $3, temp_variable_pos);
    $$ = temp_variable_pos;
    }
  | term M_DIV factor
  {
    int temp_variable_pos = symtab.insertTemp();
    gencode('/', $1, $3, temp_variable_pos);
    $$ = temp_variable_pos;
}
  ;

factor:
  variable
  | ID '(' expression_list ')'
  | NUM
  | '(' expression ')'{
    $$ = $2;
  }
  | NOT factor
  ;
%%

void parse()
{
  yyparse();
}