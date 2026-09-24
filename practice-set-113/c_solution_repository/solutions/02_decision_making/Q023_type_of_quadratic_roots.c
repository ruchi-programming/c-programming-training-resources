/*
Q23: Type of Quadratic Roots

EXPLANATION:
Use the discriminant b²−4ac to classify roots.

ALGORITHM:
Read a,b,c; calculate discriminant; positive=real unequal, zero=real equal, negative=imaginary.
*/

#include <stdio.h>
int main(void){ 
    double a,b,c,d; 
    scanf("%lf%lf%lf",&a,&b,&c); 
    if(a==0){
        puts("Not a quadratic equation");
        return 0;
    } 
    d=b*b-4*a*c; 
    if(d>0)
        puts("Real and unequal"); 
    else if(d==0)
        puts("Real and equal"); 
    else 
        puts("Imaginary"); 
    return 0; 
}
