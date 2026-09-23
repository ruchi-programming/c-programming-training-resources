/*
Q68: Plus Pattern

EXPLANATION:
Create a plus/cross symbol using +.

ALGORITHM:
For an odd-sized square, print + at the center row or center column.

SOURCE NOTE / ASSUMPTIONS:
Pattern dimensions are taken from input where the PPT leaves them variable.
*/

#include <stdio.h>
int main(void){int n;scanf("%d",&n);int m=n/2;for(int i=0;i<n;i++){for(int j=0;j<n;j++)putchar(i==m||j==m?'+':' ');putchar('\n');}return 0;}
