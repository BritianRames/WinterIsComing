#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void openFile();
void printGlobalVariableValueAssignation(int address, int value);
void printGlobalVariableVariableAsignation(int variable_address, int value_address);
void printUpdateFramePointer();
void printUpdateStackPointer(int offset);
void printFunctionLabel(int label);
void printCodeToAssignParametersValueInStack(int numberOfParameters, int stackPointer);
void printReturnValue(int stackPointer, int valueToReturn);
void printReturnVariable(int stackPointer, int variableAddress);
void printRecoverRegistersValue(int registerFramePointer);
void printSaveRegistersValue(int registerFramePointer);
void printCodeToAssignValueToVariable(int address, int value);
void printCodeToAssignVariableToVariable(int address, int value_address);
void printPrintStringCode(char* string);
void printPrintValueCode(int value);
void printPrintVariableCode(int address);