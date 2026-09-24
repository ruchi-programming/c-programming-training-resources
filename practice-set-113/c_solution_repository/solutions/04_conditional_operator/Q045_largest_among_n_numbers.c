/*
Q45: Largest Among N Numbers

EXPLANATION:
Read n values and find the maximum.

ALGORITHM:
Read n; initialize max with first; scan remaining values.
*/

#include <stdio.h>
int main(void){ 
    int n; 
    scanf("%d",&n); 
    if(n<=0)
        return 0; 
    long long x,m; 
    scanf("%lld",&m); 
    for(int i=1;i<n;i++){
        scanf("%lld",&x);
        if(x>m)m=x;
    } 
    printf("%lld\n",m); 
    return 0; 
}
