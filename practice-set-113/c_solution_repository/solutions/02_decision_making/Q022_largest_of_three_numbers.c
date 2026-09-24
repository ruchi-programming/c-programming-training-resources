/*
Q22: Largest of Three Numbers

EXPLANATION:
Find the maximum of three values.

ALGORITHM:
Read a,b,c; compare each against the current maximum.
*/

#include <stdio.h>
int main(void){ 
    double a,b,c,m; 
    scanf("%lf%lf%lf",&a,&b,&c); 
    m=a; 
    if(b>m)
        m=b; 
    if(c>m)
        m=c; 
    printf("%.2f\n",m); 
    return 0; 
}
