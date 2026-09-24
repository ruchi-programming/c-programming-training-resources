/*
Q44: Absolute Value

EXPLANATION:
Print the non-negative magnitude of an integer.

ALGORITHM:
Read n; if negative negate it; print.
*/

#include <stdio.h>
int main(void){ 
    long long n; 
    scanf("%lld",&n); 
    if(n<0)
        n=-n; 
    printf("%lld\n",n); 
    return 0; 
}
