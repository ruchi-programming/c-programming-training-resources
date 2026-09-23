/*
Q82: GCD of Two Numbers

EXPLANATION:
Use the Euclidean algorithm to find the greatest common divisor.

ALGORITHM:
Repeatedly replace (a,b) with (b,a%b) until b becomes zero.
*/

#include <stdio.h>
int main(void){long long a,b;scanf("%lld%lld",&a,&b);if(a<0)a=-a;if(b<0)b=-b;while(b){long long t=a%b;a=b;b=t;}printf("%lld\n",a);return 0;}
