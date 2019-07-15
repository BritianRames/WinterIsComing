#include "StackManager.h"

int stackPointer = 73728;

int getNextStackPointer(){
  stackPointer = stackPointer - 4;
  return stackPointer;
}

int getCurrentStackPointer(){
  return stackPointer;
}

int updateStackPointer(int offset){
  printUpdateStackPointer(offset);
  stackPointer = stackPointer - offset;
}

void updateFramePointerToStackPointer(){
  printUpdateFramePointerToStackPointer();
}

void recoverStackPointer(int offset){
  printRecoverStackPointer(offset);
  stackPointer = stackPointer + offset;
}