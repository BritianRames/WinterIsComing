#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../symbol-table/SymbolTableManager.h"
//********************************************************Assignation Code**********************************************************/

void generateAssignValueToGlobalVariable(char* variable_id, int value){
  int variable_address = getVariableAddressFromSymbolTable(variable_id);
  generateAssignation(variable_address, value);
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



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void substract(int a, int b){
  
}

void add(int a, int b){

}

void multiply(int a, int b){

}

void divide(int a, int b){

}

void returnValue(int value){

}

void returnVariable(char* variable){

}

void printLineJump(){

}

void printVariable(char* variable){

}

void printText(char* text){

}

void breakCode(){

}

void startIf(){
  
}

void startElse(){

}

void startWhile(){

}

void startControlStructure(){
  //Including --> (
}

void logicalOperate(int a, int b, char* operator){
  
}

void logicalOperate(int a, char* b, char* operator){
  
}

void logicalOperate(char* a, int b, char* operator){
  
}

void logicalOperate(char* a, char* b, char* operator){
  
}