#include "symbol-table/SymbolTableManager.h"
#include "code-generator/CodeGenerator.h"
#include "code-generator/codeGeneratorManager.h"

int main() {
    insertVariableInSymbolTable("pepe");
    // Llamamos al printSymbolTable();
    generateAssignValueToGlobalVariable("pepe", 2);
}
