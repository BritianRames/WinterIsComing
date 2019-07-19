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
STAT(0)
STR(0x11ff0,"%d\n");
CODE(0)
	GT(1);
L 1:
R6 = R7;
R0 = 2;
R1 = 73712;
R2 = 1;
GT(-12);
L 2:
	GT(-2);
END
