/*
Q15: Even or Odd

EXPLANATION:
An integer is even when divisible by 2.

ALGORITHM:
Read n; test n%2; print classification.
*/

#include <stdio.h>
int main(void){ long long n; scanf("%lld",&n); printf(n%2==0?"Even\n":"Odd\n"); return 0; }
