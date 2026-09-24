/*
Q57: Increasing Star Triangle

EXPLANATION:
Print 1 to 5 stars by row.

ALGORITHM:
For row r, print r stars.
*/

#include <stdio.h>
int main(void){
    for(int r=1;r<=5;r++){
        for(int c=1;c<=r;c++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
