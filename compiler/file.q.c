#include "include/Qlib.h"
#include "include/Q.h"

BEGIN
STAT(0)
MEM(0x11ffc, 0);
CODE(0)
L 0:
I(0x11ffc) = 10;
I(0x11ff8) = 2;
I(0x11ff4) = 3;
GT(1);
L 1:
printf("%s",main);
I(0x11ff4) = I(0x11ff4) + 1;
R0=I(0x11ff4);
printf("%d\n",R0);
R0 = 2;
R1 = 20;
GT(new_);
L 2:
I(0x11ff0) = R0;
I(P(0x11ff0) + 4 * 0) = 1;
I(P(0x11ff0) + 4 * 1) = 2;
I(P(0x11ff0) + 4 * 2) = 3;
I(P(0x11ff0) + 4 * 3) = 4;
I(P(0x11ff0) + 4 * 4) = 5;
I(0x11fe8) = I(P(0x11ff0) + 4 * 4);
R0=I(0x11fe8);
printf("%d\n",R0);
I(0x11fe8) = I(P(0x11ff0) + 4 * 3);
R0=I(0x11fe8);
printf("%d\n",R0);
I(0x11fe8) = I(P(0x11ff0) + 4 * 2);
R0=I(0x11fe8);
printf("%d\n",R0);
I(0x11fe8) = I(P(0x11ff0) + 4 * 1);
R0=I(0x11fe8);
printf("%d\n",R0);
I(0x11fe8) = I(P(0x11ff0) + 4 * 0);
R0=I(0x11fe8);
printf("%d\n",R0);
I(0x11fe8) = 0;
R0 = I(0x11ffc) != 1;
	IF(!R0) GT(3);
I(0x11fe4) = 1;
I(0x11fe0) = 4;
R1 = I(0x11fe0);

I(0x11fe4) = I(0x11fe4) * R1;
I(0x11fe0) = 2;
R1 = I(0x11fe0);

I(0x11fe4) = I(0x11fe4) / R1;
I(0x11fe0) = 10;
I(0x11fdc) = 2;
R1 = I(0x11fdc);

I(0x11fe0) = I(0x11fe0) + R1;
R1 = I(0x11fe0);

I(0x11fe4) = I(0x11fe4) * R1;
I(0x11ffc) = I(0x11fe4);
L 3:
I(0x11fe4) = 1;
I(0x11fe0) = 1;
R1 = I(0x11fe0);

I(0x11fe4) = I(0x11fe4) + R1;
I(0x11fe0) = 10;
R1 = I(0x11fe0);

I(0x11fe4) = I(0x11fe4) + R1;
I(0x11fe8) = I(0x11fe4);
R0=I(0x11fe8);
printf("%d\n",R0);
R0=I(0x11ffc);
printf("%d\n",R0);
R0=I(0x11fe8);
printf("%d\n",R0);
L 4:
R0 = I(0x11fe8) >= 1;
	IF(!R0) GT(5);
R0=I(0x11fe8);
printf("%d\n",R0);
I(0x11fe8) = I(0x11fe8) - 1;
	GT(4);
L 5:
GT(-2);
END
