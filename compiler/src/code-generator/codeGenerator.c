#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

FILE *f;

void opeFile(){
  f = fopen("file.txt", "w");
}

int generateAssignation(int address, int value){
  fprintf(f, "MEM(%d,%d);\n", address, value);
}