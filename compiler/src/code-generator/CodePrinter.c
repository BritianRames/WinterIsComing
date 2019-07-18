#include "CodePrinter.h"

FILE *f;

void openFile(){
  f = fopen("file.q.c", "w");
}

void printQInitialization(int stat, int code) {
    fprintf(f, "#include \"include/Qlib.h\"\n");
    fprintf(f, "#include \"include/Q.h\"\n\n");
    fprintf(f, "BEGIN\n");
    fprintf(f, "STAT(%d)\n",stat);
    fprintf(f, "\MEM(0x11ffc, 0);\n");
    fprintf(f, "CODE(%d)\n",code);
    fprintf(f, "L 0:\n");
}

void printJumpMain(){
    fprintf(f, "\tGT(1);\n");

}

void printMainFunction() {
    fprintf(f, "L 1:\n");
}

void printGoToExit()  {
    fprintf(f, "\tGT(-2);\n");
}

void printQEnding() {
    fprintf(f, "END\n");
}

void printUpdateFramePointerToStackPointer(){
  fprintf(f, "\tR6 = R7;\n");
}

void printUpdateStackPointer(int offset){
  fprintf(f, "\tR7 = R7 - %d;\n", offset);
}

void printFunctionLabel(int label){
  fprintf(f, "L %d:\n", label);
}

void printCodeToAssignParametersValueInStack(int numberOfParameters, int stackPointer){
  for(int i = 1; i <= numberOfParameters; i++){
    fprintf(f, "\tI(%d) = R%d;\n", stackPointer + 4 * (i - 1), i);
  }
}

void printReturnValue(int stackPointer, int valueToReturn){
  int returnLabelAddress = stackPointer; 
  fprintf(f, "\tR0 = %d;\n", valueToReturn); //Returned value in R0
  fprintf(f, "\tGT(I(%d));\n", returnLabelAddress);
}

void printReturnVariable(int stackPointer, int variableAddress){
  int returnLabelAddress = stackPointer; 
  fprintf(f, "\tR0 = I(0x%x);\n", variableAddress); //Returned value in R0
  fprintf(f, "\tGT(I(0x%x));\n", returnLabelAddress);
}

void printRecoverStackPointer(int offset){
  fprintf(f, "\tR7 = R6 + %d;\n", offset); //R7 = R6 + registerSpace + localSpace
}

void printRecoverRegisters(){
    for(int i = 1; i <= 6; i--) {
        fprintf(f, "\tR%d = I(R6 + %d);\n", i, 4*(6-i));     // R6 = 0 //R5 = 4 // R4 ==3 
    }
}

void printSaveRegistersValue(int lastRegisterPointer){
  int firstRegisterPointer = lastRegisterPointer - 24;
  for(int i = 1; i <= 1; i++) {
    int address = firstRegisterPointer - (i-1) * 4;
    fprintf(f, "\tI(%d) = R%d;\n", address, i);
  }
}

void printPutParametersInRegisters(int numberOfParameters, int *parameters){
  for(int i = 1; i <= numberOfParameters; i++) {
    int address =  - (i-1) * 4;
    fprintf(f, "\tR%d = %d;\n", address, parameters[i]);
  }
}

void _printSaveParameters(int numberOfParameters){
    for(int i = 1; i <= numberOfParameters; i++){
        fprintf(f, "\tI(R6 - %d) = R%d;\n", 4 * i, i);
    }
}



void printStoreFunctionData(int stackPointer, int numberOfParameters, int label){
    fprintf(f, "\tR6 = R7;\n");
    fprintf(f, "\tR7 = R7 - %d;\n", numberOfParameters * 4 - 8);
    _printSaveParameters(numberOfParameters);
    fprintf(f, "\tP(R7-4) = R6;\n");
    //fprintf(f, "I(R7) = %d;\n", ); //R0 contains return label TODO: Aquí que va?
    fprintf(f, "\tR7 = R7 - %d;\n", label);

}

void printCodeToAssignValueToVariable(int address, int value) {
  fprintf(f, "\tI(0x%x) = %d;\n", address, value); //Returned value in R0
}

void printCodeToAssignVariableToVariable(int address, int value_address){
  fprintf(f, "\tI(0x%x) = I(0x%x);\n", address, value_address); //Returned value in R0
}

void printCodeToAssignOperationResultToVariable(int address, int stackPointer) {
    fprintf(f, "\tI(0x%x) = I(0x%x);\n", address, stackPointer);
}

void printCodeToAssignFunctionResultToVariable(int address) {
    fprintf(f, "\tI(0x%x) = R0;\n", address);
}

void printPrintStringCode(char* string,int address,int label,int stat,int code){
  fprintf(f,"\tR7 = R7 - %d;\n",strlen(string) + 4);
  fprintf(f,"\tP(R7 + %d) = %d;\n",strlen(string),address);
  fprintf(f,"STAT(%d)\n",stat);
  fprintf(f,"\tSTR(0x%x,\"%s\");\n",address,string);
  fprintf(f,"CODE(%d)\n",code);
  fprintf(f,"\tR7 = %d;\n",label);
  fprintf(f,"\tGT(-12);\n");
  fprintf(f,"L %d: R7 = R7 + %d;\n",label,strlen(string));
}


void printPrintValueCode(int print_address,int value,int label,int stat,int code){
  fprintf(f,"\tR7 = R7 - 12;\n",value);
  fprintf(f,"\tP(R7 + 8) = 0x11ffc;\n");
  fprintf(f,"STAT(%d)\n",stat);
  fprintf(f,"\tSTR(0x%x,\"%%d\\n\");\n",print_address);
  fprintf(f,"CODE(%d)\n",code);
  fprintf(f,"\tI(R7 + 4) = I(%d);\n",value);
  fprintf(f,"\tI(R7) = %d;\n",label);
  fprintf(f,"\tGT(-12);\n");
  fprintf(f,"\tR7 = R7 + 12;\n");
}

void printPrintVariableCode(int print_address,int value_address,int label,int stat,int code){
  fprintf(f,"\tR7 = R7 - 12;\n");
  fprintf(f,"\tP(R7 + 8) = 0x11ffc;\n");
  fprintf(f,"STAT(%d)\n",stat);
  fprintf(f,"\tSTR(0x%x,\"%%d\\n\");\n",print_address);
  fprintf(f,"CODE(%d)\n",code);
  fprintf(f,"\tI(R7 + 4) = I(%d);\n",value_address);
  fprintf(f,"\tI(R7) = %d;\n",label);
  fprintf(f,"\tGT(-12);\n");
  fprintf(f,"\tR7 = R7 + 12;\n");
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

void printInsertOnStack(int address, int value){
  fprintf(f, "\tI(0x%x) = %d;\n", address, value);
}

void printInsertOnStackVariable(int address, int var_address){
  fprintf(f, "\tI(0x%x) = I(0x%x);\n", address, var_address);
}


void printAddValue(int address){
    fprintf(f, "\tR1 = I(0x%x);\n", address+4);
    fprintf(f, "\tI(0x%x) = R1 + I(0x%x);\n", address+4,address);

}

//void printAddVariable(int address){
//    fprintf(f, "R1 = I(0x%x);\n", address+4);
//    fprintf(f, "I(0x%x) = R1 + I(0x%x);\n", address+4,address);
//}

void printSubstractValue(int address){
    fprintf(f, "\tR1 = I(0x%x);\n", address+4);
    fprintf(f, "\tI(0x%x) = R1 - I(0x%x);\n", address+4,address);
}

void printSubstractVariable(int address){
    fprintf(f, "\tR0 = R0 - I(0x%x);\n", address);
}

void printProductValue(int address){
    fprintf(f, "\tR1 = I(0x%x);\n", address+4);
    fprintf(f, "\tI(0x%x) = R1 * I(0x%x);\n", address+4,address);
}

void printProductVariable(int address){
    fprintf(f, "\tR0 = R0 * I(0x%x);\n", address);
}

void printDivisionValue(int address){
    fprintf(f, "\tR1 = I(0x%x);\n", address+4);
    fprintf(f, "\tI(0x%x) = R1 / I(0x%x);\n", address+4,address);
}

void printDivisionVariable(int address){
    fprintf(f, "\tR0 = R0 / I(0x%x);\n", address);
}

void printCodeAssignOperationResultToVariable(int address) {
    fprintf(f, "\tI(0x%x) = R0;\n", address);
}







/* RELATIONAL FUNCTIONS */
void printEqualsValueToValue(int val1, int val2) {
    fprintf(f, "\tR0 = %d == %d;\n", val1, val2);
}

void printNotEqualsValueToValue(int val1, int val2){
    fprintf(f, "\tR0 = %d != %d;\n", val1, val2);
}

void printLessValueToValue(int val1, int val2){
    fprintf(f, "\tR0 = %d < %d;\n", val1, val2);
}

void printLessEqualsValueToValue(int val1, int val2){
    fprintf(f, "\tR0 = %d <= %d;\n", val1, val2);
}

void printGreaterValueToValue(int val1, int val2){
    fprintf(f, "\tR0 = %d > %d;\n", val1, val2);
}

void printGreaterEqualsValueToValue(int val1, int val2){
    fprintf(f, "\tR0 = %d >= %d;\n", val1, val2);
}


void printEqualsValueToVariable(int address, int val){
    fprintf(f, "\tR0 = I(0x%x) == %d;\n", address, val);
}

void printNotEqualsValueToVariable(int address, int val){
    fprintf(f, "\tR0 = I(0x%x) != %d;\n", address, val);
}

void printLessValueToVariable(int address, int val){
    fprintf(f, "\tR0 = I(0x%x) < %d;\n", address, val);
}

void printLessEqualsValueToVariable(int address, int val){
    fprintf(f, "\tR0 = I(0x%x) <= %d;\n", address, val);
}

void printGreaterValueToVariable(int address, int val){
    fprintf(f, "\tR0 = I(0x%x) > %d;\n", address, val);
}

void printGreaterEqualsValueToVariable(int address, int val){
    fprintf(f, "\tR0 = I(0x%x) >= %d;\n", address, val);
}


void printEqualsVariableToVariable(int address1, int address2){
    fprintf(f, "\tR0 = I(0x%x) == I(0x%x);\n", address1, address2);
}

void printNotEqualsVariableToVariable(int address1, int address2){
    fprintf(f, "\tR0 = I(0x%x) != I(0x%x);\n", address1, address2);
}

void printLessVariableToVariable(int address1, int address2){
    fprintf(f, "\tR0 = I(0x%x) < I(0x%x);\n", address1, address2);
}

void printLessEqualsVariableToVariable(int address1, int address2){
    fprintf(f, "\tR0 = I(0x%x) <= I(0x%x);\n", address1, address2);
}

void printGreaterVariableToVariable(int address1, int address2){
    fprintf(f, "\tR0 = I(0x%x) > I(0x%x);\n", address1, address2);
}

void printGreaterEqualsVariableToVariable(int address1, int address2){
    fprintf(f, "\tR0 = I(0x%x) >= I(0x%x);\n", address1, address2);
}


void printNotValue(int val){
    fprintf(f, "\tR0 = !%d;\n", val);
}

void printNotVariable(int address){
    fprintf(f, "\tR0 = !I(%d);\n", address);
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

/* ARRAY MANAGEMENT */
void printCreateArray(int addr, int size) {
    fprintf(f, "\tFIL(P(0x%x),%d,0);\n", addr, size);
}

void printArrayAssignValue(int addr, int pos, int val) {
    fprintf(f, "\tI(P(0x%x)) = %d;\n", addr - 4 * pos, pos, val);
}

void printArrayAssignVariable(int addr1, int pos, int addr2){
    fprintf(f, "\tI(P(0x%x) - 4 * %d) = I(0x%x);\n", addr1, pos, addr2);
}

void printArrayAssignArray(int addr1, int pos1, int addr2, int pos2) {
    fprintf(f, "\tI(P(0x%x) - 4 * %d) = I(P(0x%x) + 4 * %d);\n", addr1, pos1, addr2, pos2);
}
