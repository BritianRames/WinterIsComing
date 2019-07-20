#include "Q.h"

BEGIN
STAT(0)
MEM(0x11ffc, 0);
CODE(0)
L 0:
R6 = R7;
R7 = R7 - 4;
I(0x11ffc) = 1;
	GT(1);
//sum
L 2:
R7 = R7 - 4;
I(R7) = 1;
R0 = I(R7);
//(return)
R1 = I(R6 - 0x4);
R7 = R6;
R6 = R1;
R7 = R7 + 8;
R7 = R7 - 4;
I(R7) = R0;
R5 = I(R6 - 0x8);
GT(R5);
///////////////////
//Main
L 1:
R6 = R7;
R7 = R7 - 4;
R1 = R7;
//Preparamos para operación sum
R7 = R7 - 4;
I(R7) = R6;
R6 = R1;
R7 = R7 - 4;
I(R7) = 3
//(Jump)
GT(2)
L 3:
printf("%d \n", I(R6 - 4));
printf("%d \n", I(R6 - 8));
printf("%d \n", I(R6 - 12));
printf("%d \n", I(R6 - 16));
	GT(-2);
END
