/*
Q60: Hollow Rectangle

EXPLANATION:
Only the boundary of the rectangle contains stars.

ALGORITHM:
Print star when row/column is on an edge; otherwise space.

SOURCE NOTE / ASSUMPTIONS:
Pattern dimensions are taken from input where the PPT leaves them variable.
*/

#include <stdio.h>
int main(void){int r,c;scanf("%d%d",&r,&c);for(int i=0;i<r;i++){for(int j=0;j<c;j++)putchar(i==0||i==r-1||j==0||j==c-1?'*':' ');putchar('\n');}return 0;}
