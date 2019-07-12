#include "StackManager.h"

int stackPointer = 73728;
int framePointer = 73728; //TODO

int getNextStackPointer(stackPointer){
  stackPointer = stackPointer - 4;
<<<<<<< HEAD
  return stackPointer;
}

int updateStackPointer(int offset){
  printUpdateStackPointer(offset);
  stackPointer = stackPointer - offset;
}

int getCurrentStackPointer(){
=======
>>>>>>> b9b03f88dca944e685bdcd90b87ffc421b289b40
  return stackPointer;
}

int getCurrentFramePointer(){ //TODO
  return 0;
}
