#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Clause{
    char type;
    int label;
    struct Clause *previousClause;
    struct Clause *nextClause;
};


void pushClause(int label, char type);
int popClause();
