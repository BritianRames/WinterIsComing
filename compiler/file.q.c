#include "include/Qlib.h"
#include "include/Q.h"

BEGIN
STAT(0)
MEM(0x11ffc, 0);
CODE(0)
L 0:
R0 = R0 - 1;
R0 = R0 + 4;
R0 = R0 + 6;
I(0x11ffc) = R0;
R0 = R0 + 5;
R0 = R0 + 473615536;
I(0x11ff8) = R0;
R0 = R0 + 1;
R0 = R0 + 473615824;
GT(-2);
END
