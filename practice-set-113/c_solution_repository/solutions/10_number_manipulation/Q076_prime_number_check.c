/*
Q76: Prime Number Check

EXPLANATION:
Check whether a number has no divisor other than 1 and itself.

ALGORITHM:
Test divisors through sqrt(n).
*/

#include <stdio.h>
int main(void){int n,p=1;scanf("%d",&n);if(n<2)p=0;for(int i=2;i*i<=n&&p;i++)if(n%i==0)p=0;puts(p?"Prime":"Not Prime");return 0;}
