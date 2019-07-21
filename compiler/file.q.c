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
//suma
L 8:
R7 = R7 - 4;
R0 = I(R6 - 4);
I(R7) = R0;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 9;
		R1 = 0x11ffc;
		GT(-12);
		L 9:
R7 = R7 - 4;
R0 = I(R6 - 8);
I(R7) = R0;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 10;
		R1 = 0x11ffc;
		GT(-12);
		L 10:
R7 = R7 - 4;
R0 = I(R6 - 4);
I(R7) = R0;
R7 = R7 - 4;
R0 = I(R6 - 8);
I(R7) = R0;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 + R1;
I(R7) = R3;
R0 = I(R7);
//(return)
R1 = I(R6 - 0xc);	// R1 = Previous R6
R5 = I(R6 - 0x10);	// R5 = Return label
R7 = R6;	// R7 = Previous R7
R6 = R1;	// R6 = previous R6
R7 = R7 - 4;
I(R7) = R0;	// Place Return value to stack
GT(R5);
///////////////////
//resta
L 11:
R7 = R7 - 4;
R0 = I(R6 - 4);
I(R7) = R0;
R7 = R7 - 4;
R0 = I(R6 - 8);
I(R7) = R0;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 - R1;
I(R7) = R3;
R0 = I(R7);
//(return)
R1 = I(R6 - 0xc);	// R1 = Previous R6
R5 = I(R6 - 0x10);	// R5 = Return label
R7 = R6;	// R7 = Previous R7
R6 = R1;	// R6 = previous R6
R7 = R7 - 4;
I(R7) = R0;	// Place Return value to stack
GT(R5);
///////////////////
//Main
L 1:
R6 = R7;
R7 = R7 - 4;
I(R7) = 3;
R7 = R7 - 4;
I(R7) = 8;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 - R1;
I(R7) = R3;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 12;
		R1 = 0x11ffc;
		GT(-12);
		L 12:
I(R6 - 4) = 0;
R7 = R7 - 4;
I(R6 - 8) = 0;
R7 = R7 - 4;
I(R6 - 12) = 1;
L 13:
R1 = I(R6 - 0x8);
R0 = R1 < 20;
	IF(!R0) GT(14);
//Preparamos para CALL
R4 = R7;
R7 = R7 - 4;
R0 = I(R6 - 8);
I(R7) = R0;
R7 = R7 - 4;
I(R7) = R6;
R6 = R4;
R7 = R7 - 4;
I(R7) = 15;
//(Jump -> fibo)
GT(2);
L 15:
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 16;
		R1 = 0x11ffc;
		GT(-12);
		L 16:
R7 = R7 - 4;
R0 = I(R6 - 12);
I(R7) = R0;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 17;
		R1 = 0x11ffc;
		GT(-12);
		L 17:
R7 = R7 - 4;
R0 = I(R6 - 8);
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
I(R6 - 8) = R0;
R7 = R7 - 4;
R0 = I(R6 - 12);
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
I(R6 - 12) = R0;
	GT(13);
L 14:
R7 = R7 - 4;
I(R7) = 999;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 18;
		R1 = 0x11ffc;
		GT(-12);
		L 18:
//Preparamos para CALL
R4 = R7;
R7 = R7 - 4;
I(R7) = 1;
R7 = R7 - 4;
I(R7) = 2;
R7 = R7 - 4;
I(R7) = R6;
R6 = R4;
R7 = R7 - 4;
I(R7) = 19;
//(Jump -> suma)
GT(8);
L 19:
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 20;
		R1 = 0x11ffc;
		GT(-12);
		L 20:
//Preparamos para CALL
R4 = R7;
R7 = R7 - 4;
I(R7) = 10;
R7 = R7 - 4;
I(R7) = 100;
R7 = R7 - 4;
I(R7) = R6;
R6 = R4;
R7 = R7 - 4;
I(R7) = 21;
//(Jump -> resta)
GT(11);
L 21:
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 22;
		R1 = 0x11ffc;
		GT(-12);
		L 22:
R7 = R7 - 4;
R7 = R7 - 4;
R0 = I(R6 - 8);
I(R7) = R0;
R7 = R7 - 4;
I(R7) = 5;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 * R1;
I(R7) = R3;
//Preparamos para CALL
R4 = R7;
R7 = R7 - 4;
I(R7) = 3;
R7 = R7 - 4;
I(R7) = R6;
R6 = R4;
R7 = R7 - 4;
I(R7) = 23;
//(Jump -> fibo)
GT(2);
L 23:
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 / R1;
I(R7) = R3;
R0 = I(R7);
R7 = R7 + 4;
I(R6 - 16) = R0;
R7 = R7 - 4;
R0 = I(R6 - 16);
I(R7) = R0;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 24;
		R1 = 0x11ffc;
		GT(-12);
		L 24:
R7 = R7 + 4;
R7 = R7 + 4;
R7 = R7 + 4;
R6 = R7;
	GT(-2);
END
