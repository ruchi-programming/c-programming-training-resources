/*
Q30: Divisibility Check

EXPLANATION:
Determine whether the first number is divisible by the second.

ALGORITHM:
Read a,b; ensure divisor is nonzero; test a%b==0.
*/

#include <stdio.h>
int main(void){ long long a,b; scanf("%lld%lld",&a,&b); if(b==0) puts("Division by zero is undefined"); else puts(a%b==0?"Divisible":"Not divisible"); return 0; }
