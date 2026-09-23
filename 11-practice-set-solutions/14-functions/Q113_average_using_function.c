/*
Q113: Average Using Function

EXPLANATION:
Calculate the average of three values through a function.

ALGORITHM:
Define average(a,b,c); return their sum divided by 3.
*/

#include <stdio.h>
double average(double a,double b,double c){return (a+b+c)/3.0;}
int main(void){double a,b,c;scanf("%lf%lf%lf",&a,&b,&c);printf("%.2f\n",average(a,b,c));return 0;}
