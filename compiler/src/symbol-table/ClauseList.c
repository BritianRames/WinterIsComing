#include "../code-generator/StackManager.h"
#include "SymbolTableManager.h"
#include "ClauseList.h"


struct Clause* firstClauseWI;
struct Clause* lastClauseWI;
struct Clause* firstClauseWE;
struct Clause* lastClauseWE;
struct Clause* firstClauseIF;
struct Clause* lastClauseIF;
struct Clause* firstClauseIFE;
struct Clause* lastClauseIFE;
int clauseSizeWI = 0;
int clauseSizeWE = 0;
int clauseSizeIF = 0;
int clauseSizeIFE = 0;

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

void pushClauseIF(int label){
    // debug con prints
    struct Clause* clause = malloc(sizeof(struct Clause));
    clause->label = label;
    if(clauseSizeIF == 0){
        clause->previousClause = NULL;
        clause->nextClause = NULL;
        firstClauseIF = clause;
        lastClauseIF = clause;
    }else {
        lastClauseIF->nextClause = clause;
        clause->previousClause = lastClauseIF;
        lastClauseIF = clause;
    }
    clauseSizeIF++;
}

void pushClauseIFE(int label){
    // debug con prints
    struct Clause* clause = malloc(sizeof(struct Clause));
    clause->label = label;
    if(clauseSizeIFE == 0){
        clause->previousClause = NULL;
        clause->nextClause = NULL;
        firstClauseIFE = clause;
        lastClauseIFE = clause;
    }else {
        lastClauseIFE->nextClause = clause;
        clause->previousClause = lastClauseIFE;
        lastClauseIFE = clause;
    }
    clauseSizeIFE++;
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
    clauseSizeWI--;
	return etiqueta;
}
int popClauseWE(){
    //printf("------------------------------->HOLA AMIGO ESTO ES UN PUSH<----------------------------------------------");
	struct Clause* clause = lastClauseWE;
	int etiqueta = clause->label;
	if(clauseSizeWE <= 1){
		firstClauseWE = NULL;
		lastClauseWE = NULL;
	} else if (clauseSizeWE > 1){
		lastClauseWE = clause->previousClause;
	}
    clauseSizeWE--;
	return etiqueta;
}
int readClauseWE(){
    //printf("------------------------------->HOLA AMIGO ESTO ES UN PUSH<----------------------------------------------");
	struct Clause* clause = lastClauseWE;
	int etiqueta = clause->label;
	return etiqueta;
}

int readClauseWI(){
    struct Clause* clause = lastClauseWI;
	int etiqueta = clause->label;
	return etiqueta;
}

int popClauseIF(){
    struct Clause* clause = lastClauseIF;
	int etiqueta = clause->label;
	if(clauseSizeIF <= 1){
		firstClauseIF = NULL;
		lastClauseIF = NULL;
	} else if (clauseSizeIF > 1){
		lastClauseIF = clause->previousClause;
	}
    clauseSizeIF--;
	return etiqueta;
}
int popClauseIFE(){
    struct Clause* clause = lastClauseIFE;
	int etiqueta = clause->label;
	if(clauseSizeIFE <= 1){
		firstClauseIFE = NULL;
		lastClauseIFE = NULL;
	} else if (clauseSizeIFE > 1){
		lastClauseIFE = clause->previousClause;
	}
    clauseSizeIFE--;
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

