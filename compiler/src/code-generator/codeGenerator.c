#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
<<<<<<< HEAD
#include "../symbol-table/SymbolTableManager.h"
=======
#include "SymbolTableManager.c"
>>>>>>> 1c1a591b883b35c0ba9ce96a0bb3624a758d7617

FILE *f;

void opeFile(){
  f = fopen("file.txt", "w");
}

int generateAssignation(int address, int value){
  fprintf(f, "MEM(%d,%d);\n", address, value);
}