/*
Q28: Quadratic Equation Roots

EXPLANATION:
Calculate quadratic roots from a,b,c using the quadratic formula.

ALGORITHM:
Read a,b,c; compute discriminant; print real roots when available.
*/

#include <stdio.h>
#include <math.h>
int main(void){ double a,b,c,d; scanf("%lf%lf%lf",&a,&b,&c); if(a==0){puts("Not quadratic");return 0;} d=b*b-4*a*c; if(d>0) printf("Root1=%.6f\nRoot2=%.6f\n",(-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a)); else if(d==0) printf("Root=%.6f\n",-b/(2*a)); else { double real=-b/(2*a), imag=sqrt(-d)/(2*a); printf("Root1=%.6f + %.6fi\nRoot2=%.6f - %.6fi\n",real,imag,real,imag); } return 0; }
