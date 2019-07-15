#include "include/Qlib.h"
#include "include/Q.h"

BEGIN
STAT(0)
MEM(0x11ffc, 0);
CODE(0)
L 0:
I(0x11ffc) = 10;
I(0x11ff8) = 4;
GT(1);
L 1:
I(0x11ffc) = 10;
R0=I(0x11ffc);
printf("%d\n",R0);
R0=I(0x11ff8);
printf("%d\n",R0);
GT(-2);
END
