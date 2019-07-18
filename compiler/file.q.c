#include "Q.h"

BEGIN
STAT(0)
MEM(0x11ffc, 0);
CODE(0)
L 0:
R6 = R7
I(0x0) = 10;
I(0x0) = 2;
I(0x0) = 3;
	GT(1);
L 1:
I(R7 + 0x4) = 0;
	GT(-2);
END
