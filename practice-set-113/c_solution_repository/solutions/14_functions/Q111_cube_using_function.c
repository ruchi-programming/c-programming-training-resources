/*
Q111: Cube Using Function

EXPLANATION:
Encapsulate cubing in a function.

ALGORITHM:
Define cube(x)=x*x*x; call it.
*/

#include <stdio.h>
double cube(double x){
    return x*x*x;
}
int main(void){
    double x;
    scanf("%lf",&x);
    printf("%.6f\n",cube(x));
    return 0;
}
