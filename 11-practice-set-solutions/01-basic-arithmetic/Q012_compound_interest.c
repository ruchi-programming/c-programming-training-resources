/*
Q12: Compound Interest

EXPLANATION:
Compound interest and maturity amount are calculated from principal, rate and number of periods.

ALGORITHM:
Read P,R,N; compute A=P(1+R/100)^N; CI=A-P.
*/

#include <stdio.h>
#include <math.h>
int main(void){ double p,r,n,a,ci; scanf("%lf%lf%lf",&p,&r,&n); a=p*pow(1+r/100.0,n); ci=a-p; printf("Compound Interest: %.2f\nMaturity Amount: %.2f\n",ci,a); return 0; }
