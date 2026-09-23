/*
Q37: Triangle Classification

EXPLANATION:
Identify equilateral, isosceles, right-angled or none.

ALGORITHM:
Read sides; validate triangle; test equality and Pythagorean condition.
*/

#include <stdio.h>
#include <math.h>
int main(void){ long long a,b,c,x,y,z; scanf("%lld%lld%lld",&a,&b,&c); if(a<=0||b<=0||c<=0||a+b<=c||a+c<=b||b+c<=a){puts("None");return 0;} if(a==b&&b==c){puts("Equilateral");return 0;} if(a==b||b==c||a==c){puts("Isosceles");return 0;} x=a*a;y=b*b;z=c*c; if(x+y==z||x+z==y||y+z==x)puts("Right-angled"); else puts("None"); return 0; }
