#include "Q.h"

BEGIN
L 0:
STAT(0)
STR(0x11ffc,"%d\n");
CODE(0)
R6 = R7;
R7 = R7 - 4;
	GT(1);
//Main
L 1:
R6 = R7;
I(0x11ff8) = 0;
L 2:
R1 = I(0x11ff8);
R0 = R1 <= 10;
	IF(!R0) GT(3);
R7 = R7 - 4;
R0 = I(0x11ff8);
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
I(0x11ff8) = R0;
	GT(2);
L 3:
R7 = R7 - 4;
I(R6 - 4) = 3;
