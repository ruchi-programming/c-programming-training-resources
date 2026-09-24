/*
Q84: Fibonacci Series

EXPLANATION:
Display the first n Fibonacci terms.

ALGORITHM:
Start with 0 and 1; repeatedly print and update the pair.
*/

#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    long long a=0,b=1;
    for(int i=0;i<n;i++){
        printf("%lld%c",a,i==n-1?'\n':' ');
        long long c=a+b;
        a=b;
        b=c;
    }
    return 0;
}
