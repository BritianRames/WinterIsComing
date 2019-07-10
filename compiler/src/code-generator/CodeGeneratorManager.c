#include "../symbol-table/SymbolTableManager.h"
#include "CodeGeneratorManager.h"
#include "CodePrinter.h"

void generateAssignValueToGlobalVariable(char* variable_id, int value){
  int variable_address = getVariableAddressFromSymbolTable(variable_id);
  generateAssignation(variable_address, value);
    printSymbolTable();
}

void generateAssignVariableToGlobalVariableCode(char* variable_id, char value_id){
  //int variable_address = getVariableAddressFromTable(variable_id) 
  //int value_address = getVariableAddressFromTable(value_id)
  //int value = getValueFromStack(value_address)
  //generateAssignationCode(variable_address, value) --> this function should deal with registers and stack
}

void generateAssignValueToLocalVariableCode(char *variable_id, int value){
  //int variable_address = getVariableAddressFromTable(variable_id) -->   use symbol table
  //generateAssignationCode(variable_address, value);
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

void assignVariableValue(char *variableId, char *valueVariableId){
  //Load data form valueVariable
  //Save data in variableId
}

void assignFunctionReturnValue(char *variable, char *function){ 
  // No entiendo bien que se haría aquí ****
  // Find function position in function list
  // having this we know the position in the stack
  // and the position of the return value
  // so we should store it in the variable position
}