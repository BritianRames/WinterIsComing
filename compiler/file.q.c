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
		R5 = R7 - 4;
R7 = R7 - 4;
I(R7) = 98;
R7 = R7 - 4;
I(R7) = 99;
R7 = R7 - 4;
I(R7) = 100;
R7 = R7 - 4;
I(R7) = 101;
R7 = R7 - 4;
I(R7) = 0;
R7 = R7 - 4;
I(R7) = 0;
R7 = R7 - 4;
I(R7) = 0;
R7 = R7 - 4;
I(R7) = 0;
		R0 = 2;
		R1 = 0x11ffc;
		R2 = R5;
		GT(-12);
		L 2:
R7 = R7 + 4;
R7 = R7 + 4;
R7 = R7 + 4;
R7 = R7 + 4;
R7 = R7 + 4;
R7 = R7 + 4;
R7 = R7 + 4;
R7 = R7 + 4;
R6 = R7;
	GT(-2);
END
