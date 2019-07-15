#include "../symbol-table/SymbolTableManager.h"
#include "CodeGeneratorManager.h"
#include "StackManager.h"
#include "CodePrinter.h"

//int spill_count = 0;
//bool reg_free[MAX_REG] = { true, true, true, true };
//
///* REGISTRIES MANAGEMENT */
//int get_reg()
//{
//    for (int i = 0; i <= MAX_REG; i++)
//    {
//        if (reg_free[i])
//        {
//            lock_reg(i);
//            return i;
//        }
//    }
//
//    push_reg(spill_count);
//    spill_count = (spill_count + 1) % MAX_REG;
//    return -1;
//}
//
//
//void free_reg(int i) {
//    reg_free[i] = true;
//}
//
//void lock_reg(int i) {
//    reg_free[i] = false;
//}
//
//bool is_used(int i) {
//    reg_free[i];
//}

//void push_reg(int r) {
//    printPushReg(r);
//    free_reg(r);
//}
//
//void pop_reg(int r) {
//    printPopReg(r);
//    lock_reg(r);
//}


/* GENERAL STUFF */
void generateQInitialization() {
    printQInitialization();
}

void generateGlobalDefinitionAreaEnding(){
    printGlobalDefinitionAreaEnding();
}


void generateMainFunction() {
    printMainFunction();
}

void generateGoToExit() {
    printGoToExit();
}

void generateQEnding() {
    printQEnding();
}

void generateAssignValueToGlobalVariable(char* variable_id, int value){
  int variable_address = getVariableAddressFromSymbolTable(variable_id);
  printCodeToAssignValueToVariable(variable_address, value);
}

void generateFunctionHeaderCode(){
  struct Symbol* function = getLastFunctionFromSymbolTable();
  int numberOfParameters = function->numberOfParameters;
  printFunctionLabel(function->label);

  printUpdateFramePointer(); // R6 = R7;
  updateStackPointer((numberOfParameters + 2) * 4); //R7 + X; TS --> stackPointer + X
  printCodeToAssignParametersValueInStack(numberOfParameters, getCurrentStackPointer());
}
//Update lv number



void generateFunctionReturnValueCode(int value){
  printReturnValue(getCurrentStackPointer(), value);
}

void generateReturnVariableCode(char* variable){
    printReturnVariable(getCurrentStackPointer(), getVariableAddressFromSymbolTable(variable));
}

void generateFunctionCall(){
    printGoToInstruction(getLastFunctionFromSymbolTable()->label);
    int returnLabel = _getNextLabel();
    printLabelInstruction(returnLabel);
    printRecoverStack(getLastFunctionFromSymbolTable()->numberOfParameters);
    printRecoverRegisters();
    printSaveRegistersValue(getCurrentStackPointer()+4);
    printPutParametersInRegisters();
    updateStackPointer(4*6); //R1 ... R6
    printStoreFunctionData(getCurrentStackPointer(), getLastFunctionFromSymbolTable()->numberOfParameters, returnLabel);
    printParametersAsignation();
}


void generateAssignValueToVariableCode(char *variable_id, int value){
  printCodeToAssignValueToVariable(_getVariableAddress(variable_id), value);
}

void generateAssignVariableToVariableCode(char* variable_id, char* value_id){
  printCodeToAssignVariableToVariable(_getVariableAddress(variable_id), _getVariableAddress(value_id));
}

int _getVariableAddress(char* variable_id){
  struct Symbol* variable = getVariableFromSymbolTable(variable_id);
  if(variable == -1) printf("\nElement not found \n");
  else if (variable->type == 'g') return variable->address;
  else return getCurrentStackPointer() - variable->address * 4;
  return 1000;
}

void generateReturnValueCode(int value){
  //generateAssignValuleToRegister(getReturnRegisterNumber());
  //generateGoToPreviousContext();
  //generateRecoverScopeRegister();
}

void generatePrintString(char* string){
  printPrintStringCode(string);
}

void generatePrintValue(int value){
  printPrintValueCode(value);
}

void generatePrintVariable(char* id){ //TODO
  int address = _getVariableAddress(id);
  printPrintVariableCode(address);
  printf("----------------->0x%x<----------------", address);
}

void generateAddValueToValue(int firstValue, int secondValue) {
    printAddValueToValue(firstValue, secondValue);
}

void generateSubtractValueToValue(int firstValue, int secondValue) {
    printSubtractValueToValue(firstValue, secondValue);
}

void generateProductValueToValue(int firstValue, int secondValue) {
    printProductValueToValue(firstValue, secondValue);
}

void generateDivisionValueToValue(int firstValue, int secondValue) {
    printDivisionValueToValue(firstValue, secondValue);
}


void generateAddValueToVariable(char* variable, int val) {
    printAddValueToVariable(_getVariableAddress(variable), val);
}

void generateSubtractValueToVariable(char* variable, int val) {
    printSubtractValueToVariable(_getVariableAddress(variable), val);
}

void generateProductValueToVariable(char* variable, int val) {
    printMultiplyValueToVariable(_getVariableAddress(variable), val);
}

void generateDivisionValueToVariable(char* variable, int val) {
    printDivideValueToVariable(_getVariableAddress(variable), val);
}

void generateAddVariableToVariable(char* variable1, char* variable2) {
    printAddVariableToVariable(_getVariableAddress(variable1), _getVariableAddress(variable2));
}

void generateSubtractVariableToVariable(char* variable1, char* variable2) {
    printSubtractVariableToVariable(_getVariableAddress(variable1), _getVariableAddress(variable2));
}

void generateProductVariableToVariable(char* variable1, char* variable2) {
    printMultiplyVariableToVariable(_getVariableAddress(variable1), _getVariableAddress(variable2));
}

void generateDivisionVariableToVariable(char* variable1, char* variable2) {
    printDivideVariableToVariable(_getVariableAddress(variable1), _getVariableAddress(variable2));
}

void generateAssignOperationResultToVariable(char* id) {
    printCodeAssignOperationResultToVariable(_getVariableAddress(id));
}

void printPutParametersInRegisters() {
    // TOOD: This fuction is not yet implemented
}

void printParametersAsignation() {
    // TOOD: This fuction is not yet implemented
}
