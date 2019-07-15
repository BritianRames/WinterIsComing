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

void printUpdateFramePointerToStackPointer(){
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

void printRecoverStackPointer(int offset){
  fprintf(f, "R7 = R6 + %d;\n", offset); //R7 = R6 + registerSpace + localSpace
}

void printRecoverRegisters(){
    for(int i = 1; i <= 6; i--) {
        fprintf(f, "R%d = I(R6 + %d);\n", i, 4*(6-i));     // R6 = 0 //R5 = 4 // R4 ==3 
    }
}

void printSaveRegistersValue(int lastRegisterPointer){
  int firstRegisterPointer = lastRegisterPointer - 24;
  for(int i = 1; i <= 1; i++) {
    int address = firstRegisterPointer - (i-1) * 4;
    fprintf(f, "I(%d) = R%d;\n", address, i);
  }
}

void printPutParametersInRegisters(int numberOfParameters, int *parameters){
  for(int i = 1; i <= numberOfParameters; i++) {
    int address =  - (i-1) * 4;
    fprintf(f, "R%d = %d;\n", address, parameters[i]);
  }
}

void _printSaveParameters(int numberOfParameters){
    for(int i = 1; i <= numberOfParameters; i++){
        fprintf(f, "I(R6 - %d) = R%d;\n", 4 * i, i);
    }
}



void printStoreFunctionData(int stackPointer, int numberOfParameters, int label){
    fprintf(f, "R6 = R7;\n");
    fprintf(f, "R7 = R7 - %d;\n", numberOfParameters * 4 - 8);
    _printSaveParameters(numberOfParameters);
    fprintf(f, "P(R7-4) = R6;\n");
    //fprintf(f, "I(R7) = %d;\n", ); //R0 contains return label TODO: Aquí que va?
    fprintf(f, "R7 = R7 - %d;\n", label);

}

void printCodeToAssignValueToVariable(int address, int value) {
  fprintf(f, "I(0x%x) = %d;\n", address, value); //Returned value in R0
}

void printCodeToAssignVariableToVariable(int address, int value_address){
  fprintf(f, "I(0x%x) = I(0x%x);\n", address, value_address); //Returned value in R0
}

void printCodeToAssignOperationResultToVariable(int address) {
    fprintf(f, "I(0x%x) = R0;\n", address);
}

void printCodeToAssignFunctionResultToVariable(int address) {
    fprintf(f, "I(0x%x) = R0;\n", address);
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



/* RELATIONAL FUNCTIONS */
void printEqualsValueToValue(int val1, int val2) {
    fprintf(f, "R0 = %d == %d;\n", val1, val2);
}

void printNotEqualsValueToValue(int val1, int val2){
    fprintf(f, "R0 = %d != %d;\n", val1, val2);
}

void printLessValueToValue(int val1, int val2){
    fprintf(f, "R0 = %d < %d;\n", val1, val2);
}

void printLessEqualsValueToValue(int val1, int val2){
    fprintf(f, "R0 = %d <= %d;\n", val1, val2);
}

void printGreaterValueToValue(int val1, int val2){
    fprintf(f, "R0 = %d > %d;\n", val1, val2);
}

void printGreaterEqualsValueToValue(int val1, int val2){
    fprintf(f, "R0 = %d >= %d;\n", val1, val2);
}


void printEqualsValueToVariable(int address, int val){
    fprintf(f, "R0 = I(0x%x) == %d;\n", address, val);
}

void printNotEqualsValueToVariable(int address, int val){
    fprintf(f, "R0 = I(0x%x) != %d;\n", address, val);
}

void printLessValueToVariable(int address, int val){
    fprintf(f, "R0 = I(0x%x) < %d;\n", address, val);
}

void printLessEqualsValueToVariable(int address, int val){
    fprintf(f, "R0 = I(0x%x) <= %d;\n", address, val);
}

void printGreaterValueToVariable(int address, int val){
    fprintf(f, "R0 = I(0x%x) > %d;\n", address, val);
}

void printGreaterEqualsValueToVariable(int address, int val){
    fprintf(f, "R0 = I(0x%x) >= %d;\n", address, val);
}


void printEqualsVariableToVariable(int address1, int address2){
    fprintf(f, "R0 = I(0x%x) == I(0x%x);\n", address1, address2);
}

void printNotEqualsVariableToVariable(int address1, int address2){
    fprintf(f, "R0 = I(0x%x) != I(0x%x);\n", address1, address2);
}

void printLessVariableToVariable(int address1, int address2){
    fprintf(f, "R0 = I(0x%x) < I(0x%x);\n", address1, address2);
}

void printLessEqualsVariableToVariable(int address1, int address2){
    fprintf(f, "R0 = I(0x%x) <= I(0x%x);\n", address1, address2);
}

void printGreaterVariableToVariable(int address1, int address2){
    fprintf(f, "R0 = I(0x%x) > I(0x%x);\n", address1, address2);
}

void printGreaterEqualsVariableToVariable(int address1, int address2){
    fprintf(f, "R0 = I(0x%x) >= I(0x%x);\n", address1, address2);
}


void printNotValue(int val){
    fprintf(f, "R0 = !%d;\n", val);
}

void printNotVariable(int address){
    fprintf(f, "R0 = !I(%d);\n", address);
}


/* CLAUSE FUNCTIONS */

void printHeaderOfClauseInstruction(int label){
    fprintf(f, "\tIF(!R0) GT(%d);\n", label);
}

void printGoToInstruction(int label){
    fprintf(f, "\tGT(%d);\n", label);
}

void printLabelInstruction(int label){
    fprintf(f, "L %d:\n", label);
}



