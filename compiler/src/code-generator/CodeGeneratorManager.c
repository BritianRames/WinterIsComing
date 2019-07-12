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
  printFunctionLabel(getLastFunctionLabel());
  printUpdateFramePointer(); // R6 = R7;
  updateStackPointer((numberOfParameters + 2) * 4); //R7 + X; TS --> stackPointer + X
  printCodeToAssignParametersValueInStack(numberOfParameters, getCurrentStackPointer());
}
//Update lv number

void generateFunctionReturnValueCode(int value){
  printReturnValue();
}

void generateFunctionReturnVariableCode(char* variableToReturn){
  printReturnVariable(getVariableAddressFromSymbolTable(variableToReturn));
}

void generateAssignVariableToGlobalVariableCode(char* variable_id, char value_id){
  int variable_address = getVariableAddressFromSymbolTable(variable_id);
  int value_address = getVariableAddressFromTable(value_id);
  int printGlobalVariableVariableAsignation(variable_address, value_address);
}

void generateIfHeader(int reg, int cond_value){
  //TODO
  int else_label = _getNextLabel();
  printHeaderOfIfInstruction(reg, cond_value, else_label);
}

void generateIfElse(){
  //TODO
  int else_label = _getCurrentLabel();
  int exit_label = _getNextLabel();
  printMiddleOfIfInstruction(exit_label, else_label);
}

void generateIfEnd(){
  //TODO
  int exit_label = _getCurrentLabel();
  printEndOfIfInstruction(exit_label);
}

void generateWhileHeader(int reg, int cond_value){
  //TODO
  int begin_label = _getNextLabel();
  int end_label = begin_label;
  printHeaderOfWhileInstruction(reg, cond_value, begin_label, end_label);
}

void generateWhileEnd(){
  //TODO
  int begin_label = _getCurrentLabel();
  int end_label = _getNextLabel();
  printEndOfWhileInstruction(begin_label, end_label);
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
