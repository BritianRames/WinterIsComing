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
  int value_address = _getNextLocalVariableAddressFromSymbolTable(value_id);
  printGlobalVariableVariableAsignation(variable_address, value_address);
}

void generateFunctionReturnValueCode(int value){
  printReturnValue(getCurrentStackPointer(), value);
}

void generateFunctionReturnVariableCode(char* variableToReturn){
  printReturnVariable(getCurrentStackPointer(), getVariableAddressFromSymbolTable(variableToReturn));
}


void generateAssignValueToVariableAssignationCode(char *variable_id, int value){
  struct Symbol* variable = getVariableFromSymbolTable(variable_id);
  int address = variable->type == 'g' ? variable->address : getCurrentStackPointer - variable->address * 4;

  printCodeToAssignValueToVariable(address, value);
}

void generateAssignVariableToVariableCode(char* variable_id, char value_id){
  struct Symbol* variable = getVariableFromSymbolTable(variable_id);
  int address = variable->type == 'g' ? variable->address : getCurrentStackPointer - variable->address * 4;

  struct Symbol* value = getVariableFromSymbolTable(variable_id);
  int value_address = value->type == 'g' ? value->address : getCurrentStackPointer - value->address * 4;
  
  printCodeToAssignVariableToVariable(address, value_address);
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