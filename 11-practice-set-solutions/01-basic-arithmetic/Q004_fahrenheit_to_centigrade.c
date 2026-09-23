/*
Q4: Fahrenheit to Centigrade

EXPLANATION:
Convert using C = (F - 32) * 5/9.

ALGORITHM:
Read F; apply formula; print C.
*/

#include <stdio.h>
int main(void){ double f; scanf("%lf",&f); printf("%.2f\n",(f-32.0)*5.0/9.0); return 0; }
