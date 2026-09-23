/*
Q85: Armstrong Numbers in a Range

EXPLANATION:
Display numbers in a range that equal the sum of the cubes of their digits.

ALGORITHM:
For every number, compute digit-cube sum and compare.
*/

#include <stdio.h>
int arm(int n){int t=n,s=0;do{int d=t%10;s+=d*d*d;t/=10;}while(t);return s==n;}
int main(void){int a,b;scanf("%d%d",&a,&b);if(a>b){int t=a;a=b;b=t;}for(int n=a;n<=b;n++)if(n>=0&&arm(n))printf("%d ",n);putchar('\n');return 0;}
