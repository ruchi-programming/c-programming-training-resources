/*
Q41: Student Grade

EXPLANATION:
Assign A, B, C or Fail from marks.

ALGORITHM:
Read marks; choose an ordered grade range.

SOURCE NOTE / ASSUMPTIONS:
The PPT names A/B/C/Fail but does not provide cut-offs; 75/60/40 are explicit assumptions.
*/

#include <stdio.h>
int main(void){ double m; scanf("%lf",&m); if(m>=75)puts("A"); else if(m>=60)puts("B"); else if(m>=40)puts("C"); else puts("Fail"); return 0; }
