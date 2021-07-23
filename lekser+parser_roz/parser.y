%{
  #include "global.h"
  #include <iostream>
  extern Symtable symtab;
  
  extern int yylex();

  void yyerror (char const *s)
  {
    error((char *)s);
  }
  void yywarning (const char *m) 
  {
    fprintf (stderr, "warning w linii: %d:%s\n", lineno, m);
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

%token EQUAL
%token NOT_EQUAL
%token LESS
%token LESS_OR_EQ
%token GREATER
%token GREATER_OR_EQ

%token t_PLUS
%token t_MINUS
%token AND
%token NOT
%token NONE

%start program
%%

program:
  PROGRAM ID '(' identifier_list {symtab.IDlist.clear();} ')' ';' {
        myfile << "\tjump.i #" +symtab.symtable.at($2).name + " \n";
  }
  declarations{
    isGlobalScope = false;
  }
  subprogram_declarations{
 myfile << symtab.symtable.at($2).name + ": \n";
 isGlobalScope = true;
  }
  compound_statement 
  '.'{
    myfile << "\texit";
  }
  ;

identifier_list:
  ID{
    symtab.IDlist.push_back($1);
  }
  | identifier_list ',' ID{
    symtab.IDlist.push_back($3);

  }
  ;

declarations:       
  declarations VAR identifier_list ':' type ';'{
    symtab.IDrecogized($5);
    symtab.IDlist.clear();
  }
  | %empty
  ;

type:               
  standard_type
  | ARRAY '[' NUM '.' '.' NUM ']' OF standard_type
  ;

standard_type:
  INTEGER{
    $$ = INTEGER;
  }
  | REAL{
    $$ = REAL;
  }

  ;

subprogram_declarations:
  subprogram_declarations subprogram_declaration ';'
  | %empty
  ;

subprogram_declaration:
  subprogram_head declarations compound_statement
  {
    //end of function or procedure
    myfile << "\tleave\n";
    myfile << "\treturn\n";
    updateEnter((-1)*symtab.negative_current_address);
    symtab.negative_current_address = 0; 
  }
  ;

subprogram_head:
  FUNCTION ID arguments ':' standard_type ';'{
    if ($5 == INTEGER) {
            symtab.symtable.at($2).vartype = VarType::INTEGER;
        } else {
            symtab.symtable.at($2).vartype = VarType::REAL;
        }
    symtab.symtable.at($2).type = SymbolType::FUNCTION;
    symtab.symtable.at($2).isRef = true;
    myfile << symtab.symtable.at($2).name + ": \n";
    myfile << "\tenter.i ####  \n";
    int max_param_address = symtab.parameters.size()*4 +8 ;
    for( int i =0; i < symtab.parameters.size();i++){
        symtab.symtable.at($2).function_types.push_back(symtab.symtable.at(symtab.parameters.at(i)).vartype);
        symtab.symtable.at(symtab.parameters.at(i)).isRef = true;
        symtab.symtable.at(symtab.parameters.at(i)).address = max_param_address;
        max_param_address -= 4;
    }
    symtab.parameters.clear();
    symtab.symtable.at($2).isRef = true;
    symtab.symtable.at($2).address = 8;
  }
  | PROCEDURE ID arguments ';'{
    symtab.symtable.at($2).type = SymbolType::PROCEDURE;
    myfile << symtab.symtable.at($2).name + ": \n";
    int max_param_address = symtab.parameters.size()*4 +4;
    
    myfile << "\tenter.i ####  \n";
    for( int i =0; i < symtab.parameters.size();i++){
        symtab.symtable.at($2).function_types.push_back(symtab.symtable.at(symtab.parameters.at(i)).vartype);
        symtab.symtable.at(symtab.parameters.at(i)).isRef = true;
        symtab.symtable.at(symtab.parameters.at(i)).address = max_param_address;
        max_param_address -= 4;
    }
    symtab.parameters.clear();
    symtab.symtable.at($2).isRef = true;

  }
  ;

arguments:
  '(' parameter_list ')'
  | %empty
  ;

parameter_list:     
  identifier_list ':' type{
    symtab.IDrecogizedWOAdress($3);
    for( int i = 0; i < symtab.IDlist.size() ;i++){
      symtab.parameters.push_back(symtab.IDlist.at(i));
    }
    symtab.IDlist.clear();
  }
  | parameter_list ',' identifier_list ':' type
  {
    symtab.IDrecogizedWOAdress($5);
    for( int i = 0; i < symtab.IDlist.size() ;i++){
      symtab.parameters.push_back(symtab.IDlist.at(i));
    }
    symtab.IDlist.clear();
  }
  | parameter_list ';' identifier_list ':' type{
    symtab.IDrecogizedWOAdress($5);
    for( int i = 0; i < symtab.IDlist.size() ;i++){
      symtab.parameters.push_back(symtab.IDlist.at(i));
    }
    symtab.IDlist.clear();
  }
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
    changeTypeBeforeMove($1, $3);
    forMove($1, $3);
  }
  | procedure_statement

  | compound_statement 
  | IF expression {
    int new_label = symtab.insertLabel();
    myfile << "\tje.i\t" + VarOutput($2) + ",#0,#" + symtab.symtable.at(new_label).name + "\n";

    $$ = new_label;

   } THEN statement {
    int new_label1 = symtab.insertLabel();
    myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";
    myfile << symtab.symtable.at($3).name + ":\n";

    $$ = new_label1;

   } ELSE statement {
    myfile << symtab.symtable.at($6).name + ":\n";
   }

  | WHILE {
    int new_label1 = symtab.insertLabel();
    myfile << symtab.symtable.at(new_label1).name + ":\n";

    $$ = new_label1;
  } expression DO {
    int new_label2 = symtab.insertLabel();

    myfile << "\tje.i\t" + VarOutput($3) + ",#0,#" + symtab.symtable.at(new_label2).name + "\n";
    $$ = new_label2;

  } statement {
    myfile << "\tjump.i\t#" + symtab.symtable.at($2).name + "\n";
    myfile << symtab.symtable.at($5).name + ":\n";
  }

  | WRITE '(' {
    symtab.Stack.push(symtab.expressions);
    symtab.expressions.clear();}
    expression_list ')' {
    for(int i=0; i < symtab.expressions.size();i++){
      if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::REAL){
        myfile << "\twrite.r\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "\n";}
      else{
        myfile << "\twrite.i\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "\n";
      }
    }
    symtab.expressions = symtab.Stack.top();
    symtab.Stack.pop();
  }
  | READ '('{
    symtab.Stack.push(symtab.expressions);
    symtab.expressions.clear();
  } expression_list ')'{
    for(int i=0; i < symtab.expressions.size();i++){
      if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::REAL){
        myfile << "\tread.r\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "\n";}
      else{
        myfile << "\tread.i\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "\n";
      }
    }
    symtab.expressions = symtab.Stack.top();
    symtab.Stack.pop();
      }
  ;

variable:
  ID
  | ID '[' expression ']'
  ;

procedure_statement:
  ID  {
    myfile << "\tcall.i\t #" +symtab.symtable.at($1).name + "\n"; 
  }
  | ID '(' {
    symtab.Stack.push(symtab.expressions);
    symtab.expressions.clear();
  }expression_list ')'{
    for(int i = 0; i < symtab.expressions.size(); i++){
       //printf("%s \n", symtab.symtable.at(symtab.expressions.at(i)).name.c_str());
      if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::INTEGER && symtab.symtable.at($1).function_types.at(i) == VarType::REAL){
        //inttoreal
        int new_temp = symtab.insertTempGlobal(VarType::REAL);
        if ( symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM ){
          myfile << "\tinttoreal.i\t#" + symtab.symtable.at(symtab.expressions.at(i)).name + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        else{
          myfile << "\tinttoreal.i\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        symtab.expressions.at(i) = new_temp;
      }  
      else if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::REAL && symtab.symtable.at($1).function_types.at(i) == VarType::INTEGER){
        //realtoint
        int new_temp = symtab.insertTempGlobal(VarType::INTEGER);
        if (symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM){
          myfile << "\trealtoint.r\t#" + symtab.symtable.at(symtab.expressions.at(i)).name + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        else{
          myfile << "\trealtoint.r\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        symtab.expressions.at(i) = new_temp;
      }
      if (symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM){
        if (isGlobalScope == true){
          int newTempVar = symtab.insertTempGlobal(symtab.symtable.at(symtab.expressions.at(i)).vartype);
          forMove( newTempVar, symtab.expressions.at(i));
          symtab.expressions.at(i) = newTempVar;
        }
        else{
          int newTempVar = symtab.insertTempLocal(symtab.symtable.at(symtab.expressions.at(i)).vartype);
          forMove(newTempVar, symtab.expressions.at(i));
          symtab.expressions.at(i) = newTempVar;
        }
      }
      string var = VarOutput(symtab.expressions.at(i));
      if (symtab.symtable.at(symtab.expressions.at(i)).isRef == true && isGlobalScope == false){
        var.erase(0,1);
        myfile << "\tpush.i\t " + var + "\n"; 
      }
      else{
        myfile << "\tpush.i\t #" + var + "\n"; 
      }
    }
    myfile << "\tcall.i\t #" + symtab.symtable.at($1).name + "\n"; 

    myfile << "\tincsp.i\t #" + std::to_string(symtab.expressions.size()*4) + "\n";

    symtab.expressions = symtab.Stack.top();
    symtab.Stack.pop();
  }
  
  ;

expression_list:
  expression 
  {
    symtab.expressions.push_back($1);
  }
  | expression_list ',' expression {
    symtab.expressions.push_back($3);
  }
  ;

expression:
  simple_expression
  | simple_expression EQUAL simple_expression{
      int new_label = symtab.insertLabel();
      generate_relop('=', $1, $3, new_label);
      int new_temp = 0;
      if (isGlobalScope == true){
         new_temp = symtab.insertTempGlobal(VarType::INTEGER);}
      else {
         new_temp = symtab.insertTempLocal(VarType::INTEGER);}
      int new_label1 = symtab.insertLabel();

      myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
      myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

      myfile << symtab.symtable.at(new_label).name +":"+ "\n";
      myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
      myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
      
      $$ = new_temp;
  }
  | simple_expression NOT_EQUAL simple_expression{
      int new_label = symtab.insertLabel();
      generate_relop('!', $1, $3, new_label);
      int new_temp = 0;

      if (isGlobalScope == true){
         new_temp = symtab.insertTempGlobal(VarType::INTEGER);}
      else {
         new_temp = symtab.insertTempLocal(VarType::INTEGER);}
      
      int new_label1 = symtab.insertLabel();

      myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
      myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

      myfile << symtab.symtable.at(new_label).name +":"+ "\n";
      myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
      myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
      
      $$ = new_temp;
  }
  | simple_expression LESS simple_expression{
      int new_label = symtab.insertLabel();
      generate_relop('<', $1, $3, new_label);  
      int new_temp = 0; 
      if (isGlobalScope == true){
         new_temp = symtab.insertTempGlobal(VarType::INTEGER);}
      else {
         new_temp = symtab.insertTempLocal(VarType::INTEGER);}

      int new_label1 = symtab.insertLabel();

      myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
      myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

      myfile << symtab.symtable.at(new_label).name +":"+ "\n";
      myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
      myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
      
      $$ = new_temp;
  }
  | simple_expression LESS_OR_EQ simple_expression{
      int new_label = symtab.insertLabel();
      generate_relop('l', $1, $3, new_label);
      int new_temp = 0;

      if (isGlobalScope == true){
         new_temp = symtab.insertTempGlobal(VarType::INTEGER);
      }
      else {
         new_temp = symtab.insertTempLocal(VarType::INTEGER);}

      int new_label1 = symtab.insertLabel();

      myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
      myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

      myfile << symtab.symtable.at(new_label).name +":"+ "\n";
      myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
      myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
      
      $$ = new_temp;
  }
  | simple_expression GREATER simple_expression{
      int new_label = symtab.insertLabel();
      generate_relop('>', $1, $3, new_label);
      int new_temp = 0;
      if (isGlobalScope == true){
        new_temp = symtab.insertTempGlobal(VarType::INTEGER);
      }
      else {
        new_temp = symtab.insertTempLocal(VarType::INTEGER);}

      int new_label1 = symtab.insertLabel();

      myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
      myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

      myfile << symtab.symtable.at(new_label).name +":"+ "\n";
      myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
      myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
      
      $$ = new_temp;
  }
  | simple_expression GREATER_OR_EQ simple_expression{
      int new_label = symtab.insertLabel();
      generate_relop('g', $1, $3, new_label);
      int new_temp = 0;
      if (isGlobalScope == true){
         new_temp = symtab.insertTempGlobal(VarType::INTEGER);}
      else {
        new_temp = symtab.insertTempLocal(VarType::INTEGER);}
        int new_label1 = symtab.insertLabel();

        myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
        myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

        myfile << symtab.symtable.at(new_label).name +":"+ "\n";
        myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
        myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
        
        $$ = new_temp;    
  }
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
    int temp_pos = symtab.insertTempGlobal(symtab.symtable.at($2).vartype);
    gencode('-', temp_num_pos, $2, temp_pos);
    $$ = temp_pos;
  }
  | simple_expression t_PLUS term
  {
    needToTypeChange($1, $3);
    if (isGlobalScope == true){
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at($1).vartype);
      gencode('+', $1, $3, temp_variable_pos);
      $$ = temp_variable_pos;}
    else{
      int temp_variable_pos = symtab.insertTempLocal(symtab.symtable.at($1).vartype);
      gencode('+', $1, $3, temp_variable_pos);
      $$ = temp_variable_pos;
    }
  }
  | simple_expression t_MINUS term
    {
    needToTypeChange($1, $3);
    if (isGlobalScope == true){
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at($1).vartype);
      gencode('-', $1, $3, temp_variable_pos);
      $$ = temp_variable_pos;   }
    else{
      int temp_variable_pos = symtab.insertTempLocal(symtab.symtable.at($1).vartype);
      gencode('+', $1, $3, temp_variable_pos);
      $$ = temp_variable_pos;      
    }
  }
  | simple_expression OR term {
    if (isGlobalScope == true){
      int new_temp = symtab.insertTempGlobal(symtab.symtable.at($1).vartype);
      myfile << "\tor.i\t" + std::to_string(symtab.symtable.at($1).address) + "," + std::to_string(symtab.symtable.at($3).address)+ ","  + std::to_string(symtab.symtable.at(new_temp).address)  + "\n";
      $$ = new_temp;}
    else{
      int new_temp = symtab.insertTempLocal(symtab.symtable.at($1).vartype);
      myfile << "\tor.i\t" + std::to_string(symtab.symtable.at($1).address)+ "," + std::to_string(symtab.symtable.at($3).address)  +"," +std::to_string(symtab.symtable.at(new_temp).address)  + "\n";
      $$ = new_temp;
    }
  }
  | simple_expression AND term{
    if (isGlobalScope == true){
      int new_temp = symtab.insertTempGlobal(symtab.symtable.at($1).vartype);
      myfile << "\tand.i\t" + std::to_string(symtab.symtable.at($1).address) + "," + std::to_string(symtab.symtable.at($3).address)+ ","  + std::to_string(symtab.symtable.at(new_temp).address)  + "\n";
      $$ = new_temp;}
    else{
      int new_temp = symtab.insertTempLocal(symtab.symtable.at($1).vartype);
      myfile << "\tand.i\t" + std::to_string(symtab.symtable.at($1).address) +"," +std::to_string(symtab.symtable.at($3).address)+ ","  + std::to_string(symtab.symtable.at(new_temp).address)  + "\n";
      $$ = new_temp;
    }
  }
  ;
        
term:
  factor
  | term MODULO factor{
    needToTypeChange($1, $3);
    if(isGlobalScope == true){
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at($1).vartype);
      gencode('%', $1, $3, temp_variable_pos);
      $$ = temp_variable_pos;
   }
    else{
      int temp_variable_pos = symtab.insertTempLocal(symtab.symtable.at($1).vartype);
      gencode('%', $1, $3, temp_variable_pos);
      $$ = temp_variable_pos;      
    }
  }
  | term MUL factor
  {
    needToTypeChange($1, $3);
    if(isGlobalScope == true){
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at($1).vartype);
      gencode('x', $1, $3, temp_variable_pos);
      $$ = temp_variable_pos;
    }
    else{
      int temp_variable_pos = symtab.insertTempLocal(symtab.symtable.at($1).vartype);
      gencode('+', $1, $3, temp_variable_pos);
      $$ = temp_variable_pos;   
    }
    }
  | term M_DIV factor
  {
    needToTypeChange($1, $3);
    if(isGlobalScope == true){
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at($1).vartype);
      gencode('/', $1, $3, temp_variable_pos);
      $$ = temp_variable_pos;}
    else{
      int temp_variable_pos = symtab.insertTempLocal(symtab.symtable.at($1).vartype);
      gencode('+', $1, $3, temp_variable_pos);
      $$ = temp_variable_pos;   
    }
}
  ;

factor:
  variable
  {
    //funkcja bez parametru lub zmienna
    if (symtab.symtable.at($1).type == SymbolType::FUNCTION ){
      if(symtab.symtable.at($1).function_types.size()> 0)
					{
						yyerror("Wywołanie funkcji przyjmującej parametry bez parametrów");
						YYERROR;
					}
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at($1).vartype);
      myfile << "\tpush.i #" + std::to_string(symtab.symtable.at(temp_variable_pos).address) + "\n";
      myfile << "\tcall.i #" + symtab.symtable.at($1).name + "\n";
      myfile << "\tincsp.i #4\n";
      symtab.symtable.at($1).address = symtab.symtable.at(temp_variable_pos).address;

    }
  }
  | ID '(' {
    symtab.Stack.push(symtab.expressions);
    symtab.expressions.clear();
    }
    expression_list ')'{
        for(int i = 0; i < symtab.expressions.size(); i++){
      if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::INTEGER && symtab.symtable.at($1).function_types.at(i) == VarType::REAL){
        //inttoreal
        int new_temp = symtab.insertTempGlobal(VarType::REAL);
        if ( symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM ){
          myfile << "\tinttoreal.i\t#" + symtab.symtable.at(symtab.expressions.at(i)).name + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        else{
          myfile << "\tinttoreal.i\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        symtab.expressions.at(i) = new_temp;
      }  
      else if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::REAL && symtab.symtable.at($1).function_types.at(i) == VarType::INTEGER){
        //realtoint
        int new_temp = symtab.insertTempGlobal(VarType::INTEGER);
        if (symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM){
          myfile << "\trealtoint.r\t#" + symtab.symtable.at(symtab.expressions.at(i)).name + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        else{
          myfile << "\trealtoint.r\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        symtab.expressions.at(i) = new_temp;
      }
      if (symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM){
        if (isGlobalScope == true){
          int newTempVar = symtab.insertTempGlobal(symtab.symtable.at(symtab.expressions.at(i)).vartype);
          forMove( newTempVar, symtab.expressions.at(i));
          symtab.expressions.at(i) = newTempVar;
        }
        else{
          int newTempVar = symtab.insertTempLocal(symtab.symtable.at(symtab.expressions.at(i)).vartype);
          forMove(newTempVar, symtab.expressions.at(i));
          symtab.expressions.at(i) = newTempVar;
        }
      }
      string var = VarOutput(symtab.expressions.at(i));
      if (symtab.symtable.at(symtab.expressions.at(i)).isRef == true && isGlobalScope == false) {
        var.erase(0,1);
        myfile << "\tpush.i\t " + var + "\n"; 
      }
      else {
        myfile << "\tpush.i\t #" + var + "\n"; 
      }
      }
      //jesli jest funkcją to potrzebuje adres na wynik
        if (isGlobalScope == true){
          int additional_temp = symtab.insertTempGlobal(symtab.symtable.at($1).vartype); 
          $$ = additional_temp;
        }
        else{
          int additional_temp = symtab.insertTempLocal(symtab.symtable.at($1).vartype); 
          $$ = additional_temp;
        } 
      string var = VarOutput($$);
      if (symtab.symtable.at($$).isRef == true && isGlobalScope == false){
        myfile << "\tpush.i\t " + var + "\n"; 
      }
      else{
        myfile << "\tpush.i\t #" + var + "\n"; }

    myfile << "\tcall.i\t #" + symtab.symtable.at($1).name + "\n"; 
    myfile << "\tincsp.i\t #" + std::to_string(symtab.expressions.size()*4 +4) + "\n";

    symtab.expressions = symtab.Stack.top();
    symtab.Stack.pop();
  }
  
  | NUM
  | '(' expression ')'{
    $$ = $2;
  }
  | NOT factor {
    int new_label = symtab.insertLabel();
    string var = VarOutput($2);

    string num_type = "";
    if (symtab.symtable.at($2).vartype == VarType::REAL){
      num_type = "r";
    }
    else{
      num_type = "i";
    }
    myfile << "\tje." + num_type + "\t" + var + ",#0,#" + symtab.symtable.at(new_label).name + "\n";

    int temp_variable_pos = 0;
    if (isGlobalScope == true) {
      temp_variable_pos = symtab.insertTempGlobal(VarType::INTEGER);
    } else {
      temp_variable_pos = symtab.insertTempLocal(VarType::INTEGER);
    }
    $$ = temp_variable_pos;

    myfile << "\tmov.i\t#0," + VarOutput(temp_variable_pos) + "\n";

    int new_label2 = symtab.insertLabel();

    myfile << "\tjump.i\t#" + symtab.symtable.at(new_label2).name + "\n";
    myfile << symtab.symtable.at(new_label).name + ":\n";
    myfile << "\tmov.i\t#1," + VarOutput(temp_variable_pos) + "\n";
    myfile << symtab.symtable.at(new_label2).name + ":\n";
  }
  ;
%%

void parse()
{
  yyparse();
}