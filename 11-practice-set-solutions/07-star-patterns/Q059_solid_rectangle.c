/*
Q59: Solid Rectangle

EXPLANATION:
Print a rectangular block of stars.

ALGORITHM:
Use nested loops over rows and columns.

SOURCE NOTE / ASSUMPTIONS:
Pattern dimensions are taken from input where the PPT leaves them variable.
*/

#include <stdio.h>
int main(void){int r,c;scanf("%d%d",&r,&c);for(int i=0;i<r;i++){for(int j=0;j<c;j++)putchar('*');putchar('\n');}return 0;}
