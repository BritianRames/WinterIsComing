#include "../symbol-table/SymbolTableManager.h"
#include "CodeGeneratorManager.h"
#include "StackManager.h"
#include "CodePrinter.h"

#include <string.h>

/* GENERAL STUFF */
void generateQInitialization() {
    int stat = getStatSectionNumber();
    int code = getCodeSectionNumber();
    printQInitialization(stat,code);
}

void generatePrintJumpMain(){
    printJumpMain();
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
  int address = getNextStackPointer();
  updateStackPointer(strlen(string));
  printf(string);
  int label = _getNextLabel();
  int stat = getStatSectionNumber();
  int code = getCodeSectionNumber();
  printPrintStringCode(string,address,label,stat,code);
}

void generatePrintValue(int value){
  int label = _getNextLabel();
  int stat = getStatSectionNumber();
  int code = getCodeSectionNumber();
  int print_address = getNextStackPointer();
  updateStackPointer(4);
  printPrintValueCode(print_address,value,label,stat,code);
}

void generatePrintVariable(char* id){
  struct Symbol* symbol = getVariableFromSymbolTable(id);
  int label = _getNextLabel();
  int stat = getStatSectionNumber();
  int code = getCodeSectionNumber();
  if (symbol->array_size == NULL) {
    int print_address = getNextStackPointer();
    updateStackPointer(4);
    printPrintVariableCode(print_address,symbol->address,label,stat,code);
  } else {
    generatePrintString("[");
    for (int i = 0; i < symbol->array_size; i = i + 4) {
      generatePrintArrayAccess(id, i);
	  if (i == symbol->array_size - 4) {
		generatePrintString("]");
	  } else {
	    generatePrintString(", ");
	  }
	}
  }
  printf("----------------->0x%x<----------------", symbol->address);
}

void generatePrintArrayAccess(char* id, int pos) {
  int label = _getNextLabel();
  int stat = getStatSectionNumber();
  int code = getCodeSectionNumber();
  int print_address = getNextStackPointer();
  updateStackPointer(4);
  struct Symbol* symbol = getVariableFromSymbolTable(id);
  int address = symbol->address - 4*pos;
  printPrintValueCode(print_address,address,label,stat,code);
}

/* ARITHMETIC FUNCTIONS */

void generateInsertOnStack(int value){
  addOneToNumberOperators(); //¿ANTES O DESPUES?
  int address = getCurrentStackPointer();
  printf(",,,,,,,,,,");
  printInsertOnStack(address, value);
}

void generateInsertOnStackVARIABLE(char* id){
  printf(",,,,,,,,,,");
  addOneToNumberOperators(); //¿ANTES O DESPUES?
  int var_address = getVariableAddressFromSymbolTable(id);
  int address = getCurrentStackPointer();
  updateStackPointer(4);
  printInsertOnStackVariable(address, var_address);
}

void generateAddValue(){
  printf("...............");
  int address = getCurrentStackPointer() - 4 * getNumberOperators();
  printf("...............");
  printAddValue(address);
  minusOneToNumberOperators();
}
//void generateAddVariable(){
//  printAddVariable(_getVariableAddress(id));
//}
//
//
void generateSubstractValue(){
  int address = getCurrentStackPointer() - 4 * getLastFunctionFromSymbolTable()->numberOfLocalVariables - 4 * getNumberOperators();
  printf("...............");
  printSubstractValue(address);
  minusOneToNumberOperators();
}
//void generateSubstractVariable(){
//  printSubstractVariable(_getVariableAddress(id));
//}
//
void generateProductValue(){
  int address = getCurrentStackPointer() - 4 * getLastFunctionFromSymbolTable()->numberOfLocalVariables - 4 * getNumberOperators();
  printf("...............");
  printProductValue(address);
  minusOneToNumberOperators();
}
//void generateProductVariable(){
//  printProductVariable(_getVariableAddress(id));
//}
//
void generateDivisionValue(){
  int address = getCurrentStackPointer() - 4 * getLastFunctionFromSymbolTable()->numberOfLocalVariables - 4 * getNumberOperators();
  printf("...............");
  printDivisionValue(address);
  minusOneToNumberOperators();
}
//void generateDivisionVariable(char* id){
//  printDivisionVariable(_getVariableAddress(id));
//}
//
void generateAssignOperationResultToVariable(char* id) {
    int address = getCurrentStackPointer() - 4;
    printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAA%dAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n",address);
    printCodeToAssignOperationResultToVariable(_getVariableAddress(id), address);
}
//
int _getVariableAddress(char* variable_id){
  struct Symbol* variable = getVariableFromSymbolTable(variable_id);
  if(variable == -1) printf("\nElement not found \n");
  else if (variable->type == 'g') return variable->address;
  else return getCurrentStackPointer() - variable->address * 4;
  return 1000;
}


/* RELATIONAL FUNCTIONS */

void generateEqualsValueToValue(int val1, int val2){
    printEqualsValueToValue(val1, val2);
}

void generateNotEqualsValueToValue(int val1, int val2){
    printNotEqualsValueToValue(val1, val2);
}

void generateLessValueToValue(int val1, int val2){
    printLessValueToValue(val1, val2);
}

void generateLessEqualsValueToValue(int val1, int val2){
    printLessEqualsValueToValue(val1, val2);
}

void generateGreaterValueToValue(int val1, int val2){
    printGreaterValueToValue(val1, val2);
}

void generateGreaterEqualsValueToValue(int val1, int val2){
    printGreaterEqualsValueToValue(val1, val2);
}


void generateEqualsValueToVariable(char* var, int val){
    printEqualsValueToVariable(_getVariableAddress(var), val);
}

void generateNotEqualsValueToVariable(char* var, int val){
    printNotEqualsValueToVariable(_getVariableAddress(var), val);
}

void generateLessValueToVariable(char* var, int val){
    printLessValueToVariable(_getVariableAddress(var), val);
}

void generateLessEqualsValueToVariable(char* var, int val){
    printLessEqualsValueToVariable(_getVariableAddress(var), val);
}

void generateGreaterValueToVariable(char* var, int val){
    printGreaterValueToVariable(_getVariableAddress(var), val);
}

void generateGreaterEqualsValueToVariable(char* var, int val){
    printGreaterEqualsValueToVariable(_getVariableAddress(var), val);
}

void generateNotEqualsVariableToVariable(char* var1, char* var2){
    printNotEqualsVariableToVariable(_getVariableAddress(var1), _getVariableAddress(var2));
}

void generateEqualsVariableToVariable(char* var1, char* var2){
    printEqualsVariableToVariable(_getVariableAddress(var1), _getVariableAddress(var2));
}

void generateLessVariableToVariable(char* var1, char* var2){
    printLessVariableToVariable(_getVariableAddress(var1), _getVariableAddress(var2));
}

void generateLessEqualsVariableToVariable(char* var1, char* var2){
    printLessEqualsVariableToVariable(_getVariableAddress(var1), _getVariableAddress(var2));
}

void generateGreaterVariableToVariable(char* var1, char* var2){
    printGreaterVariableToVariable(_getVariableAddress(var1), _getVariableAddress(var2));
}

void generateGreaterEqualsVariableToVariable(char* var1, char* var2){
    printGreaterEqualsVariableToVariable(_getVariableAddress(var1), _getVariableAddress(var2));
}

void generateNotVariable(char* var){
    printNotVariable(_getVariableAddress(var));
}

void generateNotValue(int val){
    printNotValue(val);
}



/* CLAUSE FUNCTIONS */
int generateHeaderOfClauseInstruction() {
    int label = _getNextLabel();
    printHeaderOfClauseInstruction(label);
    return label;
}

void generateGoToInstruction(int label) {
    printGoToInstruction(label);
}

void generateLabelInstruction(int label) {
    printLabelInstruction(label);
}



/* ARRAY MANAGEMENT */
void generateCreateArray(char* var) {
    struct Symbol* symbol = getVariableFromSymbolTable(var);
    printCreateArray(symbol->address, symbol->array_size);
	updateStackPointer(symbol->array_size);
}

void generateArrayAssignValue(char* var, int pos, int val) {
    printArrayAssignValue(_getVariableAddress(var), pos, val);
}
void generateArrayAssignVariable(char* var1, int pos, char* var2) {
    printArrayAssignVariable(_getVariableAddress(var1), pos, _getVariableAddress(var2));
}

void generateArrayAssignArray(char* var1, int pos1, char* var2, int pos2){
    printArrayAssignArray(_getVariableAddress(var1), pos1, _getVariableAddress(var2), pos2);
}

void generatePrintArray(char* var){
	//TODO
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
