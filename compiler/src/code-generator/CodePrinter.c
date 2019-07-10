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

//Funtion Generation Code:::


// *************************************************************************
// void printLocalVariableValueAssignation(int relative_address, int value){
//   int framePointer = getCurrentFramePointer();
//   int address = framePointer + relative_address;
//   fprintf(f, "MEM(%d,%d);\n", address, value);
// }



