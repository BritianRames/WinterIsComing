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

void generateFuntionCall(char* functionToJump, int* parameters){
  char* currentFunction = getLastFunctionFromSymbolTable;
  //Actualizamos Stack
  int localSpace = getFunctionFromSymbolTable(currentFunction)->numberOfLocalVariables * 4;
  int registerSpace = 4 * 6; // 4 * number of register to store R1...R6
  updateStackPointer(localSpace + registerSpace); //Avanzamos espacio de locales y registros

  int goBackLabel = _getNextLabel();
  int parametersSpace = getFunctionFromSymbolTable(functionToJump)->numberOfParameters * 4;
  //Salvamos Registros
  printSaveRegistersValue(getCurrentStackPointer());
  //Actualizamos Registros a parametros
  printPutParametersInRegisters(getFunctionFromSymbolTable(functionToJump)->numberOfParameters, parameters);
  //Actualizamos FramePointer
  updateFramePointerToStackPointer(); //R6 = R7 
  //Actualizamos Stackpointer
  updateStackPointer(parametersSpace + 8); //Avanzamos espacio equivalente a parametros y framepointer y return label
  //Imprimimos GT
  printGoToInstruction(getFunctionFromSymbolTable(functionToJump)->label);
  //Escribimos código de salto y recover de datos y stack
  printLabelInstruction(goBackLabel);
  //Recuperamos Registros
  printRecoverRegisters();
  //Recuperamos StackPointer
  recoverStackPointer(localSpace + registerSpace);
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

void generateAddValueToR0(int value){
  printAddValueToR0(value);
}
void generateAddVariableToR0(char* id){
  printAddVariableToR0(_getVariableAddress(id));
}

void generateSubstractValueToR0(int value){
  printSubstractValueToR0(value);
}
void generateSubstractVariableToR0(char* id){
  printSubstractVariableToR0(_getVariableAddress(id));
}

void generateProductValueToR0(int value){
  printProductValueToR0(value);
}
void generateProductVariableToR0(char* id){
  printProductVariableToR0(_getVariableAddress(id));
}

void generateDivisionValueToR0(int value){
  printDivisionValueToR0(value);
}
void generateDivisionVariableToR0(char* id){
  printDivisionVariableToR0(_getVariableAddress(id));
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
