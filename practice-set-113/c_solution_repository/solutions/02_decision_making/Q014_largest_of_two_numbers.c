/*
Q14: Largest of Two Numbers

EXPLANATION:
Compare two values and print the larger.

ALGORITHM:
Read a,b; if a>b print a, otherwise print b.
*/

#include <stdio.h>
int main(void){ 
    double a,b; 
    scanf("%lf%lf",&a,&b); 
    printf("%.2f\n",a>b?a:b); 
    return 0;
 }
