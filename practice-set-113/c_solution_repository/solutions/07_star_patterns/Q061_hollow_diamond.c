/*
Q61: Hollow Diamond

EXPLANATION:
Print a diamond whose outline contains stars.

ALGORITHM:
For each row, calculate leading spaces and boundary star positions.

SOURCE NOTE / ASSUMPTIONS:
Pattern dimensions are taken from input where the PPT leaves them variable.
*/

#include <stdio.h>
int main(void){int n;scanf("%d",&n);for(int i=1;i<=n;i++){for(int s=0;s<n-i;s++)putchar(' ');for(int j=1;j<=2*i-1;j++)putchar(j==1||j==2*i-1?'*':' ');putchar('\n');}for(int i=n-1;i>=1;i--){for(int s=0;s<n-i;s++)putchar(' ');for(int j=1;j<=2*i-1;j++)putchar(j==1||j==2*i-1?'*':' ');putchar('\n');}return 0;}
