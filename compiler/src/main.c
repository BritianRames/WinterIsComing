#include "symbol-table/SymbolTableManager.h"
#include "code-generator/CodeGeneratorManager.h"

int main() {
    openFile();
    generateQInitialization();   // Se inicializa sección del código Q
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
    generateMainFunction(); // Creamos scope de función Main
    generatePrintString("\\nhoskdjnfkndfln<dlsanalnslanla\\n");
    generatePrintValue(4);
    generatePrintVariable("ccc");
    generateGoToExit(); // Este código debe ir siempre al final del Main para indicar
                        // para saltar a la rutina de fin de programa
    generateQEnding();  // Flag de final de código Q
}