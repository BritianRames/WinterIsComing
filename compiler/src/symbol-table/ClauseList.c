#include "../code-generator/StackManager.h"
#include "SymbolTableManager.h"
#include "ClauseList.h"


struct Clause* firstClause;
struct Clause* lastClause;
int clauseSize = 0;

void pushClause(int label, char type){
    // debug con prints
    struct Clause *clause = malloc(sizeof(struct Clause));
    clause->label = label;
    clause->type = type;
    clause->previousClause = NULL;
    clause->nextClause = NULL;
    if(clauseSize == 0){
        firstClause = clause;
        lastClause = clause;
    }else {
        lastClause->nextClause = clause;
        clause->previousClause = lastClause;
    }
    clauseSize++;
}

int popClause(char type){
    if(clauseSize == 0) return -1;
    struct Clause *clause =  lastClause;
    printf("\n\n\n--------------------vvvvvvv%cvvvvv------------------------------------------------\n\n\n",clause->type);
    printf("\n\n\n--------------------vvvvvvv%dvvvvv------------------------------------------------\n\n\n",clauseSize);
    
    for(int i = clauseSize; i > 0; i--){
        if(clause->type == type){
            int label = clause->label;
            if(clauseSize>1){
                if(clause->nextClause == NULL) lastClause = clause->previousClause;      
                else clause->previousClause->nextClause = clause->nextClause;  
            }        
            clauseSize--;
            return label;
        }else if(clauseSize > 1){
            clause = clause->previousClause;
        }
    }
    return 0;
}



