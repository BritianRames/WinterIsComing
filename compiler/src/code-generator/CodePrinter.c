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

void printHeaderOfIfInstruction(int reg, int cond_value, int else_label){
  fprintf(f, "\tR%d = %d;\n", reg, cond_value);
  fprintf(f, "\tIF(!R%d) GT(%d);\n", cond_value, label);
}

void printMiddleOfIfInstruction(int exit_label, int else_label){
  fprintf(f, "\tGT(%d);\n", exit_label);
  fprintf(f, "L %d:\n", else_label);
}

void printEndOfIfInstruction(int exit_label){
  fprintf(f, "L %d:\n", exit_label);
}  

void printHeaderOfWhileInstruction(int begin_label, int reg, int cond_value, int exit_label){
  fprintf(f, "L %d:\n", begin_label);
  fprintf(f, "\tR%d = %d;\n", reg, cond_value);
  fprintf(f, "\tIF(!R%d) GT(%d);\n", reg, exit_label);
}

void printEndOfWhileInstruction(int begin_label, int exit_label){
  fprintf(f, "\tGT(%d);\n", begin_label);
  fprintf(f, "L %d:\n", exit_label);
}

void printArrayAccessIntVal(int reg, int i, unsigned int array_address){
  //TODO
  fprintf(f, "\tR%d = %d;\n", reg, i);
  fprintf(f, "\tR%d = R%d + 4\n", reg, reg);
  fprintf(f, "\tR%d = R%d + %d\n", reg, reg, array_address);
}

void printArrayAccessIntVal(int reg, int i_address, unsigned int array_address){
  //TODO
  fprintf(f, "\tR%d = I(%d);\n", reg, i_address);
  fprintf(f, "\tR%d = R%d + 4\n", reg, reg);
  fprintf(f, "\tR%d = R%d + %d\n", reg, reg, array_address);
}

void printArrayInit(unsigned int array_address, int length){
  //TODO
  fprintf(f, "\tFIL(%d,%d,0);\n", array_address, length * 4);
}

void printSum(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
  	fprintf(f, "\tR%d = R%d + R%d;\n", reg_1, reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d + R%d;\n", reg_1, data_1, reg_1);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = R%d + %d;\n", reg_1, reg_1, data_2);
  } else {
	fprintf(f, "\tR%d = %d + %d", reg_1, data_1, data_2);
  }
}

void printSubstract(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
  	fprintf(f, "\tR%d = R%d - R%d;\n", reg_1, reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d - R%d;\n", reg_1, data_1, reg_1);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = R%d - %d;\n", reg_1, reg_1, data_2);
  } else {
	fprintf(f, "\tR%d = %d - %d", reg_1, data_1, data_2);
  }
}

void printProduct(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
  	fprintf(f, "\tR%d = R%d * R%d;\n", reg_1, reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d * R%d;\n", reg_1, data_1, reg_1);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = R%d * %d;\n", reg_1, reg_1, data_2);
  } else {
	fprintf(f, "\tR%d = %d * %d", reg_1, data_1, data_2);
  }
}

void printDivide(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
  	fprintf(f, "\tR%d = R%d / R%d;\n", reg_1, reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d / R%d;\n", reg_1, data_1, reg_1);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = R%d / %d;\n", reg_1, reg_1, data_2);
  } else {
	fprintf(f, "\tR%d = %d / %d", reg_1, data_1, data_2);
  }
}

void printLess(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
  	fprintf(f, "\tR%d = R%d < R%d;\n", reg_1, reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d < R%d;\n", reg_1, data_1, reg_1);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = R%d < %d;\n", reg_1, reg_1, data_2);
  } else {
	fprintf(f, "\tR%d = %d < %d", reg_1, data_1, data_2);
  }
}

void printGreater(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
  	fprintf(f, "\tR%d = R%d > R%d;\n", reg_1, reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d > R%d;\n", data_1, reg_1);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, reg_1, data_1);
	fprintf(f, "\tR%d = R%d > %d;\n", reg_1, reg_1, data_2);
  } else {
	fprintf(f, "\tR%d = %d > %d", reg_1, data_1, data_2);
  }
}

void printEquals(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
  	fprintf(f, "\tR%d = R%d == R%d;\n", reg_1, reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d == R%d;\n", reg_1, data_1, reg_1);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = R%d == %d;\n", reg_1, reg_1, data_2);
  } else {
	fprintf(f, "\tR%d = %d == %d", reg_1, data_1, data_2);
  }
}

void printLessEquals(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
  	fprintf(f, "\tR%d = R%d <= R%d;\n", reg_1, reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d <= R%d;\n", reg_1, data_1, reg_1);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = R%d <= %d;\n", reg_1, reg_1, data_2);
  } else {
	fprintf(f, "\tR%d = %d <= %d", reg_1, data_1, data_2);
  }
}

void printGreaterEquals(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
  	fprintf(f, "\tR%d = R%d >= R%d;\n", reg_1, reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d >= R%d;\n", reg_1, data_1, reg_1);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = R%d >= %d;\n", reg_1, reg_1, data_2);
  } else {
	fprintf(f, "\tR%d = %d >= %d", reg_1, data_1, data_2);
  }
}

void printNotEquals(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
  	fprintf(f, "\tR%d = R%d != R%d;\n", reg_1, reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d != R%d;\n", reg_1, data_1, reg_1);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = R%d != %d;\n", reg_1, reg_1, data_2);
  } else {
	fprintf(f, "\tR%d = %d != %d", reg_1, data_1, data_2);
  }
}

void printAnd(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
	fprintf(f, "\tR%d = R%d * R%d;\n", reg_2, reg_1, reg_2);
  	fprintf(f, "\tR%d = R%d != 0;\n", reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d * R%d;\n", reg_2, data_1, reg_2);
	fprintf(f, "\tR%d = R%d != 0;\n", reg_1, reg_2);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = R%d * %d;\n", reg_2, reg_1, data_2);
	fprintf(f, "\tR%d = R%d != 0;\n", reg_1, reg_2);
  } else {
	fprintf(f, "\tR%d = %d * %d", reg_1, data_1, data_2);
	fprintf(f, "\tR%d = R%d != 0;\n", reg_1, reg_1);
  }
}

void printOr(int reg_1, int reg_2, int data_1, bool is_id_1, int data_2, bool is_id_2) {
  //TODO
  if (is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = I(%d);\n", reg_2, data_2);
	fprintf(f, "\tR%d = R%d + R%d;\n", reg_2, reg_1, reg_2);
  	fprintf(f, "\tR%d = R%d >= 1;\n", reg_1, reg_2);
  } else if (!is_id_1 && is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_2);
	fprintf(f, "\tR%d = %d + R%d;\n", reg_2, data_1, reg_2);
	fprintf(f, "\tR%d = R%d >= 1;\n", reg_1, reg_2);
  } else if (is_id_1 && !is_id_2) {
	fprintf(f, "\tR%d = I(%d);\n", reg_1, data_1);
	fprintf(f, "\tR%d = R%d + %d;\n", reg_2, reg_1, data_2);
	fprintf(f, "\tR%d = R%d >= 1;\n", reg_1, reg_2);
  } else {
	fprintf(f, "\tR%d = %d + %d", reg_1, data_1, data_2);
	fprintf(f, "\tR%d = R%d >= 1;\n", reg_1, reg_1);
  }
}

void printNot(int reg, int data, bool is_id){
  //TODO
  if (is_id) {
    fprintf(f, "\tR%d = I(%d);\n", reg, data);
	fprintf(f, "\tR%d = R%d == 0);\n", reg, reg);
  } else {
	fprintf(f, "\tR%d = %d == 0);\n", reg, data);
  }
}

//Funtion Generation Code:::


// *************************************************************************
// void printLocalVariableValueAssignation(int relative_address, int value){
//   int framePointer = getCurrentFramePointer();
//   int address = framePointer + relative_address;
//   fprintf(f, "MEM(%d,%d);\n", address, value);
// }



