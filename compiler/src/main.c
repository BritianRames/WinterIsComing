#include "symbol-table/SymbolTableManager.h"
#include "code-generator/CodeGeneratorManager.h"

int main() {
    openFile();

    insertVariableInSymbolTable("aaa");

    generateAssignValueToGlobalVariable("aaa", 2);
    insertFunctionSymbolTable("miFuncion");
    openScopeInSymbolTable();
    insertParameterInSymbolTable("Param1");
    insertParameterInSymbolTable("Param2");

    generateFunctionHeaderCode();
    insertVariableInSymbolTable("bbb");
    generateAssignValueToVariableCode("bbb", 2);
    generateFunctionReturnValueCode(3);
    closeScopeInSymbolTable();
    insertVariableInSymbolTable("ccc");
    generateAssignValueToGlobalVariable("ccc", 2);
    //printSymbolTable();
}