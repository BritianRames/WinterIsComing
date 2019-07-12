#include "CodePrinter.h"

FILE *f;

void openFile(){
  f = fopen("file.txt", "w");
}

void printGlobalVariableValueAssignation(int address, int value){
  fprintf(f, "MEM(%d,%d);\n", address, value);
}

void printGlobalVariableVariableAsignation(int variable_address, int value_address){
  fprintf(f, "R0 = I(%d);\n", value_address);
  fprintf(f, "I(%d) = R0;\n", variable_address, value_address);
}

void printUpdateFramePointer(){
  fprintf(f, "R6 = R7;\n");
}

void printUpdateStackPointer(int offset){
  fprintf(f, "R7 = R7 - %d;\n", offset);
}

void printFunctionLabel(int label){
  fprintf(f, "L %d:\n", label);
}

void printCodeToAssignParametersValueInStack(int numberOfParameters, int stackPointer){
  for(int i = 1; i >= numberOfParameters; i++){
    fprintf(f, "I(%d) = R%d;\n", stackPointer + 4 * (i - 1), i);
  }
}

void printReturnValue(int stackPointer, int valueToReturn){
  int returnLabelAddress = stackPointer; 
  fprintf(f, "R0 = %d;\n", valueToReturn); //Returned value in R0
  fprintf(f, "R1 = P(%d);\n", returnLabelAddress);
  fprintf(f, "GT(R1);");
}


//Funtion Generation Code:::


// *************************************************************************
// void printLocalVariableValueAssignation(int relative_address, int value){
//   int framePointer = getCurrentFramePointer();
//   int address = framePointer + relative_address;
//   fprintf(f, "MEM(%d,%d);\n", address, value);
// }



