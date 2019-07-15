#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void openFile();
void printQInitialization();
void printGlobalDefinitionAreaEnding();
void printMainFunction();
void printGoToExit();
void printQEnding();
void printUpdateFramePointer();
void printUpdateStackPointer(int offset);
void printFunctionLabel(int label);
void printCodeToAssignParametersValueInStack(int numberOfParameters, int stackPointer);
void printReturnValue(int stackPointer, int valueToReturn);
void printReturnVariable(int stackPointer, int variableAddress);
void printRecoverRegistersValue(int registerFramePointer);
void printSaveRegistersValue(int lastRegisterPointer);
void printCodeToAssignValueToVariable(int address, int value);
void printCodeToAssignVariableToVariable(int address, int value_address);
void printPrintStringCode(char* string);
void printPrintValueCode(int value);
void printPrintVariableCode(int address);
void printRecoverStack(int numberOfParameters);
void _printSaveParameters(int numberOfParameters);

/* REGISTRY MANAGEMENT FUNCTIONS */
void printPushReg(int r);
void printPopReg(int r);

/* Assignation */
void printCodeToAssignVariableToRegister(int reg, int addr);
void printCodeToAssignValueToRegister(int reg, int val);
void printCodeToAssignRegisterToVariable(int reg, int addr);
void printCodeToAssignFunctionResultToVariable(int address);

/* ARITHMETICAL FUNCTIONS */
void printAddValueToValue(int val1, int val2);
void printSubtractValueToValue(int val1, int val2);
void printProductValueToValue(int val1, int val2);
void printDivisionValueToValue(int val1, int val2);
void printCodeAssignOperationResultToVariable(int addr);

void printAddValueToVariable(int address, int val);
void printSubtractValueToVariable(int address, int val);
void printMultiplyValueToVariable(int address, int val);
void printDivideValueToVariable(int address, int val);


void printAddVariableToVariable(int address1, int address2);
void printSubtractVariableToVariable(int address1, int address2);
void printMultiplyVariableToVariable(int address1, int address2);
void printDivideVariableToVariable(int address1, int address2);

void generateFunctionCall(char* currentFunction, char* nextFunction);
void printRecoverRegisters();
void printRecoverStackPointer(int offset);
void printPutParametersInRegisters(int numberOfParameters, int* parameters);


/* IF CLAUSE FUNCTIONS */
void printHeaderOfIfInstruction(int reg, int cond_value, int else_label);
void printGoToInstruction(int label);
void printLabelInstruction(int label);