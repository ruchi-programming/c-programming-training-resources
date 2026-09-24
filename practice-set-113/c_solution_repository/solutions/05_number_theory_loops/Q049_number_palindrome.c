/*
Q49: Number Palindrome

EXPLANATION:
A number is a palindrome if its reverse equals the original.

ALGORITHM:
Save original; reverse digits using % and /; compare.
*/

#include <stdio.h>
int main(void){ 
    long long n,t,r=0; 
    scanf("%lld",&n); 
    t=n<0?-n:n; 
    long long orig=t; 
    while(t){
        r=r*10+t%10;
        t/=10;
    } 
    puts(r==orig?"Palindrome":"Not Palindrome"); 
    return 0; 
}
