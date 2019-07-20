#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Clause{
    int label;
    struct Clause *previousClause;
    struct Clause *nextClause;
};


void pushClauseWI(int label);
int popClauseWI();
void pushClauseWE(int label);
int popClauseWE();
void printClause();
