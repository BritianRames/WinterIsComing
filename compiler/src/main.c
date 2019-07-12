#include "symbol-table/SymbolTableManager.h"
#include "code-generator/CodeGeneratorManager.h"

int main() {
    openFile();

    
    insertVariableInSymbolTable("aaa");

    generateAssignValueToGlobalVariable("aaa", 2);
    insertFunctionSymbolTable("miFuncion");
    insertParameterInSymbolTable("Param1");
    insertParameterInSymbolTable("Param2");
    
    generateFunctionHeaderCode();
    generateFunctionReturnValueCode(3);
    printSymbolTable();
}