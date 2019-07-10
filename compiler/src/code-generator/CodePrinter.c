#include "../symbol-table/SymbolTableManager.h"
#include "CodePrinter.h"

FILE *f;

void opeFile(){
  f = fopen("file.txt", "w");
  
}

int generateAssignation(int address, int value){
  fprintf(f, "MEM(%d,%d);\n", address, value);
}