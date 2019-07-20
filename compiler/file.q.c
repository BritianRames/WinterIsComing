#include "Q.h"

BEGIN
L 0:
R6 = R7;
R7 = R7 - 4;
R7 = R7 - 4;
R7 = R7 - 4;
I(0x11ffc) = 10;
I(0x11ff8) = 2;
I(0x11ff4) = 3;
R7 = R7 - 4;
STAT(0)
STR(0x11ff0,"%d \n");
CODE(0)
	GT(1);
L 1:
R6 = R7;
R7 = R7 - 4;
R7 = R7 - 4;
R0 = I(0x11ffc);
I(R7) = R0;
R7 = R7 - 4;
I(R7) = 10;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 * R1;
I(R7) = R3;
R7 = R7 - 4;
R0 = I(0x11ff8);
I(R7) = R0;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 / R1;
I(R7) = R3;
R7 = R7 - 4;
R0 = I(0x11ff4);
I(R7) = R0;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
R3 = R2 + R1;
I(R7) = R3;
R0 = I(R7);
R7 = R7 + 4;
I(0x11ffc) = R0;
R7 = R7 - 4;
R0 = I(0x11ffc);
I(R7) = R0;
R0 = I(R7);
R7 = R7 + 4;
I(R6 - 4) = R0;
R0 = 2;
R1 = 0x11ff0;
R2 = 210;
GT(-12);
L 2:
	GT(-2);
END
