#include "include/Qlib.h"
#include "include/Q.h"

BEGIN
STAT(0)
MEM(0x11ffc, 0);
CODE(0)
L 0:
I(0x11ffc) = 1;
I(0x11ff8) = 2;
GT(1);
L 1:
I(0x11ff4) = I(0x11ff8);
I(0x11ff0) = 4;
I(0x11fec) = 2;
R1 = I(0x11ff0);
I(0x11ff0) = R1 * I(0x11fec);
I(0x11fec) = 2;
R1 = I(0x11ff0);
I(0x11ff0) = R1 / I(0x11fec);
R1 = I(0x11ff4);
I(0x11ff4) = R1 + I(0x11ff0);
I(0x11ffc) = I(0x11ff4);
R0 = I(0x11ffc) == 6;
	IF(!R0) GT(2);
R0=I(0x11ffc);
printf("%d\n",R0);
I(0x11ff0) = 3;
I(0x11fec) = 6;
R1 = I(0x11ff0);
I(0x11ff0) = R1 + I(0x11fec);
I(0x11ffc) = I(0x11ff4);
	GT(3);
