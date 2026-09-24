/*
Q50: Reverse a Number

EXPLANATION:
Build the reversed number digit by digit.

ALGORITHM:
Read n; repeatedly take last digit and append to reverse.
*/

#include <stdio.h>
int main(void){ 
    long long n,r=0; 
    scanf("%lld",&n); 
    int sign=n<0?-1:1; 
    if(n<0)
        n=-n; 
    while(n){
        r=r*10+n%10;
        n/=10;
    } 
    printf("%lld\n",sign*r); 
    return 0; 
}
