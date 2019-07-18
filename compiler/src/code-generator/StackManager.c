#include "StackManager.h"

int stackPointer = 0x12000;
int numberOperators = 0;

void addOneToNumberOperators(){
  numberOperators = numberOperators + 1;
}

void minusOneToNumberOperators(){
  numberOperators = numberOperators - 1;
}

int getNumberOperators(){
  return numberOperators;
}

int getNextStackPointer(){
  stackPointer = stackPointer - 4;
  return stackPointer;
}

int foo(){
  return 1;
}

int getCurrentStackPointer(){
  return stackPointer;
}

int updateStackPointer(int offset){
  //printUpdateStackPointer(offset);
  stackPointer = stackPointer - offset;
}

void updateFramePointerToStackPointer(){
  //printUpdateFramePointerToStackPointer();

}

void recoverStackPointer(int offset){
  //printRecoverStackPointer(offset);
  stackPointer = stackPointer + offset;
}
