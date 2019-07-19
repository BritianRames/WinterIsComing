#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void openFile();

void qInitialization();

void jumpMain();

void mainFunction();

void goToExit();

void qEnding();


/*******Stack*********/

void moveR7Up();

void moveR7Down();

void r6EqualsR7();

void putVariableAddressInStack(char *variable_id);

void putVariableValueInStack(char *variable_id);

/********Assignation*********/

void insertVariableValueInStack(char* variable_id);

void putLocalVariableValueInR0(int offset);

void putGlobalVariableValueInR0(int address);

void assignValueToVariable(char* variable_id, int value);

void putR0InGlobalVariable(int address);

void putR0InLocalVariable(int offset);

void assignVariableToVariable(char *variable1_id, char *variable2_id);

void assignR0ToVariable(char* variable_id);

int getLocalVariableOffset(int position);

void declarationGlobalVariable(char* variable_id);

/*********Operations*********/

void putOperationResultInR0();

void product();

void add();

void substract();

void division();

void assign();

/********Registers***********/
void saveRegisters();

void recoverRegisters();

/*********LogCong-ValueValue***********/
void valueEqualsToValue(int val1, int val2);

void valueNotEqualToValue(int val1, int val2);

void valueSmallerThanValue(int val1, int val2);

void valueSmallerEqualsThanValue(int val1, int val2);

void valueGreaterThanValue(int val1, int val2);

void valueGreaterEqualsThanValue(int val1, int val2);

/*********LogCong-ValueVariable***********/
void valueEqualsToVariable(char* variable_id, int val);

void valueNotEqualToVariable(char* variable_id, int val);

void valueSmallerThanVariable(char* variable_id, int val);

void valueSmallerEqualsThanVariable(char* variable_id, int val);

void valueGreaterThanVariable(char* variable_id, int val);

void valueGreaterEqualsThanVariable(char* variable_id, int val);

/*********LogCong-VariableVariable***********/
void variableEqualsToVariable(char* variable1_id, char* variable2_id);

void variableNotEqualsToVariable(char* variable1_id, char* variable2_id);

void variableSmallerThanVariable(char* variable1_id, char* variable2_id);

void variableSmallerEqualsToVariable(char* variable1_id, char* variable2_id);

void variableGraterThanVariable(char* variable1_id, char* variable2_id);

void variableGreaterEqualsThanVariable(char* variable1_id, char* variable2_id);

/*******Not operations**********/

void notValue(int val);

void notVariable(char *variable_id);