/*
Q36: Grade Using Conditional Operator

EXPLANATION:
Assign A when percentage is at least 75, otherwise B.

ALGORITHM:
Read percentage; use conditional operator.
*/

#include <stdio.h>
int main(void){ 
    double p; 
    scanf("%lf",&p); 
    printf("%c\n",p>=75?'A':'B'); 
    return 0; 
}
