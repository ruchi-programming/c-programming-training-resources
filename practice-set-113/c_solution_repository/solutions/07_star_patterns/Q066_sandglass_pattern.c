/*
Q66: Sandglass Pattern

EXPLANATION:
Print widths n down to 1 and back up.

ALGORITHM:
Use one decreasing loop and one increasing loop.

SOURCE NOTE / ASSUMPTIONS:
Pattern dimensions are taken from input where the PPT leaves them variable.
*/

#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    for(int r=n;r>=1;r--){
        for(int c=0;c<r;c++)
            putchar('*');
        putchar('\n');
    }
    for(int r=2;r<=n;r++){
        for(int c=0;c<r;c++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
