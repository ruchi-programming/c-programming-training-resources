/*
Q80: Sum of Digits

EXPLANATION:
Add all decimal digits.

ALGORITHM:
Take n%10, add it, then divide by 10 until no digits remain.
*/

#include <stdio.h>
int main(void){
    long long n,sum=0;
    scanf("%lld",&n);
    if(n<0)
        n=-n;
    while(n){
        sum+=n%10;
        n/=10;
    }
    printf("%lld\n",sum);
    return 0;
}
