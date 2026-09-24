/*
Q65: Diamond Pattern

EXPLANATION:
Print a solid diamond.

ALGORITHM:
Print an increasing centered pyramid followed by its decreasing half.

SOURCE NOTE / ASSUMPTIONS:
Pattern dimensions are taken from input where the PPT leaves them variable.
*/

#include <stdio.h>
int main(void){int n;scanf("%d",&n);for(int r=1;r<=n;r++){for(int s=0;s<n-r;s++)putchar(' ');for(int c=0;c<2*r-1;c++)putchar('*');putchar('\n');}for(int r=n-1;r>=1;r--){for(int s=0;s<n-r;s++)putchar(' ');for(int c=0;c<2*r-1;c++)putchar('*');putchar('\n');}return 0;}
