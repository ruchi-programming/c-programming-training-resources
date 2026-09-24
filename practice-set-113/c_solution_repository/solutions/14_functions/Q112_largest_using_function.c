/*
Q112: Largest Using Function

EXPLANATION:
Find the larger of two numbers through a function.

ALGORITHM:
Define max2(a,b); return the greater; print it.
*/

#include <stdio.h>
double max2(double a,double b){
    return a>b?a:b;
}
int main(void){
    double a,b;
    scanf("%lf%lf",&a,&b);
    printf("%.2f\n",max2(a,b));
    return 0;
}
