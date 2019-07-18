#include "include/Qlib.h"
#include "include/Q.h"

BEGIN
STAT(0)
MEM(0x11ffc, 0);
CODE(0)
L 0:
	I(0x11ff8) = 1;
	I(0x11ff4) = 2;
	GT(1);
L 1:
	R7 = R7 - 4;
	I(0x11ff4) = I(0x11ff4);
	I(0x11ff0) = 4;
	I(0x11ff0) = 2;
	R1 = I(0x11fe8);
	I(0x11fe8) = R1 * I(0x11fe4);
	I(0x11ff0) = 2;
	R1 = I(0x11fe8);
	I(0x11fe8) = R1 / I(0x11fe4);
	R1 = I(0x11fec);
	I(0x11fec) = R1 + I(0x11fe8);
	I(0x11ff8) = I(0x11fec);
	R0 = I(0x11ff8) == 6;
	R7 = R7 - 4;
	R7 = R7 - 12;
	P(R7 + 8) = 0x11ffc;
STAT(1)
	STR(0x11fec,"%d\n");
CODE(1)
	I(R7 + 4) = I(73720);
	I(R7) = 1;
	GT(-12);
	R7 = R7 + 12;
	I(0x11fe8) = 3;
	I(0x11fe8) = 6;
	R1 = I(0x11fe0);
	I(0x11fe0) = R1 + I(0x11fdc);
	I(0x11ff8) = I(0x11fe4);
	R7 = R7 - 4;
	R7 = R7 - 12;
	P(R7 + 8) = 0x11ffc;
STAT(2)
	STR(0x11fe4,"%d\n");
CODE(2)
	I(R7 + 4) = I(73720);
	I(R7) = 2;
	GT(-12);
	R7 = R7 + 12;
	R7 = R7 - 4;
	R7 = R7 - 12;
	P(R7 + 8) = 0x11ffc;
STAT(3)
	STR(0x11fdc,"%d\n");
CODE(3)
	I(R7 + 4) = I(73716);
	I(R7) = 3;
	GT(-12);
	R7 = R7 + 12;
	GT(-2);
END
