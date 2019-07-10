#include "CodePrinter.h"

FILE *f;

void openFile(){
  f = fopen("file.txt", "w");
}

int generateAssignation(int address, int value){
  fprintf(f, "MEM(%d,%d);\n", address, value);
}