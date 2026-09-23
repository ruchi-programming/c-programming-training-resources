/*
Q46: Prime Number

EXPLANATION:
A prime has exactly two positive divisors.

ALGORITHM:
Read n; reject n<2; test divisors from 2 through sqrt(n).
*/

#include <stdio.h>
int main(void){ long long n; scanf("%lld",&n); int prime=n>=2; for(long long i=2;i*i<=n&&prime;i++) if(n%i==0) prime=0; puts(prime?"Prime":"Not Prime"); return 0; }
