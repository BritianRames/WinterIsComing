#include "symbol-table/SymbolTableManager.h"
#include "symbol-table/ClauseList.h"
#include "code-generator/demo.h"
#include <stdio.h>
extern FILE *yyin;
extern int yyparse();

int main(int argc, char** argv) {
    openFile();
    if (argc>1) yyin=fopen(argv[1],"r");
    yyparse();
}
