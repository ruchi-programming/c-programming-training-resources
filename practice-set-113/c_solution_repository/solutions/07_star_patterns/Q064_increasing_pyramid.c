/*
Q64: Increasing Pyramid

EXPLANATION:
Print odd-width star rows: 1,3,5,...

ALGORITHM:
For row r, print n-r leading spaces then 2r-1 stars.

SOURCE NOTE / ASSUMPTIONS:
Pattern dimensions are taken from input where the PPT leaves them variable.
*/

#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    for(int r=1;r<=n;r++){
        for(int s=0;s<n-r;s++)
            putchar(' ');
        for(int c=0;c<2*r-1;c++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
