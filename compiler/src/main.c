#include "symbol-table/SymbolTableManager.h"
#include "code-generator/CodeGeneratorManager.h"
#include <stdio.h>
extern FILE *yyin;
extern int yyparse();
int main(int argc, char** argv) {
    openFile();
    if (argc>1) yyin=fopen(argv[1],"r");
    yyparse();
    //printSymbolTable();




    //generateGoToExit(); // Este código debe ir siempre al final del Main para indicar para saltar a la rutina de fin de programa
    //closeScopeInSymbolTable();

    //generateQEnding();  // Flag de final de código





    //generateQInitialization();   // Se inicializa sección del código Q
//
    //insertVariableInSymbolTable("aaa");
    //insertVariableInSymbolTable("bbb");
//
    //generateAssignValueToGlobalVariable("aaa", 5);

//    insertVariableInSymbolTable("aaa");
    //generateAssignValueToGlobalVariable("bbb", 2);
    //generateMainFunction();
    //openScopeInSymbolTable();
    //generatePrintString("Helloworld: \\n");
    //generateAddVariableToVariable("aaa","bbb");
    //generateAssignOperationResultToVariable("aaa");
    //generatePrintVariable("aaa");

//    generatePrintString("ahdk\\n");
//    printSymbolTable();
//    generatePrintVariable("aaa");
//
//
//    generateAddValueToValue(20, 10);

//    generateAssignOperationResultToVariable("aaa");
//    generatePrintVariable("aaa");
//    generateSubtractValueToValue(4,2);
//    generateAssignOperationResultToVariable("aaa");
//    generatePrintVariable("aaa");
//    generateProductValueToValue(2,5);
//    generateAssignOperationResultToVariable("aaa");
//    generatePrintVariable("aaa");
//    generateDivisionValueToValue(10,5);
//    generateAssignOperationResultToVariable("aaa");
//    generatePrintVariable("aaa");
//    generateAddValueToVariable("aaa", 3);
//    generateAssignOperationResultToVariable("aaa");
//    generatePrintVariable("aaa");
//    generateProductValueToVariable("aaa", 3);
//    generateAssignOperationResultToVariable("aaa");
//    generatePrintVariable("aaa");
//    generateDivisionValueToVariable("aaa", 3);
//    generateAssignOperationResultToVariable("aaa");
//    generatePrintVariable("aaa");
//    generateAssignValueToGlobalVariable("aaa", 1);
//    generatePrintVariable("bbb");
//    generatePrintVariable("aaa");
//    generatePrintString("Eres un pringador");
//    generateAddVariableToVariable("aaa", "bbb");
//    generateAssignOperationResultToVariable("aaa");
//    generatePrintVariable("aaa");
    
}