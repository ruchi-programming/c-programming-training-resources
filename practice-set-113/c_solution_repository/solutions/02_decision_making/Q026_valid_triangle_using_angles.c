/*
Q26: Valid Triangle Using Angles

EXPLANATION:
Three angles form a triangle when they are positive and sum to 180°.

ALGORITHM:
Read three angles; check positivity and sum.
*/

#include <stdio.h>
int main(void){ 
    int a,b,c; 
    scanf("%d%d%d",&a,&b,&c); 
    puts(a>0&&b>0&&c>0&&a+b+c==180?"Valid Triangle":"Invalid Triangle"); 
    return 0; 
}
