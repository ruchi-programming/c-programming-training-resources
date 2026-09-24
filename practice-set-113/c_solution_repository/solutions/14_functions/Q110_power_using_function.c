/*
Q110: Power Using Function

EXPLANATION:
Encapsulate exponentiation in a function.

ALGORITHM:
Define power(x,y); call it after reading x and y.
*/

#include <stdio.h>
#include <math.h>
double power(double x,double y){return pow(x,y);}
int main(void){double x,y;scanf("%lf%lf",&x,&y);printf("%.6f\n",power(x,y));return 0;}
