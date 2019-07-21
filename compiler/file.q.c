#include "Q.h"

BEGIN
L 0:
STAT(0)
STR(0x11ffc,"%d\n");
CODE(0)
R6 = R7;
R7 = R7 - 4;
R7 = R7 - 4;
R7 = R7 - 4;
I(0x11ff8) = 10;
I(0x11ff4) = 3;
I(0x11ff0) = 3;
	GT(1);
//Main
L 1:
R6 = R7;
L 2:
R1 = I(0x11ff0);
R0 = R1 != 6;
	IF(!R0) GT(3);
R7 = R7 - 4;
R0 = I(0x11ff0);
I(R7) = R0;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 4;
		R1 = 0x11ffc;
		GT(-12);
		L 4:
R7 = R7 - 4;
R0 = I(0x11ff0);
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
I(0x11ff0) = R0;
	GT(2);
L 3:
I(0x11ff4) = 4;
L 5:
R1 = I(0x11ff8);
R0 = R1 != 5;
	IF(!R0) GT(6);
L 7:
R1 = I(0x11ff4);
R0 = R1 != 10;
	IF(!R0) GT(8);
L 9:
R1 = I(0x11ff0);
R0 = R1 != 4;
	IF(!R0) GT(10);
R7 = R7 - 4;
I(R7) = 2;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 11;
		R1 = 0x11ffc;
		GT(-12);
		L 11:
I(0x11ff0) = 4;
R1 = I(0x11ff0);
R2 = I(0x11ff4);
R0 = R1 == R2;
	IF(!R0) GT(12);
	GT(9);
R7 = R7 - 4;
R7 = R7 - 4;
I(R7) = 8;
R7 = R7 - 4;
R0 = I(0x11ff4);
I(R7) = R0;
R7 = R7 - 4;
R0 = I(0x11ff8);
I(R7) = R0;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 * R1;
I(R7) = R3;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 - R1;
I(R7) = R3;
R0 = I(R7);
R7 = R7 + 4;
I(R6 - 4) = R0;
R7 = R7 - 4;
R0 = I(R6 - 4);
I(R7) = R0;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 13;
		R1 = 0x11ffc;
		GT(-12);
		L 13:
R7 = R7 + 4;
L 12:
	GT(9);
L 10:
R7 = R7 - 4;
I(R7) = 3;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 14;
		R1 = 0x11ffc;
		GT(-12);
		L 14:
R7 = R7 - 4;
R0 = I(0x11ff4);
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
I(0x11ff4) = R0;
	GT(7);
L 8:
R7 = R7 - 4;
I(R7) = 4;
		R2 = I(R7);
R7 = R7 + 4;
		R0 = 15;
		R1 = 0x11ffc;
		GT(-12);
		L 15:
I(0x11ff8) = 5;
	GT(5);
L 6:
R6 = R7;
	GT(-2);
END
