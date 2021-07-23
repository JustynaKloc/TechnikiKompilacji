#include "global.h"
#include <iostream>

void gencode(char type, int x1, int x2, int x3){

    string firstVar = ""; 
    string secondVar = "";

    if (symtab.symtable.at(x1).type == SymbolType::ID){
      firstVar = std::to_string(symtab.symtable.at(x1).address);
    }
    else{
      firstVar = "#" + std::to_string(symtab.symtable.at(x1).value);
    }
    if (symtab.symtable.at(x2).type == SymbolType::ID){
      secondVar = std::to_string(symtab.symtable.at(x2).address);
    }
    else{
      secondVar = "#" + std::to_string(symtab.symtable.at(x2).value);
    }

    string thirdVar = std::to_string(symtab.symtable.at(x3).address);


  switch(type){
      case '+':{
          generateMathCode(firstVar, secondVar, thirdVar, "add.i") ;
          break;
          }

      case '-':{
          generateMathCode(firstVar, secondVar, thirdVar, "sub.i") ;
          break;
          }

      case 'x':{
          generateMathCode(firstVar, secondVar, thirdVar, "mul.i") ;
          break;
          }

      case '/':{
          generateMathCode(firstVar, secondVar, thirdVar, "div.i") ;
          break;
      }
      case 'd':{
          generateMathCode(firstVar, secondVar, thirdVar, "div.i") ;
          break;
      }

      case '%': {
          generateMathCode(firstVar, secondVar, thirdVar, "mod.i"); 
          break;
      }

      default:{
          printf("Operacja nieznana\n");
          yylex_destroy();
          exit(1);
          }


  }
}

void generateMathCode(string firstAddress, string secondAddress, string addressVar, string mathOperation){

      myfile << "\t"+ mathOperation+ "\t" + firstAddress + ", " + secondAddress + ", " + addressVar + "\n";

}