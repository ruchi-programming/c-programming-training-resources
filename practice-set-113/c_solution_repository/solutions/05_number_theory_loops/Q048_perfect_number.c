/*
Q48: Perfect Number

EXPLANATION:
A perfect number equals the sum of its proper positive divisors.

ALGORITHM:
Read n; sum divisors below n; compare sum with n.
*/

#include <stdio.h>
int main(void){ 
    int n,sum=0; 
    scanf("%d",&n); 
    for(int i=1;i<=n/2;i++)
        if(n%i==0)
            sum+=i; 
    puts(n>0&&sum==n?"Perfect Number":"Not Perfect");
    return 0; 
}
