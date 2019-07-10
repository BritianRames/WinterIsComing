#include "symbol-table/SymbolTableManager.h"
#include "code-generator/CodeGenerator.h"
#include "code-generator/codeGeneratorManager.h"

int main() {
    insertVariableInSymbolTable("pepe");
    printVariable("pepe")
    generateAssignValueToGlobalVariable("pepe", 2);
}
