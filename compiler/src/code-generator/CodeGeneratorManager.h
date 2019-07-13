#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void generateAssignValueToGlobalVariable(char* variable_id, int value);
void generateFunctionHeaderCode();
void generateAssignVariableToGlobalVariableCode(char* variable_id, char value_id);
void generateFunctionReturnValueCode(int value);
void generateFunctionReturnVariableCode(char* variableToReturn);
void generateAssignValueToVariableAssignationCode(char *variable_id, int value);
void generateAssignVariableToVariableCode(char* variable_id, char value_id);
int _getVariableAddress(char* variable_id);
void generateAssignValueToVariableCode(char *variable_id, int value);
void generatePrintString(char* string);
void generatePrintValue(int value);
void generatePrintVariable(char* id);