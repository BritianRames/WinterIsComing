#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//********************************************************Assignation Code**********************************************************/

void generateAssignValueToStaticVariableCode(char* variable_id, int value){
  //int variable_address = getVariableAddressFromTable(variable_id) -->   use symbol table
  //generateAssignationCode(variable_address, value) --> this function should deal with registers and stack
}

void generateAssignVariableToStaticVariableCode(char* variable_id, char value_id){
  //int variable_address = getVariableAddressFromTable(variable_id) 
  //int value_address = getVariableAddres(value_id)
  //int value = getValueFromStack(value_address)
  //generateAssignationCode(variable_address, value) --> this function should deal with registers and stack
}

void generateAssignValueToDynamicVariableCode(char *variable_id, int value){
  //int variable_address = getVariableAddressFromTable(variable_id) -->   use symbol table
  //generateAssignationCode(variable_address, value);
}

void generateAssignVariableToDynamicVariableCode(char* variable_id, char value_id){
  //int variable_address = getVariableAddressFromTable(variable_id) -->   use symbol table
  //int value_address = getVariableAddres(value_id)
  //int value = getValueFromStack(value_address)
  //generateAssignationCode(variable_address, value)
}

void generateReturnValueCode(int value){
  //int address = getReturnCurrentFunctionAddress()
  //generateAssignationCode(address, value) --> we have a memory position for return value (maybe better a register)
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

void logicalOperate(var a, var b, char* operator){
  
}

void logicalOperate(var a, char* b, char* operator){
  
}

void logicalOperate(char* a, var b, char* operator){
  
}

void logicalOperate(char* a, char* b, char* operator){
  
}