/*
Q70: Valid Square Root Input

EXPLANATION:
Keep asking until a non-negative number is entered, then show its square root.

ALGORITHM:
Loop while input is negative; stop when valid; calculate sqrt.
*/

#include <stdio.h>
#include <math.h>
int main(void){
    double x;
    do{
        scanf("%lf",&x);
        if(x<0)
            puts("Enter a non-negative number");
        }while(x<0);
    printf("%.6f\n",sqrt(x));
    return 0;
    }
