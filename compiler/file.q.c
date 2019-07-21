#include "Q.h"

BEGIN
L 0:
STAT(0)
STR(0x11ffc,"%d\n");
CODE(0)
R6 = R7;
R0 = 2;
R1 = 8;
GT(new_);
L 2:
R7 = R7 - 4;
I(0x11ff8) = R0;
	GT(1);
//suma
L 3:
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
//Main
L 1:
R6 = R7;
R0 = 4;
R1 = 12;
GT(new_);
L 4:
R7 = R7 - 4;
I(R6 - 4) = R0;
R3 = 4 * 0;
R2 = P(R6 - 4);
R3 = R2 + R3;
I(R3) = 1;
R3 = 4 * 1;
R2 = P(R6 - 4);
R3 = R2 + R3;
I(R3) = 2;
R3 = 4 * 2;
R2 = P(R6 - 4);
R3 = R2 + R3;
I(R3) = 3;
R3 = 4 * 0;
R2 = P(0x11ff8);
R3 = R2 + R3;
I(R3) = 5;
R3 = 4 * 1;
R2 = P(0x11ff8);
R3 = R2 + R3;
I(R3) = 4;
R7 = R7 - 4;
R0 = I(R6 - 4);
I(R7) = R0;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 5;
		R1 = 0x11ffc;
		GT(-12);
		L 5:
//Preparamos para CALL
R4 = R7;
R7 = R7 - 4;
R3 = 4 * 0;
R2 = P(R6 - 4);
R3 = R2 + R3;
R3 = I(R3);
I(R7) = R3;
R7 = R7 - 4;
R3 = 4 * 0;
R2 = P(0x11ff8);
R3 = R2 + R3;
R3 = I(R3);
I(R7) = R3;
R7 = R7 - 4;
I(R7) = R6;
R6 = R4;
R7 = R7 - 4;
I(R7) = 6;
//(Jump -> suma)
GT(3);
L 6:
R0 = I(R7);
R7 = R7 + 4;
R3 = 4 * 0;
R2 = P(R6 - 4);
R3 = R2 + R3;
I(R3) = R0;
R7 = R7 - 4;
R3 = 4 * 0;
R2 = P(R6 - 4);
R3 = R2 + R3;
R3 = I(R3);
I(R7) = R3;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 7;
		R1 = 0x11ffc;
		GT(-12);
		L 7:
R7 = R7 + 4;
R6 = R7;
	GT(-2);
END
