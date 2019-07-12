#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void generateAssignValueToGlobalVariable(char* variable_id, int value);

void generateFunctionHeaderCode();

void generateFunctionReturnValueCode(int value);

void generateFunctionReturnVariableCode(char* variableToReturn);

void generateAssignVariableToGlobalVariableCode(char* variable_id, char value_id);

void generateAssignValueToLocalVariableCode(char *local_variable_id, int value);

void generateAssignVariableToLocalVariableCode(char* variable_id, char value_id);

void generateReturnValueCode(int value);

void generateReturnVariableCode(char* variable);