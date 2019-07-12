#include "StackManager.h"

int stackPointer = 12000;
int framePointer = 12000; //TODO

int getNextStackPointer(stackPointer){
  stackPointer = stackPointer + 4;
  return stackPointer;
}

int updateStackPointer(int offset){
  printUpdateStackPointer(offset);
  stackPointer = stackPointer - offset;
}

int getCurrentStackPointer(){
  return stackPointer;
}

int getCurrentFramePointer(){ //TODO
  return 0;
}