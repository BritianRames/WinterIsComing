#include "StackManager.h"

int stackPointer = 73728;
int framePointer = 73728; //TODO

int getNextStackPointer(stackPointer){
  stackPointer = stackPointer - 4;
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