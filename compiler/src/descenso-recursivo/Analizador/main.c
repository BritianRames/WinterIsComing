#include <stdio.h>
#include "cabeceras.h"

int l;

int yylex();
int fails = 0;
char terminals [][20] = {"END_OF_INSTR","RETURN","BREAK","VARIABLE","INT_VAL","REAL_VAL","BOOL_VAL","INT_TYPE","REAL_TYPE","BOOL_TYPE","ASSIGN","SUM","SUBSTRACT","PRODUCT","DIVIDE","AND","OR","NOT","EQUALS","NOT_EQUALS","GREATER","GREATER_EQUALS","LESS","LESS_EQUALS","HEADER_END","FOR_WHILE_CLAUSE","SQUARE_BRACKET_OPEN","SQUARE_BRACKET_CLOSE","PARETHESES_OPEN","PARETHESES_CLOSE","ID","OPEN_CONTEXT_TAG","CLOSE_CONTEXT_TAG"};

int main(int argc, char** argv) {
	printf("\n--------[%s]--------\n",argv[1]);
	yyin = fopen(argv[1], "r");
    l = getChar();
    while_instr();
	int n = 0;
	if(l != 0){
		printf("ERROR[SOBRAN]");
		fails++;
	}
    if(fails==0){
        printf("NO HAY ERRORES\n");
    } else {
        printf(" %d ERRORES DETECTADOS\n",fails);
    }
    return 1;
}

int getChar() {
    return yylex();
}

void while_instr () {
	while(1){
		expr();
		if(l == FOR_WHILE_CLAUSE) break;
		if(l==AND){
			match(AND);
		} else{
			match(OR);
		}
	}
	match(FOR_WHILE_CLAUSE);
	match(HEADER_END);
	match(END_OF_INSTR);
	match(OPEN_CONTEXT_TAG);
	input();
	match(CLOSE_CONTEXT_TAG);
}

void input () {
	if (l == ID || l == INT_TYPE || l == BOOL_TYPE || l == REAL_TYPE || l == INT_VAL || l == REAL_VAL || l == BOOL_VAL || l == BREAK) {
		instr();
		input();
	}else {
		// DO NOTHING
	}
}

void instr () {
    if(l == ID){
		match(ID);
		if(l == LESS || l == GREATER || l == GREATER_EQUALS || l == NOT_EQUALS || l == LESS_EQUALS || l == EQUALS){
			pre_anid_while();
		} else {
			if(l == ASSIGN){
				match(ASSIGN);
				term();
			} else {
				//DO NOTHING
			}
			match(END_OF_INSTR);
		}
	}else if(l == BREAK){
		match(l);
		match(END_OF_INSTR);
	}else if(l==INT_VAL || l == REAL_VAL || l == BOOL_VAL){
		if(l==INT_VAL){
			match(INT_VAL);
		} else if (l == REAL_VAL){
			match(REAL_VAL);
		} else {
			match(BOOL_VAL);
		}
		if(l == LESS || l == GREATER || l == GREATER_EQUALS || l == NOT_EQUALS || l == LESS_EQUALS || l == EQUALS){
			pre_anid_while();
		} else {
			anid_while();
		}
	}else if(l == INT_TYPE || l == BOOL_TYPE || l == REAL_TYPE){
		if(l==INT_TYPE){
			match(INT_TYPE);
		} else if (l == REAL_TYPE){
			match(REAL_TYPE);
		} else {
			match(BOOL_TYPE);
		}
		match(ID);
		if(l == ASSIGN){
			match(ASSIGN);
			term();
			
		} else{
			//DO NOTHING
		}
		match(END_OF_INSTR);
		
	}
}

void pre_anid_while(){
	if(l == LESS || l == GREATER || l == GREATER_EQUALS || l == NOT_EQUALS || l == LESS_EQUALS){
		if(l==LESS){
			match(LESS);
		} else if (l == GREATER){
			match(GREATER);
		} else if (l == GREATER_EQUALS){
			match(GREATER_EQUALS);
		} else if (l == NOT_EQUALS){
			match(NOT_EQUALS);
		} else {
			match(LESS_EQUALS);
		}
	}
	if(l == INT_VAL || l == REAL_VAL || l == BOOL_VAL || l == ID){
		if(l==INT_VAL){
			match(INT_VAL);
		} else if (l == REAL_VAL){
			match(REAL_VAL);
		} else if (l == BOOL_VAL){
			match(BOOL_VAL);
		} else {
			match(ID);
		}
	} else {
		//ERROR
		printf("ERROR[TERM]\n");
	}
	anid_while();
}

void anid_while(){
	match(FOR_WHILE_CLAUSE);
	match(HEADER_END);
	match(END_OF_INSTR);
	match(OPEN_CONTEXT_TAG);
	input();
	match(CLOSE_CONTEXT_TAG);
}

void expr () {
	term();
	if(l == LESS_EQUALS || l == LESS || l == EQUALS || l == GREATER || l == GREATER_EQUALS || l == NOT_EQUALS){
		if(l==LESS){
			match(LESS);
		} else if(l == EQUALS){
			match(EQUALS);
		} else if (l == GREATER){
			match(GREATER);
		} else if (l == GREATER_EQUALS){
			match(GREATER_EQUALS);
		} else if (l == NOT_EQUALS){
			match(NOT_EQUALS);
		} else {
			match(LESS_EQUALS);
		}
		term();
	} else {
		//NOTHING TODO
	}
}

void term () {
	if (l == INT_VAL || l == REAL_VAL || l == BOOL_VAL) {
		data_value();
	} else{
		match(ID);
	} 
	if(l == SUM || l == SUBSTRACT || l == PRODUCT || l == DIVIDE){
		if (l == SUM){
			match(SUM);
		} else if(l == SUBSTRACT){
			match(SUBSTRACT);
		} else if(l == PRODUCT){
			match(PRODUCT);
		} else {
			match(DIVIDE);
		}
		term();
	}else{
		//NOTHING TODO
	}
}

void data_value () {
	if (l == INT_VAL) {
		match(INT_VAL);
	} else if (l == REAL_VAL) {
		match(REAL_VAL);
	} else{
		match(BOOL_VAL);
	}
}

void match(int terminal) {
    if(l == terminal) {
        printf("Simbolo %s\n",terminals[l-257]);
		l = getChar();
    } else {
        printf("Error: Expected character %s != Actual character %s\n", terminals[terminal-257], terminals[l-257]);
        fails++;
    }
}


