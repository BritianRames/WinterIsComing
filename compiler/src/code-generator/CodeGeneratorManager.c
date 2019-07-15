#include "../symbol-table/SymbolTableManager.h"
#include "CodeGeneratorManager.h"
#include "StackManager.h"
#include "CodePrinter.h"

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

void generateFunctionReturnValueCode(int value){
  printReturnValue(getCurrentStackPointer(), value);
}

void generateReturnVariableCode(char* variable){
  printReturnVariable(getCurrentStackPointer(), getVariableAddressFromSymbolTable(variable));
}

void generateCallFunctionCode(char* functionToJump, int* parameters){
  struct Symbol* currentFunction = getFunctionFromSymbolTable(functionToJump)->numberOfParameters;
  int localSpace = getFunctionFromSymbolTable(currentFunction)->numberOfLocalVariables * 4;
  int registerSpace = 4 * 7; // 4 * number of register to store R1...R6
  int parametersSpace =currentFunction->numberOfParameters * 4;
  
  updateStackPointer(localSpace); //Avanzamos espacio de locales y registros
  printSaveRegistersValues(getCurrentStackPointer());
  updateStackPointer(registerSpace); //Avanzamos espacio de locales y registros
  updateFramePointerToStackPointer(); //R6 = R7 
  printPutParametersInStack(currentFunction->numberOfParameters, parameters);
  updateStackPointer(parametersSpace + 8); //Avanzamos espacio equivalente a parametros y framepointer y return label

  int goBackLabel = _getNextLabel();
  printInsertReturnLabelInStack(goBackLabel);
  printGoToInstruction(currentFunction->label);
  printLabelInstruction(goBackLabel);
  printRecoverRegistersValues();
  recoverStackPointer(localSpace + registerSpace + parameterSpace + 2);
}


void generateAssignValueToVariableCode(char *variable_id, int value){
  printCodeToAssignValueToVariable(_getVariableAddress(variable_id), value);
}

void generateAssignVariableToVariableCode(char* variable_id, char* value_id){
  printCodeToAssignVariableToVariable(_getVariableAddress(variable_id), _getVariableAddress(value_id));
}

void generateAssignVariableToFunctionResult(char* variable){
  printCodeToAssignFunctionResultToVariable(variable);
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
    printCodeToAssignOperationResultToVariable(_getVariableAddress(id));
}

int _getVariableAddress(char* variable_id){
  struct Symbol* variable = getVariableFromSymbolTable(variable_id);
  if(variable == -1) printf("\nElement not found \n");
  else if (variable->type == 'g') return variable->address;
  else return getCurrentStackPointer() - variable->address * 4;
  return 1000;
}
// void generateReturnValueCode(int value){
//   //generateAssignValuleToRegister(getReturnRegisterNumber());
//   //generateGoToPreviousContext();
//   //generateRecoverScopeRegister();
// }

// void generateReturnVariableCode(char* variable){
//   //int variable_address = getVariableAddressFromTable(variable_id) -->   use symbol table
//   //int value_address = getVariableAddres(value_id)
//   //int value = getValueFromStack(value_address)
//   //int address = getReturnCurrentFunctionAddress()
//   //generateAssignationCode(address, value) --> we have a memory position for return value (maybe better a register)
// }
