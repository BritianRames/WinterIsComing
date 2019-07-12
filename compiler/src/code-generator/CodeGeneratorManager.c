#include "../symbol-table/SymbolTableManager.h"
#include "CodeGeneratorManager.h"
#include "StackManager.h"
#include "CodePrinter.h"

void generateAssignValueToGlobalVariable(char* variable_id, int value){
  int variable_address = getVariableAddressFromSymbolTable(variable_id);
  printGlobalVariableValueAssignation(variable_address, value);
  printSymbolTable();
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
  int value_address = getVariableAddressFromSymbolTable(value_id);
  printGlobalVariableVariableAsignation(variable_address, value_address);
}

void generateFunctionReturnValueCode(int value){
  printReturnValue(getCurrentStackPointer(), value);
}

void generateFunctionReturnVariableCode(char* variableToReturn){
  printReturnVariable(getCurrentStackPointer(), getVariableAddressFromSymbolTable(variableToReturn));
}


void generateAssignValueToLocalVariableAssignationCode(char *local_variable_id, int value){
  int local_variable_address = getVariableAddressFromSymbolTable(local_variable_id) * 4;
  printCodeToAssignLocalVariableValueInStack(local_variable_address, value);
}

void generateAssignLocalVariableToLocalVariableCode(char* local_variable_id, char value_id){
  int local_variable_address = getVariableAddressFromSymbolTable(local_variable_id) * 4;
  int value_address = getVariableAddressFromSymbolTable(value_id) * 4;
  printCodeToAssignLocalVariableVariableInStack(local_variable_address, value_address);
  //int value = getValueFromStack(value_address)
  //generateAssignationCode(variable_address, value)
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