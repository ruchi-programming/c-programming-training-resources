/*
Q3: Area of Circle

EXPLANATION:
Use πr².

ALGORITHM:
Read radius; calculate pi*r*r; print.
*/

#include <stdio.h>
int main(void){ 
    double r; 
    const double pi=3.141592653589793; 
    scanf("%lf",&r); 
    printf("%.6f\n",pi*r*r); 
    return 0; 
}
