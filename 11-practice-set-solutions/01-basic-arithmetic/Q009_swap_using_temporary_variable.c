/*
Q9: Swap Using Temporary Variable

EXPLANATION:
Use a third variable to exchange two values.

ALGORITHM:
Store a in temp; put b in a; put temp in b.
*/

#include <stdio.h>
int main(void){ int a,b,t; scanf("%d%d",&a,&b); t=a; a=b; b=t; printf("%d %d\n",a,b); return 0; }
