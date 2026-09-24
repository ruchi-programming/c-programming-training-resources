/*
Q109: Addition Using Function

EXPLANATION:
Encapsulate addition in a user-defined function.

ALGORITHM:
Define add(a,b); read inputs; call function; print return value.
*/

#include <stdio.h>
double add(double a,double b){
    return a+b;
}
int main(void){
    double a,b;
    scanf("%lf%lf",&a,&b);
    printf("%.2f\n",add(a,b));
    return 0;
}
