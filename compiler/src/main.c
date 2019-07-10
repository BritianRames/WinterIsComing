#include "symbol-table/SymbolTableManager.h"
#include "code-generator/CodeGeneratorManager.h"

int main() {
    openFile();
    printSymbolTable();
    insertVariableInSymbolTable("aaa");
    printSymbolTable();
    generateAssignValueToGlobalVariable("aaa", 2);
}
