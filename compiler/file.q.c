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
L 1:
R6 = R7;
L 2:
	R1 = I(0x11ff0);
R2 = I(0x11ff8);
	R0 = R1 != R2;
	IF(!R0) GT(3);
R0 = 4;
R1 = 0x11ffc;
R2 = 11;
GT(-12);
L 4:
	GT(2);
L 3:
R6 = R7;
	GT(-2);
END
