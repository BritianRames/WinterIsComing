#include "../symbol-table/SymbolTableManager.h"
#include "CodeGeneratorManager.h"
#include "CodePrinter.h"

void generateAssignValueToGlobalVariable(char* variable_id, int value){
  int variable_address = getVariableAddressFromSymbolTable(variable_id);
  printGlobalVariableValueAssignation(variable_address, value);
  printSymbolTable();
}

void generateAssignVariableToGlobalVariableCode(char* variable_id, char value_id){
  int variable_address = getVariableAddressFromSymbolTable(variable_id);
  int value_address = getVariableAddressFromSymbolTable(value_id);
  int printGlobalVariableVariableAsignation(variable_address, value_address);
}

void generateFunctionCode(){
  //TODO !IMPORTANT
}

void generateAssignValueToLocalVariableCode(char *local_variable_id, int value){
  //int local_variable_address = getVariableAddressFromSymbolTable(local_variable_id);
  //printLocalVariableValueAssignation(local_variable_id, value);
}

void generateAssignVariableToLocalVariableCode(char* variable_id, char value_id){
  //int variable_address = getVariableAddressFromTable(variable_id) -->   use symbol table
  //int value_address = getVariableAddressFromTable(value_id)
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
