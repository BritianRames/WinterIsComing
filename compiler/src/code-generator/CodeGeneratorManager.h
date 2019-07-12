#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void generateAssignValueToGlobalVariable(char* variable_id, int value);
void generateFunctionHeaderCode();
void generateAssignVariableToGlobalVariableCode(char* variable_id, char value_id);
void generateFunctionReturnValueCode(int value);
void generateFunctionReturnVariableCode(char* variableToReturn);
void generateAssignValueToLocalVariableAssignationCode(char *local_variable_id, int value);
void generateAssignLocalVariableToLocalVariableCode(char* local_variable_id, char value_id);
void printReturnVariable();

#include "../symbol-table/SymbolTableManager.h"
#include "CodeGeneratorManager.h"
#include "StackManager.h"
#include "CodePrinter.h"

void generateAssignValueToGlobalVariable(char* variable_id, int value);
void generateFunctionHeaderCode();
void generateAssignVariableToGlobalVariableCode(char* variable_id, char value_id);
void generateFunctionReturnValueCode(int value);
void generateFunctionReturnVariableCode(char* variableToReturn);
void generateAssignValueToVariableAssignationCode(char *variable_id, int value);
void generateAssignVariableToVariableCode(char* variable_id, char value_id);
int _getVariableAddress(char* variable_id);