#include "SymbolTableManager.h"
#include "../code-generator/StackManager.h"

struct Symbol* firstSymbol;
struct Symbol* lastSymbol;
struct Symbol* lastFunc;
int tableSize = 0;
int currentScope = 0;
int lastLabel = 0;
int currentStatCodeSectionNumber = 0;

void insertArrayInSymbolTable(char* id, int size) {
    struct Symbol* symbol = malloc(sizeof(struct Symbol));
    symbol->id = malloc(sizeof(char) * strlen(id));
    symbol->nextSymbol = NULL;
    symbol->label = NULL;
    symbol->numberOfLocalVariables = NULL;
    symbol->scope = currentScope;
    symbol->array_size = 4*size;
    symbol->type = symbol->scope == 0 ? 'g' : 'l';
    symbol->address = symbol->type == 'g' ? _getNextStaticAddressFromSymbolTable() : _getNextLocalVariableAddressFromSymbolTable();

    strcpy(symbol->id, id);

    _existSymbolInSymbolTable(symbol) ? printf("Error") : _linkSymbolToSymbolTable(symbol);
}

void insertVariableInSymbolTable(char* id){
    // debug con prints
    struct Symbol* symbol = malloc(sizeof(struct Symbol));
    symbol->id = malloc(sizeof(char) * strlen(id));
    symbol->nextSymbol = NULL;
    symbol->label = NULL;
    symbol->array_size = NULL;
    symbol->numberOfLocalVariables = NULL;
    symbol->scope = currentScope;
    symbol->type = symbol->scope == 0 ? 'g' : 'l';
    symbol->address = symbol->type == 'g' ? _getNextStaticAddressFromSymbolTable() : _getNextLocalVariableAddressFromSymbolTable();

    strcpy(symbol->id, id);

    _existSymbolInSymbolTable(symbol) ? printf("Error") : _linkSymbolToSymbolTable(symbol);

}

void insertParameterInSymbolTable(char *id){
    struct Symbol* symbol = malloc(sizeof(struct Symbol));

    symbol->id = malloc(sizeof(char) * strlen(id));
    symbol->nextSymbol = NULL;
    symbol->label = NULL;
    symbol->array_size = NULL;
    symbol->numberOfLocalVariables = NULL;
    symbol->scope = currentScope;
    symbol->type = 'p';
    symbol->address = _getNextParametersAddressFromSymbolTable();

    strcpy(symbol->id, id);

    _existSymbolInSymbolTable(symbol) ? printf("Error") : _linkSymbolToSymbolTable(symbol);

}

void insertFunctionSymbolTable(char *id){
    if(strcmp(id,"main") == 0){
        struct Symbol* symbol = malloc(sizeof(struct Symbol));

        symbol->id = malloc(sizeof(char) * strlen(id));
        symbol->nextSymbol = NULL;
        symbol->label = 0;
        symbol->numberOfLocalVariables = 0;
        symbol->numberOfParameters = 0;
        symbol->type = 'f';
        symbol->address = NULL;
        symbol->scope = 0;

        strcpy(symbol->id, id);

        _existSymbolInSymbolTable(symbol) ? printf("Error") : _linkSymbolToSymbolTable(symbol);
    } else {
        struct Symbol* symbol = malloc(sizeof(struct Symbol));
    
        symbol->id = malloc(sizeof(char) * strlen(id));
        symbol->nextSymbol = NULL;
        symbol->array_size = NULL;
        symbol->label = _getNextLabel();
        symbol->numberOfLocalVariables = 0;
        symbol->numberOfParameters = 0;
        symbol->type = 'f';
        symbol->address = NULL;
        symbol->scope = 0;

        strcpy(symbol->id, id);

        _existSymbolInSymbolTable(symbol) ? printf("Error") : _linkSymbolToSymbolTable(symbol);
    }


}

void _linkSymbolToSymbolTable(struct Symbol* symbol) {
    if(tableSize == 0) firstSymbol = symbol;
    else {
        lastSymbol->nextSymbol = symbol;
        symbol->previousSymbol = lastSymbol;
    }

    if(symbol->type == 'f') lastFunc = symbol;
    lastSymbol = symbol;
    _incrementNumberOfLocalVariablesAndParameters();
    tableSize++;
}

void _incrementNumberOfLocalVariablesAndParameters(){
    if(lastSymbol->type == 'p') lastFunc->numberOfParameters++;
    else if(lastSymbol->type == 'l') lastFunc->numberOfLocalVariables++;
}

int _getNextLocalVariableAddressFromSymbolTable(){
    lastFunc->numberOfLocalVariables++;
    return (lastFunc->numberOfLocalVariables);
}

int _getNextParametersAddressFromSymbolTable(){
    lastFunc ->numberOfParameters++;
    return (lastFunc->numberOfParameters + 1);
}

int _getNextStaticAddressFromSymbolTable() {
    return getNextStackPointer();
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
    lastLabel++;
    return lastLabel;
}

void openScopeInSymbolTable(){
    currentScope++;
}

void closeScopeInSymbolTable(){
    _removeLocalVariablesFromSymbolTable();
    currentScope--;
}

int getVariableAddressFromSymbolTable(char* id){
    struct Symbol* currentSymbol = lastSymbol;
    for(int i = tableSize; i > 0; i--){
        if(strcmp(currentSymbol->id, id) == 0 && (currentSymbol->type == 'g' | currentSymbol->type =='l')){
            return currentSymbol->address;
        }
        currentSymbol = currentSymbol->previousSymbol;
    }
    printf("ERROR\n");
    return -1;
}

int getStatSectionNumber() {
  return currentStatCodeSectionNumber;
}

int getCodeSectionNumber() {
  return currentStatCodeSectionNumber++;
}

char getTypeFromSymbol(char* id) {
    struct Symbol* currentSymbol = lastSymbol;
    for(int i = tableSize; i > 0; i--){
        if(strcmp(currentSymbol->id, id) == 0 && (currentSymbol->type == 'g' | currentSymbol->type =='l')){
            return currentSymbol->type;
        }
        currentSymbol = currentSymbol->previousSymbol;
    }
    printf("ERROR\n");
    return -1;
}

struct Symbol* getVariableFromSymbolTable(char* id){
    struct Symbol* currentSymbol = lastSymbol;
    printf("symbol: %s, %c\n", currentSymbol->id, currentSymbol->type);
    for(int i = tableSize; i > 0; i--){
        if(strcmp(currentSymbol->id, id) == 0 && (currentSymbol->type == 'g' | currentSymbol->type =='l')){
            return currentSymbol;
        }
        currentSymbol = currentSymbol->previousSymbol;
    }
    return -1;
}

struct Symbol* getFunctionFromSymbolTable(char* id){
    struct Symbol* currentSymbol = lastSymbol;
    printf("symbol (f): %s, %c\n", currentSymbol->id, currentSymbol->type);
    for(int i = tableSize; i > 0; i--){
        if(strcmp(currentSymbol->id, id) == 0 && (currentSymbol->type == 'f')){
            return currentSymbol;
        }
        currentSymbol = currentSymbol->previousSymbol;
    }
    return -1;
}

struct Symbol* getLastFunctionFromSymbolTable(){
    return lastFunc;
}

void printSymbolTable(){
    struct Symbol* currentSymbol = firstSymbol;
    for(int i = 0; i < tableSize; i++){
        printf("-----------SYMBOL (SIZE %d) -> %d------------\n",tableSize, i);
        printf("ADDRESS -> %d\n",currentSymbol->address);
        printf("ID -> %s\n",currentSymbol->id);
        printf("LABEL -> %d\n",currentSymbol->label);
        printf("NLOCALV -> %d\n",currentSymbol->numberOfLocalVariables);
        printf("NPARAM -> %d\n",currentSymbol->numberOfParameters);
        printf("SCOPE -> %d\n",currentSymbol->scope);
        printf("TYPE -> %c\n",currentSymbol->type);
        printf("--------------------------------------------\n",i);
        currentSymbol = currentSymbol->nextSymbol;
    }
}

int getCurrentScopeFromSymbolTable(){
    return currentScope;
}
