#include "CodePrinter.h"

FILE *f;

void openFile(){
  f = fopen("file.q.c", "w");
}

void printQInitialization() {
    fprintf(f, "#include \"include/Qlib.h\"\n");
    fprintf(f, "#include \"include/Q.h\"\n\n");
    fprintf(f, "BEGIN\n");
    fprintf(f, "STAT(0)\n");
    fprintf(f, "MEM(0x11ffc, 0);\n");
    fprintf(f, "CODE(0)\n");
    fprintf(f, "L 0:\n");
}

void printGlobalDefinitionAreaEnding(){
    fprintf(f, "GT(1);\n");

}

void printMainFunction() {
    fprintf(f, "L 1:\n");
}

void printGoToExit()  {
    fprintf(f, "GT(-2);\n");
}

void printQEnding() {
    fprintf(f, "END\n");
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
  fprintf(f, "GT(I(%d));\n", returnLabelAddress);
}

void printReturnVariable(int stackPointer, int variableAddress){
  int returnLabelAddress = stackPointer; 
  fprintf(f, "R0 = I(0x%x);\n", variableAddress); //Returned value in R0
  fprintf(f, "GT(I(0x%x));\n", returnLabelAddress);
}

void printRecoverRegistersValue(int registerFramePointer){
  for(int i = 0; i <= 7; i--){
    fprintf(f, "R%d = I(0x%x);\n", i, registerFramePointer + ((i - 1) * 4));
  }
}

void printSaveRegistersValue(int registerFramePointer){
  for(int i = 0; i <= 7; i--) {
    fprintf(f, "I(0x%x) = R%d;\n", registerFramePointer + ((i - 1) * 4), i);
  }
}

void printCodeToAssignValueToVariable(int address, int value) {
  fprintf(f, "I(0x%x) = %d;\n", address, value); //Returned value in R0
}

void printCodeToAssignVariableToVariable(int address, int value_address){
  fprintf(f, "I(0x%x) = I(0x%x);\n", address, value_address); //Returned value in R0
}

void printPrintStringCode(char* string){
  fprintf(f,"printf(\"%s\");\n",string);
}


void printPrintValueCode(int value){
  fprintf(f,"printf(\"%d\");\n",value);
}

void printPrintVariableCode(int address){
  fprintf(f,"R0=I(0x%x);\n",address);
  fprintf(f,"printf(\"%%d\\n\",R0);\n");
}


///* REGISTRIES MANAGEMENT */
//
//void printPushReg(int r) {
//    fprintf(f, "R7 = R7 - 4;");
//    fprintf(f, "I(R7) = R%d;", r);
//}
//
//void printPopReg(int r) {
//    fprintf(f, "R%d = I(R7);", r);
//    fprintf(f, "R7 = R7 + 4;");
//}

/* ARITHMETICAL FUNCTIONS */

void printAddValueToValue(int val1, int val2) {
    fprintf(f, "R0 = %d + %d;\n", val1, val2);
}

void printSubtractValueToValue(int val1, int val2) {
    fprintf(f, "R0 = %d - %d;\n", val1, val2);
}

void printProductValueToValue(int val1, int val2) {
    fprintf(f, "R0 = %d * %d;\n", val1, val2);
}

void printDivisionValueToValue(int val1, int val2) {
    fprintf(f, "R0 = %d / %d;\n", val1, val2);
}

void printCodeAssignOperationResultToVariable(int address) {
    fprintf(f, "I(0x%x) = R0;\n", address);
}

void printAddValueToVariable(int address, int val){
    fprintf(f, "R0 = I(0x%x) + %d;\n", address, val);
}

void printSubtractValueToVariable(int address, int val){
    fprintf(f, "R0 = I(0x%x) - %d;\n", address, val);
}

void printMultiplyValueToVariable(int address, int val){
    fprintf(f, "R0 = I(0x%x) * %d;\n", address, val);
}

void printDivideValueToVariable(int address, int val){
    fprintf(f, "R0 = I(0x%x) / %d;\n", address, val);
}

void printAddVariableToVariable(int address1, int address2) {
    fprintf(f, "R0 = I(0x%x) + I(0x%x);\n", address1, address2);
}

void printSubtractVariableToVariable(int address1, int address2) {
    fprintf(f, "R0 = I(0x%x) - I(0x%x);\n", address1, address2);
}

void printMultiplyVariableToVariable(int address1, int address2) {
    fprintf(f, "R0 = I(0x%x) * I(0x%x);\n", address1, address2);
}

void printDivideVariableToVariable(int address1, int address2) {
    fprintf(f, "R0 = I(0x%x) / I(0x%x);\n", address1, address2);
}

/* IF CLAUSE */

void printHeaderOfIfInstruction(int reg, int cond_value, int if_label){ //REFACTOR
    fprintf(f, "\tR%d = %d;\n", reg, cond_value);
    fprintf(f, "\tIF(R%d) GT(%d);\n", cond_value, if_label);
}

void printGoToInstruction(int label){
    fprintf(f, "\tGT(%d);\n", label);
}

void printLabelInstruction(int label){
    fprintf(f, "L %d:\n", label);
}


