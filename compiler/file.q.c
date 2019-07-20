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
L 2:
	R0 = I(0x11ff8) != 5;
	IF(!R0) GT(3);
L 4:
	R0 = I(0x11ff4) != 10;
	IF(!R0) GT(5);
L 6:
	R0 = I(0x11ff0) != 4;
	IF(!R0) GT(7);
R0 = 8;
R1 = 0x11ffc;
R2 = 3;
GT(-12);
L 8:
I(0x11ff0) = 4;
	GT(6);
L 7:
R0 = 9;
R1 = 0x11ffc;
R2 = 2;
GT(-12);
L 9:
I(0x11ff4) = 10;
	GT(4);
L 5:
R0 = 10;
R1 = 0x11ffc;
R2 = 1;
GT(-12);
L 10:
I(0x11ff8) = 5;
	GT(2);
L 3:
R6 = R7;
	GT(-2);
END
