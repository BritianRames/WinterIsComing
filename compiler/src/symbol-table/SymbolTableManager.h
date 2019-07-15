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

void insertVariableInSymbolTable(char* id);
void insertParameterInSymbolTable(char *id);
void insertFunctionSymbolTable(char *id);
void _linkSymbolToSymbolTable(struct Symbol* symbol);
void _incrementNumberOfLocalVariablesAndParameters();
int _getNextLocalVariableAddressFromSymbolTable();
int _getNextParametersAddressFromSymbolTable();
int _getNextStaticAddressFromSymbolTable();
bool _haveSameType(struct Symbol* symbol1, struct Symbol* symbol2);
bool _existSymbolInSymbolTable(struct Symbol* symbol);
void _removeLocalVariablesFromSymbolTable();
int _getNextLabel();
void openScopeInSymbolTable();
void closeScopeInSymbolTable();
int getVariableAddressFromSymbolTable(char* id);
struct Symbol* getLastFunctionFromSymbolTable();
void printSymbolTable();
struct Symbol* getVariableFromSymbolTable(char* id);
int getCurrentScopeFromSymbolTable();
struct Symbol* getFunctionFromSymbolTable(char* id);