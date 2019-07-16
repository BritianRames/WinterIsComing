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
void generatePrintJumpMain();
void generateMainFunction();
void generateGoToExit();
void generateQEnding();
void generateAssignValueToVariableCode(char* variable_id, int value);
void generateFunctionHeaderCode();
void generateFunctionReturnValueCode(int value);
void generateFunctionReturnVariableCode(char* variableToReturn);
void generateAssignValueToVariableAssignationCode(char *variable_id, int value);
void generateAssignVariableToVariableCode(char* variable_id, char* value_id);
int _getVariableAddress(char* variable_id);
void generateAssignValueToVariableCode(char *variable_id, int value);
void generatePrintString(char* string);
void generatePrintValue(int value);
void generatePrintVariable(char* id);

/* ARITHMETIC FUNCTIONS */
void generateAddValueToValue(int val1, int val2);
void generateSubtractValueToValue(int val1, int val2);
void generateProductValueToValue(int val1, int val2);
void generateDivisionValueToValue(int val1, int val2);


void generateInsertOnStack(int value);
void generateInsertOnStackVARIABLE(char* id);

void generateAddValue();
void generateAddVariable();
void generateSubstractValue();
void generateSubstractVariable();
void generateProductValue();
void generateProductVariable();
void generateDivisionValue();
void generateDivisionVariable();


void generateAssignOperationResultToVariable(char* id);


/* RELATIONAL FUNCTIONS */
void generateEqualsValueToValue(int val1, int val2);
void generateNotEqualsValueToValue(int val1, int val2);
void generateLessValueToValue(int val1, int val2);
void generateLessEqualsValueToValue(int val1, int val2);
void generateGreaterValueToValue(int val1, int val2);
void generateGreaterEqualsValueToValue(int val1, int val2);


void generateEqualsValueToVariable(char* var, int val);
void generateNotEqualsValueToVariable(char* var, int val);
void generateLessValueToVariable(char* var, int val);
void generateLessEqualsValueToVariable(char* var, int val);
void generateGreaterValueToVariable(char* var, int val);
void generateGreaterEqualsValueToVariable(char* var, int val);

void generateNotEqualsVariableToVariable(char* var1, char* var2);
void generateEqualsVariableToVariable(char* var1, char* var2);
void generateLessVariableToVariable(char* var1, char* var2);
void generateLessEqualsVariableToVariable(char* var1, char* var2);
void generateGreaterVariableToVariable(char* var1, char* var2);
void generateGreaterEqualsVariableToVariable(char* var1, char* var2);

void generateNotVariable(char* var);
void generateNotValue(int val);


/* CLAUSE FUNCTIONS */
int generateHeaderOfClauseInstruction();
void generateGoToInstruction(int label);
void generateLabelInstruction(int label);


/* FUNCTIONS' STUFF */
void generateReturnValue(int value);
void generateReturnVariable(char* variable);
void generateFuntionCall(char* functionToJump, int* parameters);

/* ARRAY MANAGEMENT */
void generateCreateArray(char* var);
void generateArrayAssignValue(char* var, int pos, int val);
void generateArrayAssignVariable(char* var1, int pos, char* var2);
void generateArrayAssignArray(char* var1, int pos1, char* var2, int pos2);
