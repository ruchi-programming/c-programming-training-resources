/*
Q62: Hollow Right Triangle

EXPLANATION:
Create a right triangle with an empty interior.

ALGORITHM:
Print star on the left edge, bottom edge, and diagonal edge.

SOURCE NOTE / ASSUMPTIONS:
Pattern dimensions are taken from input where the PPT leaves them variable.
*/

#include <stdio.h>
int main(void){int n;scanf("%d",&n);for(int i=1;i<=n;i++){for(int j=1;j<=i;j++)putchar(j==1||j==i||i==n?'*':' ');putchar('\n');}return 0;}
