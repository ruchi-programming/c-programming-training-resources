/*
Q67: Butterfly Pattern

EXPLANATION:
Print two mirrored star triangles separated by spaces.

ALGORITHM:
For each row, compute left/right star counts and middle gap.

SOURCE NOTE / ASSUMPTIONS:
Pattern dimensions are taken from input where the PPT leaves them variable.
*/

#include <stdio.h>
int main(void){int n;scanf("%d",&n);for(int i=1;i<=n;i++){for(int j=0;j<i;j++)putchar('*');for(int s=0;s<2*(n-i);s++)putchar(' ');for(int j=0;j<i;j++)putchar('*');putchar('\n');}for(int i=n;i>=1;i--){for(int j=0;j<i;j++)putchar('*');for(int s=0;s<2*(n-i);s++)putchar(' ');for(int j=0;j<i;j++)putchar('*');putchar('\n');}return 0;}
