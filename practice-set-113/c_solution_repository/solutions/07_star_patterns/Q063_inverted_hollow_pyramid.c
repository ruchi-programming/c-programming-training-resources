/*
Q63: Inverted Hollow Pyramid

EXPLANATION:
Print an inverted pyramid with a hollow center.

ALGORITHM:
For each decreasing width, print boundary stars and spaces inside.

SOURCE NOTE / ASSUMPTIONS:
Pattern dimensions are taken from input where the PPT leaves them variable.
*/

#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=n;i>=1;i--){
        for(int s=0;s<n-i;s++)
            putchar(' ');
        for(int j=1;j<=2*i-1;j++)
            putchar(i==n||i==1||j==1||j==2*i-1?'*':' ');
        putchar('\n');
    }
    return 0;
}
