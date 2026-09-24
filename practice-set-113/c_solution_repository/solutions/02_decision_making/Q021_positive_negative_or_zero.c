/*
Q21: Positive Negative or Zero

EXPLANATION:
Classify a number by its sign.

ALGORITHM:
Read n; compare with zero.
*/

#include <stdio.h>
int main(void){ 
    double n; 
    scanf("%lf",&n); 
    if(n>0) 
        puts("Positive"); 
    else if(n<0) 
        puts("Negative"); 
    else 
        puts("Zero"); 
    return 0; 
}
