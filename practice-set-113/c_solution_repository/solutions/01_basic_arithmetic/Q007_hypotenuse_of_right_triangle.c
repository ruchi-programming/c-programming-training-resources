/*
Q7: Hypotenuse of Right Triangle

EXPLANATION:
Pythagoras gives h = sqrt(a²+b²).

ALGORITHM:
Read the two perpendicular sides; square and add; take square root.
*/

#include <stdio.h>
#include <math.h>
int main(void){ 
    double a,b; 
    scanf("%lf%lf",&a,&b); 
    printf("%.6f\n",sqrt(a*a+b*b)); 
    return 0; 
}
