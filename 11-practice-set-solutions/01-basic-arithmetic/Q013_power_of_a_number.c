/*
Q13: Power of a Number

EXPLANATION:
Calculate x raised to y.

ALGORITHM:
Read x,y; use pow(x,y); print.
*/

#include <stdio.h>
#include <math.h>
int main(void){ double x,y; scanf("%lf%lf",&x,&y); printf("%.6f\n",pow(x,y)); return 0; }
