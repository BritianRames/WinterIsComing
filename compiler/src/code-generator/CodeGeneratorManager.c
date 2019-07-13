#include "../symbol-table/SymbolTableManager.h"
#include "CodeGeneratorManager.h"
#include "StackManager.h"
#include "CodePrinter.h"

void generateQInitialization() {
    printQInitialization();
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
  printGlobalVariableValueAssignation(variable_address, value);
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

void generateAssignVariableToGlobalVariableCode(char* variable_id, char value_id){
  int variable_address = getVariableAddressFromSymbolTable(variable_id);
  int value_address = _getNextLocalVariableAddressFromSymbolTable(value_id);
  printGlobalVariableVariableAsignation(variable_address, value_address);
}

void generateFunctionReturnValueCode(int value){
  printReturnValue(getCurrentStackPointer(), value);
}

void generateFunctionReturnVariableCode(char* variableToReturn){
  struct Symbol* variable = getVariableFromSymbolTable(variableToReturn);
  int address = variable->type == 'g' ? variable->address : getCurrentStackPointer - variable->address * 4;

  printReturnVariable(getCurrentStackPointer(), address);
}

void generateAssignValueToVariableCode(char *variable_id, int value){
  printCodeToAssignValueToVariable(_getVariableAddress(variable_id), value);
}

void generateAssignVariableToVariableCode(char* variable_id, char value_id){
  printCodeToAssignVariableToVariable(_getVariableAddress(variable_id), _getVariableAddress(value_id));
}

int _getVariableAddress(char* variable_id){
  struct Symbol* variable = getVariableFromSymbolTable(variable_id);
  if(variable == -1) printf("\nElement not found \n");
  else{
    printf("%c",variable->type);
    if (variable->type == 'g') return variable->address;
   else return getCurrentStackPointer() - variable->address * 4;
  }
  return 1000;
}

void generateReturnValueCode(int value){
  //generateAssignValuleToRegister(getReturnRegisterNumber());
  //generateGoToPreviousContext();
  //generateRecoverScopeRegister();
}

void generateReturnVariableCode(char* variable){
  //int variable_address = getVariableAddressFromTable(variable_id) -->   use symbol table
  //int value_address = getVariableAddres(value_id)
  //int value = getValueFromStack(value_address)
  //int address = getReturnCurrentFunctionAddress()
  //generateAssignationCode(address, value) --> we have a memory position for return value (maybe better a register)
}

void generatePrintString(char* string){
  printPrintStringCode(string);
}

void generatePrintValue(int value){
  printPrintValueCode(value);
}
void generatePrintVariable(char* id){
  
  int addr = _getVariableAddress(id);
  printf("FALTA ESTE METODO");
  printPrintVariableCode(addr);
}
