#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_REG 4

/* REGISTRIES MANAGEMENT */
int get_reg();
void free_reg(int r);
void lock_reg(int r);
bool is_used(int r);
void push_reg(int r);
void pop_reg(int r);


void generateQInitialization();
void generateGlobalDefinitionAreaEnding();
void generateMainFunction();
void generateGoToExit();
void generateQEnding();
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
void generateAddValueToValue(int val1, int val2);
void generateSubtractValueToValue(int val1, int val2);
void generateProductValueToValue(int val1, int val2);
void generateDivisionValueToValue(int val1, int val2);

void generateAddValueToVariable(char* variable, int val);
void generateSubtractValueToVariable(char* variable, int val);
void generateProductValueToVariable(char* variable, int val);
void generateDivisionValueToVariable(char* variable, int val);

void generateAddVariableToVariable(char* variable1, char* variable2);
void generateSubtractVariableToVariable(char* variable1, char* variable2);
void generateProductVariableToVariable(char* variable1, char* variable2);
void generateDivisionVariableToVariable(char* variable1, char* variable2);

void generateAssignOperationResultToVariable(char* id);

void generateReturnValue(int value);
void generateReturnVariable(char* variable);

void generateFunctionCall();