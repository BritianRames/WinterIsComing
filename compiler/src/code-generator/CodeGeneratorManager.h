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