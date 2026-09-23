/*
Q52: Simple Interest for Three Sets

EXPLANATION:
Compute SI for three sets of P, R and N.

ALGORITHM:
Repeat three times: read P,R,N and print P×R×N/100.
*/

#include <stdio.h>
int main(void){ for(int i=1;i<=3;i++){double p,r,n;scanf("%lf%lf%lf",&p,&r,&n);printf("Set %d: %.2f\n",i,p*r*n/100.0);} return 0; }
