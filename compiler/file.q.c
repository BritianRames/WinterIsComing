#include "Q.h"

BEGIN
STAT(0)
MEM(0x11ffc, 0);
CODE(0)
L 0:
R6 = R7;
R7 = R7 - 4;
R7 = R7 - 4;
R7 = R7 - 4;
I(0x11ffc) = 10;
I(0x11ff8) = 2;
I(0x11ff4) = 3;
	GT(1);
L 1:
R6 = R7;
R7 = R7 - 4;
I(R7) = 0;
R7 = R7 - 4;
I(R7) = 2;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
I(R7) = R2 + R1;
R7 = R7 - 4;
I(R7) = 4;
R1 = I(R7);
R7 = R7 + 4;
R2 = I(R7);
I(R7) = R2 + R1;
R0 = I(R7);
R7 = R7 + 4;
I(R6 - 12) = R0;
R7 = R7 - 4;
I(R6 - 20) = 100;
I(0x11ff4) = 4;
	GT(-2);
END
