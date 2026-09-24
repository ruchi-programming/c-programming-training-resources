/*
Q6: Simple Interest

EXPLANATION:
Simple interest is P×R×N/100.

ALGORITHM:
Read P,R,N; calculate SI; print.
*/

#include <stdio.h>
int main(void){ 
    double p,r,n; 
    scanf("%lf%lf%lf",&p,&r,&n); 
    printf("%.2f\n",p*r*n/100.0); 
    return 0; 
}
