/*
Q79: Prime Numbers in Range

EXPLANATION:
Display primes between two limits.

ALGORITHM:
Read low/high; test each number for primality.
*/

#include <stdio.h>
int prime(int n){if(n<2)return 0;for(int i=2;i*i<=n;i++)if(n%i==0)return 0;return 1;}
int main(void){int a,b;scanf("%d%d",&a,&b);if(a>b){int t=a;a=b;b=t;}for(int n=a;n<=b;n++)if(prime(n))printf("%d ",n);putchar('\n');return 0;}
