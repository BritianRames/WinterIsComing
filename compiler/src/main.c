#include "symbol-table/SymbolTableManager.h"
#include "code-generator/CodeGeneratorManager.h"

int main() {
    insertVariableInSymbolTable("pepe");
    printVariable("pepe")
    generateAssignValueToGlobalVariable("pepe", 2);
}
