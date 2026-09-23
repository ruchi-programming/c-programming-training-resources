/*
Q78: Multiplication Table

EXPLANATION:
Generate the multiplication table of an integer.

ALGORITHM:
Read n; multiply it by 1 through 10.
*/

#include <stdio.h>
int main(void){int n;scanf("%d",&n);for(int i=1;i<=10;i++)printf("%d x %d = %d\n",n,i,n*i);return 0;}
