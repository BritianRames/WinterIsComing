#include "CodePrinter.h"
#include "../symbol-table/SymbolTableManager.h"

FILE *f;

void openFile(){
  f = fopen("file.q.c", "w");
}

void qInitialization() {
    fprintf(f, "#include \"Q.h\"\n\n");
    fprintf(f, "BEGIN\n");
    fprintf(f, "STAT(0)\n");
    fprintf(f, "MEM(0x11ffc, 0);\n");
    fprintf(f, "CODE(0)\n");
    fprintf(f, "L 0:\n");
    fprintf(f, "R6 = R7\n");
}

void jumpMain(){
    fprintf(f, "\tGT(1);\n");
}

void mainFunction() {
    fprintf(f, "L 1:\n");
}

void goToExit()  {
    fprintf(f, "\tGT(-2);\n");
}

void qEnding() {
    fprintf(f, "END\n");
}


/*******Stack*********/

void moveR7Up(){
  fprintf(f, "R7 = R7 + 4;\n");
}
void moveR7Down(){
  fprintf(f, "R7 = R7 - 4;\n");
}

/********Assignation*********/

void putLocalVariableValueInR0(int offset){
  fprintf(f, "R0 = I(R7 + offset);\n", offset);
}
void putGlobalVariableValueInR0(int address){
  fprintf(f, "R0 = I(%d);\n", address);
}

//void declarationGlobalVariableONLY(){
//  fprintf(f, "R0 = I(%d);\n", address);
//}

void assignValueToGlobalVariable(int address, int value){
  fprintf(f, "I(0x%x) = %d;\n", address, value);
}
void assignValueToLocalVariable(int offset, int value){
  fprintf(f, "I(R7 + offset) = %d;\n", offset, value);
}

void putR0InGlobalVariable(int address){
  fprintf(f, "I(%d) = R0;\n", address);
}
void putR0InLocalVariable(int offset){
  fprintf(f, "I(R7 + %d) = R0;\n", offset);
}

void assignVariableToVariable(int variable_address, int variable_type, int value_address, char value_type){
  if (value_type == "g"){
    putGlobalVariableValueInR0(value_address);
  } else if(value_type = "l"){
    int offset = getLocalVariableOffset(value_address);
    putLocalVariableValueInR0(offset);
  }
  if (variable_type == 'g'){
    putR0InGlobalVariable(variable_address);
  } else if(value_type = 'l'){
    int offset = getLocalVariableOffset(variable_address);
    putR0InLocalVariable(offset);
  }
}

void assignR0ToVariable(int address, int stackPointer, char variable_type) {
  putOperationResultInR0();
  moveR7Up();
  if (variable_type == 'g'){
    fprintf(f, "I(0x%x) = R0;\n", address);  
  } else if (variable_type == 'l'){
    int offset = getLocalVariableOffset(address);
    fprintf(f, "I(R7 - %d) = R0;\n", offset);  
  }
}

int getLocalVariableOffset(int position){
  int numberOfLocalVariables = getLastFunctionFromSymbolTable() -> numberOfLocalVariables; 
  return 4 * (numberOfLocalVariables - position);
}


/*********Operations*********/

void putOperationResultInR0(){
  fprintf(f, "R0 = I(R7);\n");  
}

void saveRegisters(){
  moveR7Down();
  fprintf(f, "I(R7) = R0;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R1;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R2;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R3;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R4;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R5;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R6;\n");
}

void product(){
  fprintf(f, "R1 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R2 = I(R7);\n");
  fprintf(f, "I(R7) = R2 * R1;\n");
  moveR7Up();
}

void add(){
  fprintf(f, "R1 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R2 = I(R7);\n");
  fprintf(f, "I(R7) = R2 + R1;\n");
  moveR7Up();
}

void substract(){
  fprintf(f, "R1 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R2 = I(R7);\n");
  fprintf(f, "I(R7) = R2 - R1;\n");
  moveR7Up();
}

void division(int address){
  fprintf(f, "R1 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R2 = I(R7);\n");
  fprintf(f, "I(R7) = R2 / R1;\n");
  moveR7Up();
}