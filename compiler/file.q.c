#include "Q.h"

BEGIN
L 0:
STAT(0)
STR(0x11ffc,"%d\n");
CODE(0)
R6 = R7;
	GT(1);
//fibo
L 2:
R1 = I(R6 - 0x4);
R0 = R1 == 0;
	IF(!R0) GT(3);
R7 = R7 - 4;
I(R7) = 0;
R0 = I(R7);
//(return)
R1 = I(R6 - 0x8);	// R1 = Previous R6
R5 = I(R6 - 0xc);	// R5 = Return label
R7 = R6;	// R7 = Previous R7
R6 = R1;	// R6 = previous R6
R7 = R7 - 4;
I(R7) = R0;	// Place Return value to stack
GT(R5);
///////////////////
L 3:
R1 = I(R6 - 0x4);
R0 = R1 == 1;
	IF(!R0) GT(4);
R7 = R7 - 4;
I(R7) = 1;
R0 = I(R7);
//(return)
R1 = I(R6 - 0x8);	// R1 = Previous R6
R5 = I(R6 - 0xc);	// R5 = Return label
R7 = R6;	// R7 = Previous R7
R6 = R1;	// R6 = previous R6
R7 = R7 - 4;
I(R7) = R0;	// Place Return value to stack
GT(R5);
///////////////////
	GT(5);
L 4:
//Preparamos para CALL
R4 = R7;
R7 = R7 - 4;
R0 = I(R6 - 4);
I(R7) = R0;
R7 = R7 - 4;
I(R7) = 1;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 - R1;
I(R7) = R3;
R7 = R7 - 4;
I(R7) = R6;
R6 = R4;
R7 = R7 - 4;
I(R7) = 6;
//(Jump -> fibo)
GT(2);
L 6:
//Preparamos para CALL
R4 = R7;
R7 = R7 - 4;
R0 = I(R6 - 4);
I(R7) = R0;
R7 = R7 - 4;
I(R7) = 2;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 - R1;
I(R7) = R3;
R7 = R7 - 4;
I(R7) = R6;
R6 = R4;
R7 = R7 - 4;
I(R7) = 7;
//(Jump -> fibo)
GT(2);
L 7:
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 + R1;
I(R7) = R3;
R0 = I(R7);
//(return)
R1 = I(R6 - 0x8);	// R1 = Previous R6
R5 = I(R6 - 0xc);	// R5 = Return label
R7 = R6;	// R7 = Previous R7
R6 = R1;	// R6 = previous R6
R7 = R7 - 4;
I(R7) = R0;	// Place Return value to stack
GT(R5);
///////////////////
L 5:
//Main
L 1:
R6 = R7;
R7 = R7 - 4;
I(R6 - 4) = 0;
L 8:
R1 = I(R6 - 0x4);
R0 = R1 < 10;
	IF(!R0) GT(9);
//Preparamos para CALL
R4 = R7;
R7 = R7 - 4;
R0 = I(R6 - 4);
I(R7) = R0;
R7 = R7 - 4;
I(R7) = R6;
R6 = R4;
R7 = R7 - 4;
I(R7) = 10;
//(Jump -> fibo)
GT(2);
L 10:
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 11;
		R1 = 0x11ffc;
		GT(-12);
		L 11:
R7 = R7 - 4;
R0 = I(R6 - 4);
I(R7) = R0;
R7 = R7 - 4;
I(R7) = 1;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 + R1;
I(R7) = R3;
R0 = I(R7);
R7 = R7 + 4;
I(R6 - 4) = R0;
	GT(8);
L 9:
R7 = R7 + 4;
R6 = R7;
	GT(-2);
END
