#include "demo.h"
#include "../symbol-table/SymbolTableManager.h"

FILE *f;

void openFile(){
  f = fopen("file.q.c", "w");
}

void qInitialization() {
    fprintf(f, "#include \"Q.h\"\n\n");
    fprintf(f, "BEGIN\n");
    fprintf(f, "L 0:\n");
    insertVariableInSymbolTable("STR4PRINT");
    fprintf(f,"STAT(0)\nSTR(0x11ffc,\"%%d\\n\");\nCODE(0)\n");
    r6EqualsR7();
}

void jumpMain(){
    fprintf(f, "\tGT(1);\n");
}

void goToExit()  {
  //fprintf(f, "printf(\"%%d \\n\", I(R6 - 4));\n");
  //fprintf(f, "printf(\"%%d \\n\", I(R6 - 8));\n");
  //fprintf(f, "printf(\"%%d \\n\", I(R6 - 12));\n");
  //fprintf(f, "printf(\"%%d \\n\", I(R6 - 16));\n");
  r6EqualsR7();
  fprintf(f, "\tGT(-2);\n");
}

void qEnding() {
    fprintf(f, "END\n");
}

/*****Functions********/
void function(char *name){
  struct Symbol *function = getLastFunctionFromSymbolTable();
  fprintf(f, "//%s\n", name);
  fprintf(f, "L %d:\n", function->label);
}

void mainFunction() {
  fprintf(f, "//Main\n");
  fprintf(f, "L 1:\n");
  r6EqualsR7();
}

void functionCall(char* function_id){ //FunctionCall
  struct Symbol *function = getFunctionFromSymbolTable(function_id);
  int returnLabel = _getNextLabel();
  moveR7Down();
  fprintf(f, "I(R7) = R6;\n");
  fprintf(f, "R6 = R1;\n"); //R1 has original R7 of the function
  moveR7Down();
  fprintf(f, "I(R7) = %d;\n", returnLabel);
  fprintf(f, "//(Jump -> %s)\n", function_id);
  fprintf(f, "GT(%d);\n", function->label);
  fprintf(f, "L %d:\n", returnLabel);
}

void putParameterValueInStack(int value){ //For each recognized param
  insertValueInStack(value);
}

void saveR7inR1(){ //Before inserting params
  fprintf(f, "//Preparamos para CALL\n");
  fprintf(f, "R1 = R7;\n");
}

void functionReturn(){
  //Value to return should be un stack top
  struct Symbol *function = getLastFunctionFromSymbolTable();
  int offset = 4*(function->numberOfParameters);
  fprintf(f, "//(return)\n");
  fprintf(f,"R1 = I(R6 - 0x%x);\t// R1 = Previous R6\n", offset + 4);
  fprintf(f,"R5 = I(R6 - 0x%x);\t// R5 = Return label\n", offset + 8);
  fprintf(f,"R7 = R6;\t// R7 = Previous R7\n");
  fprintf(f,"R6 = R1;\t// R6 = previous R6\n");
  //Returned value to stack
  moveR7Down();
  fprintf(f,"I(R7) = R0;\t// Place Return value to stack\n");
  //Go to return label
  fprintf(f,"GT(R5);\n");
  fprintf(f, "///////////////////\n");
}

//hacer rt con gt(R6 + numberParam + 4)

/*******Stack*********/

void moveR7Up(){
  fprintf(f, "R7 = R7 + 4;\n");
}
void moveR7Down(){
  fprintf(f, "R7 = R7 - 4;\n");
}
void r6EqualsR7(){
  fprintf(f, "R6 = R7;\n");
}

/********Assignation*********/

void putLocalVariableValueInR0(int offset){
  fprintf(f, "R0 = I(R6 - %d);\n", offset);
}
void putGlobalVariableValueInR0(int address){
  fprintf(f, "R0 = I(%d);\n", address);
}

//Called when a declaration is recognized

void assignValueToVariable(char* variable_id, int value){
  struct Symbol* variable = getVariableFromSymbolTable(variable_id);
  struct Symbol* function = getLastFunctionFromSymbolTable();
  if(variable->type == 'g'){	  
    fprintf(f, "I(0x%x) = %d;\n", variable->address, value);
  } else if (variable->type == 'l'){	  
    int offset =  getLocalVariableOffset(variable->address);
    //moveR7Down();
    fprintf(f, "I(R6 - %d) = %d;\n", offset, value);    
  } else if(variable->type == 'p'){
    int offset =  getParameterOffset(variable->address);
    fprintf(f, "I(R6 - %d) = %d;\n", offset, value);
  }
}
void declarationGlobalVariable(char* variable_id){
  struct Symbol* variable = getVariableFromSymbolTable(variable_id);
  if(variable->type == 'g'){	  
    moveR7Down();
  }

  if(variable->type == 'l'){	  
    moveR7Down();
  }
}

void putValueInR0(int value){
  fprintf(f, "R0 = %d;\n", value);
}

void putVariableInR0(char *variable_id){
  struct Symbol* variable = getVariableFromSymbolTable(variable_id);
  if (variable->type == "g"){
    putGlobalVariableValueInR0(variable->address);
  } else if(variable->type = "l"){
    int offset = getLocalVariableOffset(variable->address);
    putLocalVariableValueInR0(offset);
  }
}

void putOperationResultInR0(){
  fprintf(f, "R0 = I(R7);\n");
}

void putR0InGlobalVariable(int address){
  fprintf(f, "I(%d) = R0;\n", address);
}
void putR0InLocalVariable(int offset){
  fprintf(f, "I(R6 - %d) = R0;\n", offset);
}

void assignVariableToVariable(char* variable1_id, char* variable2_id){
  struct Symbol* variable1 = getVariableFromSymbolTable(variable1_id);
  struct Symbol* variable2 = getVariableFromSymbolTable(variable2_id);

  if (variable1->type == "g"){
    putGlobalVariableValueInR0(variable1->address);
    moveR7Down(); //TODO (christian dice que esta bien)
  } else if(variable1->type = "l"){
    int offset = getLocalVariableOffset(variable1->address);
    putLocalVariableValueInR0(offset);
  }
  if (variable2->type == 'g'){
    putR0InGlobalVariable(variable2->address);
  } else if(variable2->type = 'l'){
    int offset = getLocalVariableOffset(variable2->address);
    putR0InLocalVariable(offset);
  }
}

void assignR0ToVariable(char *variable_id) {
  struct Symbol *variable = getVariableFromSymbolTable(variable_id); 
  putOperationResultInR0();
  moveR7Up();
  if (variable->type == 'g'){
    fprintf(f, "I(0x%x) = R0;\n", variable->address);  
  } else if (variable->type == 'l'){
    int offset = getLocalVariableOffset(variable->address);
    printf("Hey there %d -------------------------------------------------------", variable->address);
    fprintf(f, "I(R6 - %d) = R0;\n", offset);  
  } else if (variable->type == 'p'){
      int offset = getParameterOffset(variable->address);
      printf("Hey there %d -------------------------------------------------------", variable->address);
      fprintf(f, "I(R6 - %d) = R0;\n", offset);
  }
}

int getLocalVariableOffset(int position){
  struct Symbol* function = getLastFunctionFromSymbolTable();
  int numberOfParameters = function -> numberOfParameters;
  int result = 0;
  if(strcmp(function->id, "main") == 0){
    result = 4 * (position);
    printf("\n\n\nAAAAAAAAAA-----%d---AAAAAAAAAAAA\n\n\n",position);
    printSymbolTable();
  } else {
    result = 4 * (numberOfParameters + 2 + position);
  }
  return result;
}

void printValue(int value){
  int label = _getNextLabel();
  //saveRegisters();
  fprintf(f,"R0 = %d;\n",label);
  fprintf(f,"R1 = 0x%x;\n",0x11ffc);
  fprintf(f,"R2 = %d;\n",value);
  fprintf(f,"GT(-12);\n");
  fprintf(f, "L %d:\n", label);
  //recoverRegisters();
}

int getParameterOffset(int position){
    return position * 4;
}

/*********Operations*********/

void insertValueInStack(value){
  moveR7Down();
  fprintf(f, "I(R7) = %d;\n", value);
}

void insertVariableValueInStack(char* variable_id){
  struct Symbol* variable = getVariableFromSymbolTable(variable_id);
  if(variable->type == 'g'){
    moveR7Down();
    fprintf(f, "R0 = I(0x%x);\n", variable->address);
    fprintf(f, "I(R7) = R0;\n");
  }
  else if(variable->type == 'l'){
    int offset = getLocalVariableOffset(variable->address);
    moveR7Down();
    fprintf(f, "R0 = I(R6 - %d);\n", offset);
    fprintf(f, "I(R7) = R0;\n");
  }
}

void product(){
  fprintf(f, "R1 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R2 = I(R7);\n");
  fprintf(f, "R3 = R2 * R1;\n");
  fprintf(f, "I(R7) = R3;\n");
}

void add(){
  fprintf(f, "R1 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R2 = I(R7);\n");
  fprintf(f, "R3 = R2 + R1;\n");
  fprintf(f, "I(R7) = R3;\n");
}

void substract(){
  fprintf(f, "R1 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R2 = I(R7);\n");
  fprintf(f, "R3 = R2 - R1;\n");
  fprintf(f, "I(R7) = R3;\n");
}

void division(){
  fprintf(f, "R1 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R2 = I(R7);\n");
  fprintf(f, "R3 = R2 / R1;\n");
  fprintf(f, "I(R7) = R3;\n");
}

/********Registers***********/

void saveRegisters(){
  moveR7Down();
  fprintf(f, "I(R7) = R0;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R1;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R2;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R3;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R4;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R5;\n");
  moveR7Down();
  fprintf(f, "I(R7) = R6;\n");
}

void recoverRegisters(){
  fprintf(f, "R6 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R5 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R4 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R3 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R2 = I(R7);\n");
  moveR7Up();
  fprintf(f, "R1 = I(R7);\n");
  moveR7Up();
}

/*********LogCong-ValueValue***********/
void logicalValueToValue(int val1, int val2, char* logic) {
  fprintf(f, "R0 = %d %s %d;\n", val1, logic, val2);
}

/*********LogCong-ValueVariable***********/
void logicalVariableToValue(char* variable_id, int val, char* logic){
  struct Symbol *variable = getVariableFromSymbolTable(variable_id);
  if(variable->type == 'g'){
    fprintf(f, "R1 = I(0x%x);\n", variable->address, val);

  }else if(variable->type == 'l'){
    int offset = getLocalVariableOffset(variable->address);
    fprintf(f, "R1 = I(R6 - 0x%x);\n", offset, val);
  }
  fprintf(f, "R0 = R1 %s %d;\n", logic, val);
}



/*********LogCong-VariableVariable***********/
void logicalVariableToVariable(char* variable1_id, char* variable2_id, char* logic){
  struct Symbol* variable1 = getVariableFromSymbolTable(variable1_id);
  struct Symbol* variable2 = getVariableFromSymbolTable(variable2_id);
  if(variable1->type == 'g'){
    fprintf(f, "R1 = I(0x%x);\n", variable1->address);
  }
  else if(variable1->type == 'l'){
    int offset = getLocalVariableOffset(variable1->address);
    fprintf(f, "R1 = I(R6 - 0x%x);\n", offset);
  }
  if(variable2->type == 'g'){
    fprintf(f, "R2 = I(0x%x);\n", variable2->address);
  }
  else if(variable1->type == 'l'){
    int offset = getLocalVariableOffset(variable2->address);
    fprintf(f, "R2 = I(R6 - 0x%x);\n", offset);
  }
  fprintf(f, "R0 = R1 %s R2;\n",logic);
}

///*******Not operations**********/
void notValue(int val){
  fprintf(f, "\tR0 = !%d;\n", val);
}

void notVariable(char *variable_id){
  struct Symbol* variable = getVariableFromSymbolTable(variable_id);
  if(variable->type == 'g'){
    fprintf(f, "\tR0 = !I(0x%x);\n", variable->address);
  }
  else if(variable->type == 'l'){
    int offset = getLocalVariableOffset(variable->address);
    fprintf(f, "\tR0 = !I(R6 - 0x%x);\n", offset);
  }
}

int printHeaderOfClauseInstruction(){
    int etiqueta = _getNextLabel();
    fprintf(f, "\tIF(!R0) GT(%d);\n", etiqueta);
    return etiqueta;
}

int printGoToFinalEstructureElse(){
    int etiqueta = _getNextLabel();
    fprintf(f, "\tGT(%d);\n", etiqueta);
    return etiqueta;
}

void printLabelInstruction(int label){
    fprintf(f, "L %d:\n", label);
}

void generateGoToWhile(int etiqueta){
    fprintf(f, "\tGT(%d);\n", etiqueta);
}
