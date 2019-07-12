#include "CodePrinter.h"

FILE *f;

void openFile(){
  f = fopen("file.txt", "w");
}

void printGlobalVariableValueAssignation(int address, int value){
  fprintf(f, "I(%d) = %d; // guardamos %d en %d\n", address, value, value, address);
}

void printGlobalVariableVariableAsignation(int variable_address, int value_address){
  fprintf(f, "R0 = I(%d);\n", value_address);
  fprintf(f, "I(%d) = R0;\n", variable_address);
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
  for(int i = 1; i <= numberOfParameters; i++){
    fprintf(f, "I(%d) = R%d;\n", stackPointer + 4 * (i - 1), i);
  }
}

void printReturnValue(int stackPointer, int valueToReturn){
  int returnLabelAddress = stackPointer; 
  fprintf(f, "R0 = %d;\n", valueToReturn); //Returned value in R0
  fprintf(f, "R1 = I(%d);\n", returnLabelAddress);
  fprintf(f, "GT(R1);");
}

void printReturnVariable(int stackPointer, int variableAddress){
  int returnLabelAddress = stackPointer; 
  fprintf(f, "R0 = I(%d);\n", variableAddress); //Returned value in R0
  fprintf(f, "R1 = I(%d);\n", returnLabelAddress);
  fprintf(f, "GT(R1);");
}

void printRecoverRegistersValue(int registerFramePointer){
  for(int i = 0; i <= 7; i--){
    fprintf(f, "R%d = I(%d);\n", i, registerFramePointer + ((i - 1) * 4));
  }
}

void printSaveRegistersValue(int registerFramePointer){
  for(int i = 0; i <= 7; i--){
    fprintf(f, "I(%d) = R%d;\n", registerFramePointer + ((i - 1) * 4), i);
  }
}

void printCodeToAssignValueToVariable(int address, int value){
  fprintf(f, "I(%d) = %d;\n", address, value); //Returned value in R0
}

void printCodeToAssignVariableToVariable(int address, int value_address){
  fprintf(f, "R1 = I(%d);\n", value_address); //Returned value in R0
  fprintf(f, "I(%d) = R1;\n", address); //Returned value in R0
}


//Funtion Generation Code:::


// *************************************************************************
// void printLocalVariableValueAssignation(int relative_address, int value){
//   int framePointer = getCurrentFramePointer();
//   int address = framePointer + relative_address;
//   fprintf(f, "MEM(%d,%d);\n", address, value);
// }



