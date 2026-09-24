/*
Q74: Mirror Image of Number

EXPLANATION:
Reverse the digits; e.g. 1234 becomes 4321.

ALGORITHM:
Repeatedly take the last digit and append it to the result.
*/

#include <stdio.h>
int main(void){
    long long n,r=0;
    scanf("%lld",&n);
    int sign=n<0?-1:1;
    if(n<0)n=-n;
    while(n){
        r=r*10+n%10;
        n/=10;
    }
    printf("%lld\n",sign*r);
    return 0;
}
