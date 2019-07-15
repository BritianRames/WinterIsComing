#include "../symbol-table/SymbolTableManager.h"
#include "CodeGeneratorManager.h"
#include "StackManager.h"
#include "CodePrinter.h"

/* GENERAL STUFF */
void generateQInitialization() {
    printQInitialization();
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
  printPrintStringCode(string);
}

void generatePrintValue(int value){
  printPrintValueCode(value);
}

void generatePrintVariable(char* id){
  int address = _getVariableAddress(id);
  printPrintVariableCode(address);
  printf("----------------->0x%x<----------------", address);
}

/* ARITHMETIC FUNCTIONS */

void generateInsertOnStack(int value){
  int address = getCurrentStackPointer() - 4 * getLastFunctionFromSymbolTable()->numberOfLocalVariables - 4 * getNumberOperators() - 4;
  printf(",,,,,,,,,,");
  printInsertOnStack(address, value);
  addOneToNumberOperators(); //¿ANTES O DESPUES?
}

void generateInsertOnStackVARIABLE(char* id){
  int address = getCurrentStackPointer() - 4 * getLastFunctionFromSymbolTable()->numberOfLocalVariables - 4 * getNumberOperators() - 4;
  printf(",,,,,,,,,,");
  int var_address = getVariableAddressFromSymbolTable(id);
  printInsertOnStackVariable(address, var_address);
  addOneToNumberOperators(); //¿ANTES O DESPUES?
}

void generateAddValue(){
  printf("...............");
  int address = getCurrentStackPointer() - 4 * getLastFunctionFromSymbolTable()->numberOfLocalVariables - 4 * getNumberOperators();
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
    int address = getCurrentStackPointer() - 4 * getLastFunctionFromSymbolTable()->numberOfLocalVariables - 4;
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
    printCreateArray(_getNextLabel(), _getVariableAddress(var), symbol->array_size);
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
