#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "SymbolTableManager.h"

struct Symbol* firstSymbol;
struct Symbol* lastSymbol;
struct Symbol* lastFunc;
int tableSize = 0;

int tablePointer = 12000; //default Stackpointer R7
int currentScope = 0;
int lasLabel = 0;

void insertVariableInSymbolTable(char *id){
    struct Symbol* symbol = malloc(sizeof(struct Symbol));

    symbol->id = malloc(sizeof(char) * strlen(id));
    symbol->nextSymbol = NULL;
    symbol->label = NULL;
    symbol->numberOfLocalVariables = NULL;
    symbol->scope = currentScope;
    symbol->type = symbol->scope == 0 ? 'g' : 'l';
    symbol->address = symbol->type == 'g' ? _getStaticAddressFromSymbolTable() : _getRelativeAddressFromSymbolTable();

    strcpy(symbol->id, id);

    _existSymbolInSymbolTable(symbol) ? printf("Error") : _linkSymbolToSymbolTable(symbol);

}

void insertParameterInSymbolTable(char *id){
    struct Symbol* symbol = malloc(sizeof(struct Symbol));

    symbol->id = malloc(sizeof(char) * strlen(id));
    symbol->nextSymbol = NULL;
    symbol->label = NULL;
    symbol->numberOfLocalVariables = NULL;
    symbol->scope = currentScope;
    symbol->type = 'p';
    symbol->address = _getRelativeAddressFromSymbolTable();

    strcpy(symbol->id, id);

    _existSymbolInSymbolTable(symbol) ? printf("Error") : _linkSymbolToSymbolTable(symbol);

}

void insertFunctionSymbolTable(char *id){
    struct Symbol* symbol = malloc(sizeof(struct Symbol));
    
    symbol->id = malloc(sizeof(char) * strlen(id));
    symbol->nextSymbol = NULL;
    symbol->label = _getNextLabel();
    symbol->numberOfLocalVariables = 0;
    symbol->numberOfParameters = 0;
    symbol->type = 'f';
    symbol->address = NULL;
    symbol->scope = 0;

    strcpy(symbol->id, id);

    _existSymbolInSymbolTable(symbol) ? printf("Error") : _linkSymbolToSymbolTable(symbol);
    
}

void _linkSymbolToSymbolTable(struct Symbol* symbol){
    _incrementNumberOfLocalVariablesAndParameters();
    if(tableSize == 0) firstSymbol = symbol;
    else {
        lastSymbol->nextSymbol = symbol;
        symbol->previousSymbol = lastSymbol;
    }
    
    if(symbol->type == "f") lastFunc = symbol;
    lastSymbol = symbol; 
    tableSize++;
}

void _incrementNumberOfLocalVariablesAndParameters(){
    if(lastSymbol->type == 'p') lastFunc->numberOfParameters++;
    else if(lastSymbol->type == 'l') lastFunc->numberOfLocalVariables++;
}

int _getRelativeAddressFromSymbolTable(){
    return (lastFunc->numberOfLocalVariables + lastFunc->numberOfParameters + 1) * 4;
}

int _getStaticAddressFromSymbolTable() {
    tablePointer = tablePointer - 4;
    return tablePointer;
}

bool _haveSameType(struct Symbol* symbol1, struct Symbol* symbol2){
    if(symbol1->type == symbol2->type) return true;
    if(symbol1->type == 'l' && symbol2->type == 'p') return true;
    if(symbol1->type == 'p' && symbol2->type == 'l') return true;
    return false;
}

bool _existSymbolInSymbolTable(struct Symbol* symbol){
    struct Symbol* currentSymbol = lastSymbol;
    for(int i = tableSize; i > 0; i--){
        if(_haveSameType(symbol, currentSymbol) && currentSymbol->scope == symbol->scope && (strcmp(currentSymbol->id, symbol->id) == 0)){
            return true;
        }
        currentSymbol = currentSymbol->previousSymbol;
    }
    return false;
}

void _removeLocalVariablesFromSymbolTable(){
    struct Symbol* currentSymbol = lastSymbol;
    for(int i = tableSize; i > 0; i--){
        if(currentSymbol->scope == currentScope && currentSymbol->type == 'l' ){
            currentSymbol->previousSymbol->nextSymbol = NULL;
            lastSymbol = currentSymbol->previousSymbol;            
            currentSymbol = currentSymbol->previousSymbol;
            tableSize--;
        } else break;
    }
}

int _getNextLabel(){
    lasLabel++;
    return lasLabel;
}

void openScopeInSymbolTable(){
    currentScope++;
}

void closeScopeInSymbolTable(){
    _removeLocalVariablesFromSymbolTable();
    currentScope--;
}