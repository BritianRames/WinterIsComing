#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int getNextStackPointer();
int updateStackPointer(int offset);
int getCurrentStackPointer();
int getCurrentFramePointer();
void recoverStackPointer(int offset);
void updateFramePointerToStackPointer();
void addOneToNumberOperators();
void minusOneToNumberOperators();
int getNumberOperators();

