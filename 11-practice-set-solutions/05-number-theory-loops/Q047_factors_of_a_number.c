/*
Q47: Factors of a Number

EXPLANATION:
Print every positive divisor.

ALGORITHM:
Read n; loop i=1..n and print values dividing n.
*/

#include <stdio.h>
int main(void){ int n; scanf("%d",&n); if(n<=0)return 0; for(int i=1;i<=n;i++)if(n%i==0)printf("%d ",i); putchar('\n'); return 0; }
