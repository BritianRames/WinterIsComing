#include "include/Qlib.h"
#include "include/Q.h"

BEGIN
STAT(0)
MEM(0x11ffc, 0);
CODE(0)
L 0:
	FIL(P(0x11ff8),12,0);
	R7 = R7 - 12;
	I(0x11fec) = 3;
	I(P(0x11ff8)) = 0;
	I(0x11fec) = 6;
	I(P(0x11ff4)) = 1;
	I(0x11fec) = 5;
	I(P(0x11ff0)) = 2;
	R7 = R7 - 1;
	R7 = R7 - 5;
	P(R7 + 1) = 73704;
STAT(2)
	STR(0x11fe8,"[");
CODE(2)
	R7 = 2;
	GT(-12);
L 2: R7 = R7 + 1;
	R7 = R7 - 4;
	R7 = R7 - 12;
	P(R7 + 8) = 0x11ffc;
STAT(3)
	STR(0x11fe3,"%d\n");
CODE(3)
	I(R7 + 4) = I(73720);
	I(R7) = 3;
	GT(-12);
	R7 = R7 + 12;
	R7 = R7 - 2;
	R7 = R7 - 6;
	P(R7 + 2) = 73691;
STAT(4)
	STR(0x11fdb,", ");
CODE(4)
	R7 = 4;
	GT(-12);
L 4: R7 = R7 + 2;
	R7 = R7 - 4;
	R7 = R7 - 12;
	P(R7 + 8) = 0x11ffc;
STAT(5)
	STR(0x11fd5,"%d\n");
CODE(5)
	I(R7 + 4) = I(73704);
	I(R7) = 5;
	GT(-12);
	R7 = R7 + 12;
	R7 = R7 - 2;
	R7 = R7 - 6;
	P(R7 + 2) = 73677;
STAT(6)
	STR(0x11fcd,", ");
CODE(6)
	R7 = 6;
	GT(-12);
L 6: R7 = R7 + 2;
	R7 = R7 - 4;
	R7 = R7 - 12;
	P(R7 + 8) = 0x11ffc;
STAT(7)
	STR(0x11fc7,"%d\n");
CODE(7)
	I(R7 + 4) = I(73688);
	I(R7) = 7;
	GT(-12);
	R7 = R7 + 12;
	R7 = R7 - 1;
	R7 = R7 - 5;
	P(R7 + 1) = 73663;
STAT(8)
	STR(0x11fbf,"]");
CODE(8)
	R7 = 8;
	GT(-12);
L 8: R7 = R7 + 1;
	GT(-2);
END
