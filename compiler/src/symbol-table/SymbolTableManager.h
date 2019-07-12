#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Symbol
{
    char *id;
    int address; //absolute or relative
    char type;
    int scope;
    int label;
    int numberOfParameters;
    int numberOfLocalVariables;
    struct Symbol *previousSymbol;
    struct Symbol *nextSymbol;
};

void insertVariableInSymbolTable(char *id);
void insertParameterInSymbolTable(char *id);
void insertFunctionInSymbolTable(char *id);

bool _existSymbolInSymbolTable(struct Symbol *symbol);
void _linkSymbolToSymbolTable(struct Symbol *symbol);
void _incrementNumberOfLocalVariablesAndParameters();
bool _haveSameType(struct Symbol* symbol1, struct Symbol* symbol2);

int _getRelativeAddressFromSymbolTable();
int _getStaticAddressFromSymbolTable();

void openScopeInSymbolTable();
void closeScopeInSymbolTable();
void _removeLocalVariablesFromSymbolTable();
int _getCurrentLabel();
int _getNextLabel();
void printSymbolTable();

int getVariableAddressFromSymbolTable(char* id);
struct Symbol* getLastFunctionFromSymbolTable();
