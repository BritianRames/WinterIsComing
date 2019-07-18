#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void putLocalVariableValueInR0(int offset);
void putGlobalVariableValueInR0(int address);

void assignValueToGlobalVariable(int address, int value);
void assignValueToLocalVariable(int offset, int value);

void putR0InGlobalVariable(int address);
void putR0InLocalVariable(int offset);

void assignVariableToVariable(int variable_address, int variable_type, int value_address, char value_type);
void assignR0ToVariable(int address, int stackPointer, char variable_type);

int getLocalVariableOffset(int position);

void putOperationResultInR0();

void moveR7Up();
void moveR7Down();