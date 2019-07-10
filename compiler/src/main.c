#include "symbol-table/SymbolTableManager.h"
#include "code-generator/CodeGeneratorManager.h"
#include "code-generator/CodeGeneratorManager.c"

int main() {
    insertVariableInSymbolTable("pepe");
    printVariable("pepe");
    generateAssignValueToGlobalVariable("pepe", 2);
}
