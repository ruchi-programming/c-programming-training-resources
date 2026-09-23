/*
Q43: Smallest of Three Numbers

EXPLANATION:
Find the minimum of three values.

ALGORITHM:
Initialize minimum with first; compare the other two.
*/

#include <stdio.h>
int main(void){ double a,b,c,m; scanf("%lf%lf%lf",&a,&b,&c); m=a; if(b<m)m=b; if(c<m)m=c; printf("%.2f\n",m); return 0; }
