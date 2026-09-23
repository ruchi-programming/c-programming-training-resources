/*
Q38: Largest of Three Applicants

EXPLANATION:
Find the highest score among three applicants.

ALGORITHM:
Read three scores; track the maximum.
*/

#include <stdio.h>
int main(void){ double a,b,c,m; scanf("%lf%lf%lf",&a,&b,&c); m=a; if(b>m)m=b; if(c>m)m=c; printf("%.2f\n",m); return 0; }
