#include "global.h"


string VarOutput(int x2){
  string firstVar = ""; 

    if(symtab.symtable.at(x2).type == SymbolType::NUM){
      firstVar = "#" + symtab.symtable.at(x2).name;
    }
    else if(symtab.symtable.at(x2).isRef == true && isGlobalScope == false && symtab.symtable.at(x2).type == SymbolType::FUNCTION){
      firstVar = "*BP+"+ std::to_string(symtab.symtable.at(x2).address);
    }
    else if (symtab.symtable.at(x2).type == SymbolType::ID && isGlobalScope == true ){
      firstVar = std::to_string(symtab.symtable.at(x2).address);
    }
    else if(symtab.symtable.at(x2).isRef == false && isGlobalScope == false && symtab.symtable.at(x2).type == SymbolType::ID){
      firstVar = "BP"+ std::to_string(symtab.symtable.at(x2).address);
    }
     else if(symtab.symtable.at(x2).type == SymbolType::FUNCTION || symtab.symtable.at(x2).type == SymbolType::PROCEDURE){
        firstVar = std::to_string(symtab.symtable.at(x2).address);
     } 
     else if (symtab.symtable.at(x2).isRef == true){
      firstVar = "*BP+"+ std::to_string(symtab.symtable.at(x2).address);
     }
    else{
      firstVar = "#" + symtab.symtable.at(x2).name;
    }    
  return firstVar;
}


void gencode(char type, int x1, int x2, int x3){

    string firstVar = ""; 
    string secondVar = "";

    firstVar = VarOutput(x1);
    secondVar = VarOutput(x2);

    string thirdVar = "";
    if(symtab.symtable.at(x3).isRef == true && symtab.symtable.at(x3).isGlobal == false ){
           thirdVar ="*BP+"+ std::to_string(symtab.symtable.at(x3).address);

    }
    else if(isGlobalScope == false ){
          thirdVar ="BP" + std::to_string(symtab.symtable.at(x3).address);
    }
    else{
    thirdVar = std::to_string(symtab.symtable.at(x3).address);
    }
  
    string num_type = "";

    if ( symtab.symtable.at(x1).vartype == VarType::REAL || symtab.symtable.at(x2).vartype == VarType::REAL ){
      num_type = "r";
    }
    else{
      num_type = "i";
    }

  switch(type){
      case '+':{
          generateMathCode(firstVar, secondVar, thirdVar, "add."+num_type);
          break;
          }

      case '-':{
          generateMathCode(firstVar, secondVar, thirdVar, "sub."+num_type);
          break;
          }

      case 'x':{
          generateMathCode(firstVar, secondVar, thirdVar, "mul."+num_type);
          break;
          }

      case '/':{
          generateMathCode(firstVar, secondVar, thirdVar, "div."+num_type);
          break;
      }
      case 'd':{
          generateMathCode(firstVar, secondVar, thirdVar, "div."+num_type);
          break;
      }

      case '%': {
          generateMathCode(firstVar, secondVar, thirdVar, "mod."+num_type); 
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

void needToTypeChange(int &x1, int &x2){

    string firstVar = ""; 
    string secondVar = "";
    firstVar = VarOutput(x1);
    secondVar = VarOutput(x2);

  
    if ( (symtab.symtable.at(x1).vartype == VarType::REAL && symtab.symtable.at(x2).vartype == VarType::INTEGER && isGlobalScope == true)) {
        int new_temp = symtab.insertTempGlobal(symtab.symtable.at(x1).vartype);
        myfile << "\tinttoreal.i\t" + secondVar + ", " + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        x2 = new_temp;

    }
    else if ( (symtab.symtable.at(x1).vartype == VarType::INTEGER && symtab.symtable.at(x2).vartype == VarType::REAL && isGlobalScope == true)) {
        int new_temp = symtab.insertTempGlobal(symtab.symtable.at(x2).vartype);
        myfile << "\tinttoreal.i\t" + firstVar + ", " + std::to_string(symtab.symtable.at(new_temp).address)  +"\n";
        x1 = new_temp;

    }
    else if ( symtab.symtable.at(x1).vartype == VarType::REAL && symtab.symtable.at(x2).vartype == VarType::INTEGER && isGlobalScope == false) {
        int new_temp = symtab.insertTempLocal(symtab.symtable.at(x1).vartype);
        myfile << "\tinttoreal.i\t" + secondVar + ", BP" + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        x2 = new_temp;

    }
    else if ( symtab.symtable.at(x1).vartype == VarType::INTEGER && symtab.symtable.at(x2).vartype == VarType::REAL && isGlobalScope ==false) {
        int new_temp = symtab.insertTempLocal(symtab.symtable.at(x2).vartype);
        myfile << "\tinttoreal.i\t" + firstVar + ", BP"+ std::to_string(symtab.symtable.at(new_temp).address)  +"\n";
        x1 = new_temp;

    } 

    }


void changeTypeBeforeMove(int &x1, int &x3){

    string firstVar = "";
      if (symtab.symtable.at(x3).type == SymbolType::ID){
        firstVar = std::to_string(symtab.symtable.at(x3).address);
      }
        else{
      firstVar = "#" + symtab.symtable.at(x3).name;
      }

      if(( symtab.symtable.at(x1).vartype == VarType::REAL && symtab.symtable.at(x3).vartype == VarType::INTEGER && isGlobalScope == true)){
          int new_temp = symtab.insertTempGlobal(symtab.symtable.at(x1).vartype);
          myfile << "\tinttoreal.i\t"+ firstVar + ", " + std::to_string(symtab.symtable.at(new_temp).address) + "\n";
          x3 = new_temp;
      } 
      else if (symtab.symtable.at(x1).vartype == VarType::REAL && symtab.symtable.at(x3).vartype == VarType::INTEGER && isGlobalScope == false){
        int new_temp = symtab.insertTempLocal(symtab.symtable.at(x1).vartype);
        myfile << "\tinttoreal.i\t BP"+ firstVar + ", BP" + std::to_string(symtab.symtable.at(new_temp).address) + "\n";
        x3 = new_temp;
      }
    
      else if ((symtab.symtable.at(x1).vartype == VarType::INTEGER && symtab.symtable.at(x3).vartype == VarType::REAL && isGlobalScope == true)){
        int new_temp = symtab.insertTempGlobal(symtab.symtable.at(x1).vartype);
        myfile << "\trealtoint.r\t"+ firstVar + ", " + std::to_string(symtab.symtable.at(new_temp).address) + "\n";
      
        x3 = new_temp;  
    }

      else if ((symtab.symtable.at(x1).vartype == VarType::INTEGER && symtab.symtable.at(x3).vartype == VarType::REAL && isGlobalScope == false)){
        int new_temp = symtab.insertTempLocal(symtab.symtable.at(x1).vartype);
        myfile << "\trealtoint.r\t BP"+ firstVar + ", BP" + std::to_string(symtab.symtable.at(new_temp).address) + "\n";
      
        x3 = new_temp;  
    }
}

void forMove(int x1, int x2){

 string firstVar = "";
  string secondVar = "";


  firstVar = VarOutput(x2);
  secondVar = VarOutput(x1);
  
    string num_type = "";

    if (symtab.symtable.at(x1).vartype == VarType::REAL || symtab.symtable.at(x2).vartype == VarType::REAL){
      num_type = "r";
    }
    else{
      num_type = "i";
    }

    myfile << "\tmov." +num_type +"\t"+ firstVar + ", " + secondVar + "\n";

}

void generate_relop(char command, int x1, int x2, int label) {
    string num_type = "";
    if (symtab.symtable.at(x1).vartype == VarType::REAL){
      num_type = "r";
    }
    else{
      num_type = "i";
    }
    string firstVar = "";
    firstVar = VarOutput(x2);
    string secondVar = "";
    secondVar = VarOutput(x1);

  switch (command)
  {
    case  '=': {
      myfile <<  "\tje." + num_type +"\t" + secondVar + ',' + firstVar  + ",#" + symtab.symtable.at(label).name +"\n";
      break;}
      case '>':  {
      myfile <<  "\tjg." + num_type +"\t" + secondVar + ',' + firstVar  + ",#" + symtab.symtable.at(label).name +"\n";
      break;
      }
      case '<': {
      myfile <<  "\tjl." + num_type + "\t" + secondVar + ',' + firstVar  + ",#" + symtab.symtable.at(label).name +"\n";
      break;
      }
      case 'g':{
      myfile <<  "\tjge." + num_type + "\t" + secondVar + ',' + firstVar  + ",#" + symtab.symtable.at(label).name +"\n";
      break;
      }
      case 'l':{
      myfile <<  "\tjle." + num_type + "\t" + secondVar + ',' + firstVar  + ",#" + symtab.symtable.at(label).name +"\n";
      break;
      }
      case '!':{
      myfile <<  "\tjne." + num_type + "\t" + secondVar + ',' + firstVar  + ",#" + symtab.symtable.at(label).name +"\n";
      break;
      }
    
      default:{
      printf("Operacja nieznana\n");
      yylex_destroy();
      exit(1);
      }
  }
}

void updateEnter(int v1){

    std::string s = myfile.str();
    std::string regex = "enter.i ####";
    s.replace(s.find(regex), regex.length(), "enter.i #" + std::to_string(v1));
    myfile.str("");
    myfile << s;

}