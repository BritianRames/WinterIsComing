#include "../symbol-table/SymbolTableManager.h"
#include "CodeGeneratorManager.h"
#include "StackManager.h"
#include "CodePrinter.h"

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
//Update lv number

void generateFunctionReturnValueCode(int value){
  printReturnValue();
}

void generateFunctionReturnVariableCode(char* variableToReturn){
  printReturnVariable(getVariableAddressFromSymbolTable(variableToReturn));
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

void generateArrayAccessIntVal(int i_reg, int i, char* array){
  //TODO
  unsigned int array_address = getVariableAddressFromSymbolTable(array);
  printArrayAccessIntVal(i_reg, i, array_address);
}

void generateArrayAccessId(int i_reg, char* i, char* array){
  //TODO
  unsigned int array_address = getVariableAddressFromSymbolTable(array);
  unsigned int i_address = getVariableAddressFromSymbolTable(i);
  printArrayAccessId(i_reg, i_address, array_address);
}

void generateArrayInit(char* array, int length){
  //TODO
  insertVariableInSymbolTable(array);
  unsigned int array_address = getVariableAddressFromSymbolTable(array);
  printArrayInit(array_address, length);
}

void generateSum(int reg_1, int reg_2, void* data_1, void* data_2){
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printSum(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printSum(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printSum(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printSum(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateSubstract(int reg_1, int reg_2, void* data_1, void* data_2){
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printSubstract(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printSubstract(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printSubstract(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printSubstract(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateProduct(int reg_1, int reg_2, void* data_1, void* data_2){
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printProduct(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printProduct(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printProduct(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printProduct(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateDivide(int reg_1, int reg_2, void* data_1, void* data_2){
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printDivide(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printDivide(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printDivide(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printDivide(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateLess(int reg_1, int reg_2, void* data_1, void* data_2){
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printLess(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printLess(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printLess(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printLess(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateGreater(int reg_1, int reg_2, void* data_1, void* data_2){
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printGreater(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printGreater(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printGreater(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printGreater(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateEquals(int reg_1, int reg_2, void* data_1, void* data_2){
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printEquals(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printEquals(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printEquals(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printEquals(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateLessEquals(int reg_1, int reg_2, void* data_1, void* data_2){
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printLessEquals(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printLessEquals(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printLessEquals(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printLessEquals(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateGreaterEquals(int reg_1, int reg_2, void* data_1, void* data_2){
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printGreaterEquals(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printGreaterEquals(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printGreaterEquals(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printGreaterEquals(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateNotEquals(int reg_1, int reg_2, void* data_1, void* data_2){
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printNotEquals(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printNotEquals(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printNotEquals(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printNotEquals(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateAnd(int reg_1, int reg_2, void* data_1, void* data_2) {
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printAnd(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printAnd(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printAnd(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printAnd(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateOr(int reg_1, int reg_2, void* data_1, void* data_2) {
  //TODO
  if (typeof(data_1) != int && typeof(data_2) != int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printOr(reg_1, reg_2, address_1, true, address_2, true);
  } else if (typeof(data_1) == int && typeof(data_2) != int) {
	unsigned int address_2 = getVariableAddressFromSymbolTable(data_2);
	printOr(reg_1, reg_2, data_1, true, address_2, true);
  } else if (typeof(data_1) != int && typeof(data_2) == int) {
	unsigned int address_1 = getVariableAddressFromSymbolTable(data_1);
	printOr(reg_1, reg_2, address_1, true, data_2, true);
  } else {
	printOr(reg_1, reg_2, data_1, true, data_2, true);
  }
}

void generateNot(int reg, void* data) {
  //TODO
  if (typeof(data) != int) {
	unsigned int address = getVariableAddressFromSymbolTable(data);
	printNot(reg, address, true);
  } else {
	printNot(reg, data, false);
  }
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

void generateSaveValueParam(int reg, int value){
  //TODO
  struct Symbol* function = getLastFunctionFromSymbolTable();
  printSaveValueParam(reg, value);
}

void generateSaveVariableParam(int reg, char* variable){
  //TODO
  struct Symbol* function = getLastFunctionFromSymbolTable();
  int variable_address = getVariableAddressFromTable(variable_id);
  printSaveParam(reg, variable_address);
}

void generateCallFunction(){
  //TODO
  struct Symbol* function = getLastFunctionFromSymbolTable();
  int fun_label = function->label;
  printCallFunction(fun_label);
}

void generateBreak(){
  //TODO
  int label = _getCurrentLabel() + 1;
  printBreak(label);
}

void generateContinue(){
  //TODO
  int label = _getCurrentLabel();
  printContinue(label);
}
