#include "Q.h"

BEGIN
STAT(0)
MEM(0x11ffc, 0);
CODE(0)
L 0:
R6 = R7;
I(0x11ffc) = 10;
R7 = R7 - 4;
R6 = R7;
I(0x11ff8) = 2;
R7 = R7 - 4;
R6 = R7;
I(0x11ff4) = 3;
R7 = R7 - 4;
R6 = R7;
	GT(1);
L 1:
R7 = R7 - 4;
printf("%d\n", R7);
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
printf("%d\n",R0);
R7 = R7 + 4;
I(R7 - 4) = R0;
I(R7 + 4) = 100;
printf("%d", I(73708));
	GT(-2);
END
