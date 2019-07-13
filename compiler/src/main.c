#include "symbol-table/SymbolTableManager.h"
#include "code-generator/CodeGeneratorManager.h"

int main() {
    openFile();
    insertVariableInSymbolTable("aaa");

    printCodeToAssignValueToVariable("aaa", 2);
    insertFunctionSymbolTable("miFuncion");
    openScopeInSymbolTable();
    insertParameterInSymbolTable("Param1");
    insertParameterInSymbolTable("Param2");

    generateFunctionHeaderCode();
    insertVariableInSymbolTable("bbb");
    printCodeToAssignValueToVariable("bbb", 2);
    generateFunctionReturnValueCode(3);
    closeScopeInSymbolTable();
    insertVariableInSymbolTable("ccc");
    printCodeToAssignValueToVariable("ccc", 2);
    //printSymbolTable();
}