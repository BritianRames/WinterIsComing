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
I(0x11ff4) = 2;
I(0x11ff0) = 3;
	GT(1);
L 1:
R6 = R7;
R7 = R7 - 4;
R7 = R7 - 4;
R0 = I(0x11ff8);
I(R7) = R0;
R7 = R7 - 4;
I(R7) = 10;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 * R1;
I(R7) = R3;
R7 = R7 - 4;
R0 = I(0x11ff4);
I(R7) = R0;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 / R1;
I(R7) = R3;
R7 = R7 - 4;
R0 = I(0x11ff0);
I(R7) = R0;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 + R1;
I(R7) = R3;
R0 = I(R7);
R7 = R7 + 4;
I(0x11ff8) = R0;
I(R6 - 4) = 1;
L 2:
	R0 = I(R6 - 0x4) != 5;
	IF(!R0) GT(3);
R0 = I(R6 - 0x4) == 4;
	IF(!R0) GT(4);
R0 = 5;
R1 = 0x11ffc;
R2 = 999;
GT(-12);
L 5:
R0 = I(0x11ff0) == 3;
	IF(!R0) GT(6);
R0 = 7;
R1 = 0x11ffc;
R2 = 111;
GT(-12);
L 7:
L 6:
	GT(8);
L 6:
R0 = 9;
R1 = 0x11ffc;
R2 = 888;
GT(-12);
L 9:
L 8:
R0 = 10;
R1 = 0x11ffc;
R2 = 210;
GT(-12);
L 10:
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
	GT(2);
L 3:
R7 = R7 - 4;
I(R6 - 8) = 333;
R7 = R7 + 4;
R7 = R7 + 4;
R6 = R7;
	GT(-2);
END
