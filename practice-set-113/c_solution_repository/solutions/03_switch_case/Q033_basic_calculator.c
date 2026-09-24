/*
Q33: Basic Calculator

EXPLANATION:
Select addition, subtraction, multiplication or division.

ALGORITHM:
Read two operands and an operator choice; use switch; guard division by zero.

SOURCE NOTE / ASSUMPTIONS:
The PPT does not specify menu values; this implementation uses 1=add, 2=subtract, 3=multiply, 4=divide.
*/

#include <stdio.h>
int main(void){ 
    double a,b; 
    int ch; 
    scanf("%lf%lf%d",&a,&b,&ch); 
    switch(ch){
        case 1:
            printf("%.2f\n",a+b);
            break;
        case 2:
            printf("%.2f\n",a-b);
            break;
        case 3:
            printf("%.2f\n",a*b);
            break;
        case 4:
            if(b==0)
                puts("Division by zero");
            else 
                printf("%.2f\n",a/b);
            break;
        default:
            puts("Invalid choice");
    } 
    return 0; 
}
