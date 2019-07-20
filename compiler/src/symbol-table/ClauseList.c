#include "../code-generator/StackManager.h"
#include "SymbolTableManager.h"
#include "ClauseList.h"


struct Clause* firstClauseWI;
struct Clause* lastClauseWI;
struct Clause* firstClauseWE;
struct Clause* lastClauseWE;
int clauseSizeWI = 0;
int clauseSizeWE = 0;


void pushClauseWI(int label){
    // debug con prints
    struct Clause* clause = malloc(sizeof(struct Clause));
    clause->label = label;
    if(clauseSizeWI == 0){
        clause->previousClause = NULL;
        clause->nextClause = NULL;
        firstClauseWI = clause;
        lastClauseWI = clause;
    }else {
        lastClauseWI->nextClause = clause;
        clause->previousClause = lastClauseWI;
        lastClauseWI = clause;
    }
    clauseSizeWI++;
}

void pushClauseWE(int label){
    // debug con prints
    struct Clause* clause = malloc(sizeof(struct Clause));
    clause->label = label;
    if(clauseSizeWE == 0){
        clause->previousClause = NULL;
        clause->nextClause = NULL;
        firstClauseWE = clause;
        lastClauseWE = clause;
    }else {
        lastClauseWE->nextClause = clause;
        clause->previousClause = lastClauseWE;
        lastClauseWE = clause;
    }
    clauseSizeWE++;
}


    
int popClauseWI(){
    //printf("------------------------------->HOLA AMIGO ESTO ES UN PUSH<----------------------------------------------");
	struct Clause* clause = lastClauseWI;
	int etiqueta = clause->label;
	if(clauseSizeWI <= 1){
		firstClauseWI = NULL;
		lastClauseWI = NULL;
	} else if (clauseSizeWI > 1){
		lastClauseWI = clause->previousClause;
	}
	return etiqueta;
}
int popClauseWE(){
    //printf("------------------------------->HOLA AMIGO ESTO ES UN PUSH<----------------------------------------------");
	struct Clause* clause = lastClauseWE;
	int etiqueta = clause->label;
	if(clauseSizeWE <= 1){
		firstClauseWE = NULL;
		lastClauseWE = NULL;
	} else if (clauseSizeWI > 1){
		lastClauseWE = clause->previousClause;
	}
	return etiqueta;
}


void printClause(){
	printf("df");
    //struct Clause* currentClause = firstClauseWI;
    //for(int i = 0; i < clauseSize; i++){
    //    printf("-----------SYMBOL (SIZE %d) -> %d------------\n",clauseSize, i);
    //    printf("LABEL -> %d\n",currentClause->label);
    //    printf("TYPE -> %c\n",currentClause->type);
	//	if(currentClause->previousClause != NULL) printf("PREVIOUS -> %d\n",currentClause->previousClause->label);
	//	if(currentClause->nextClause != NULL) printf("NEXT -> %d\n",currentClause->nextClause->label);
    //    printf("--------------------------------------------\n",i);
    //    currentClause = currentClause->nextClause;
    //}
}

