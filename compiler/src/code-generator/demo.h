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

void printR0();

void printString(char* str);

void putValueInR0(int value);

void putVariableInR0(char *variable_id);

void putOperationResultInR0();

/********Assignation*********/

void insertCharInStack(value);

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
void logicalValueToValue(int val1, int val2, char* logic);

/*********LogCong-ValueVariable***********/
void logicalVariableToValue(char* variable_id, int val, char* logic);

/*********LogCong-VariableVariable***********/
void logicalVariableToVariable(char* variable1_id, char* variable2_id, char* logic);

/*******Not operations**********/

void notValue(int val);

void notVariable(char *variable_id);

int printHeaderOfClauseInstruction();

void printLabelInstruction(int label);

int printGoToFinalEstructureElse();
void generateGoToWhile(int etiqueta);

/*******Functions************/
void functionReturn();
void functionCall(char *funciton_id);
void function(char *name);

