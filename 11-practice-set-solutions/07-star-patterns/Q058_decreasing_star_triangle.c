/*
Q58: Decreasing Star Triangle

EXPLANATION:
Print 5 to 1 stars by row.

ALGORITHM:
For row r, print 6-r stars.
*/

#include <stdio.h>
int main(void){for(int r=5;r>=1;r--){for(int c=1;c<=r;c++)putchar('*');putchar('\n');}return 0;}
