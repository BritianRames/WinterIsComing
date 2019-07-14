#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void openFile();
int generateAssignation(int address, int value);
void printSaveValueParam(int reg, int value);
void printSaveVariableParam(int reg, int variable);
void printCalFunction(int fun_label);
void printBreak(int label);
void printContinue(int label);
void printPrintJumper();
