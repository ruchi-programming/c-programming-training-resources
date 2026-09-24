/*
Q75: Number Palindrome

EXPLANATION:
Check whether a number equals its reverse.

ALGORITHM:
Reverse the number and compare with the original magnitude.
*/

#include <stdio.h>
int main(void){
    long long n,t,r=0;
    scanf("%lld",&n);
    t=n<0?-n:n;
    long long o=t;
    while(t){
        r=r*10+t%10;
        t/=10;
    }
    puts(r==o?"Palindrome":"Not Palindrome");
    return 0;
}
