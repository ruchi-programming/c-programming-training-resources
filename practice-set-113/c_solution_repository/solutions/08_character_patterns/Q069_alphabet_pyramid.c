/*
Q69: Alphabet Pyramid

EXPLANATION:
Print A, AB, ABC, ... up to the requested number of rows.

ALGORITHM:
For row r, print letters A through the r-th letter.
*/

#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    for(int r=1;r<=n;r++){
        for(int c=0;c<r;c++)
            printf("%c",'A'+c);
        putchar('\n');
    }return 0;
}
