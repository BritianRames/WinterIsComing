//********************************************************Assignation Code**********************************************************/

void generateAssignValueToGlobalVariable(char* variable_id, int value);

void generateAssignVariableToGlobalVariableCode(char* variable_id, char value_id);

void generateAssignValueToLocalVariableCode(char *variable_id, int value);

void generateAssignVariableToLocalVariableCode(char* variable_id, char value_id);

void generateReturnValueCode(int value);

void generateReturnVariableCode(char* variable);

void assignVariableValue(char *variableId, char *valueVariableId);

void assignFunctionReturnValue(char *variable, char *function);



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void substract(int a, int b);

void add(int a, int b);

void multiply(int a, int b);

void divide(int a, int b);

void returnValue(int value);

void returnVariable(char* variable);

void printLineJump();

void printVariable(char* variable);

void printText(char* text);

void breakCode();

void startIf();

void startElse();

void startWhile();

void startControlStructure();

void logicalOperate(int a, int b, char* operator);

void logicalOperate(int a, char* b, char* operator);

void logicalOperate(char* a, int b, char* operator);

void logicalOperate(char* a, char* b, char* operator);}