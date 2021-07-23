%option noyywrap

%{ 					
#include "global.h"											
#include <stdlib.h> 										
int lineno = 1;
int tokenval = NONE;
%} 
ws 					[ \t]+
nl 					\n
letter      		[a-zA-Z]
digit       		[0-9]
id          		{letter}({letter}|{digit})*
digits				{digit}+
optional_digit  	{digits}(\.{digits})?
optional_exponent	([Ee][+-]?{digits})?
num					{digits}{optional_fraction}{optional_exponent}

%%
{ws}			;											
{nl}			lineno++;
"<"				return LESS;
">"				return GREATER;
"<="			return LESS_OR_EQ;
">="			return GREATER_OR_EQ;
"="				return EQUAL;
"<>"			return NOT_EQUAL;
"program"		return PROGRAM;
"var"			return VAR;
"integer" 		return INTEGER;
"real" 			return REAL;
"/"				return M_DIV;
"*"				return MUL;
"div"			return M_DIV;
"mod"			return MODULO;
"array"			return ARRAY;
"of"			return OF;
"then"			return THEN;
"if"			return IF;
"and"			return AND;
"while"			return WHILE;
"do"			return DO;
"else"			return ELSE;
"begin"			return BEGIN_TOKEN;
"end"			return END_TOKEN;
":="			return ASSIGNOP;
"or" 			return OR;
"write"			return WRITE;
"read"			return READ;
"not"			return NOT;

"-"				{
				return t_MINUS;
				}
"+"				{
				return t_PLUS;
				}
"procedure"		return PROCEDURE;
"function"		return FUNCTION;
{id}		{

				std::string my_string(yytext);
				int my_stringIdx = symtab.lookup(my_string);
				if (my_stringIdx == -1){
					my_stringIdx = symtab.insert(my_string);
				}
				yylval = my_stringIdx;
				return ID;
			}	
{digits}    {
				yylval = symtab.insertNUM(yytext);
                return NUM;
            }
{optional_digit} {
				yylval = symtab.insertReal(yytext);
				return NUM;
				}
													

. {
	return yytext[0];
}															
%%
