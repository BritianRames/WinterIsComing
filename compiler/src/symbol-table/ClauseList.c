#include "../code-generator/StackManager.h"
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
    }else {
        lastClause->nextClause = clause;
        clause->previousClause = lastClause;
    }
    clauseSize++;
}

int popClause(){
    int label = lastClause->label;
    lastClause->previousClause->nextClause = NULL;
    return label;
}




