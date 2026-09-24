/*
Q53: Repeated Number Rows

EXPLANATION:
Print three rows containing 1 2 3 4 5.

ALGORITHM:
Use nested loops; outer loop controls rows, inner loop prints 1..5.
*/

#include <stdio.h>
int main(void){
    for(int r=0;r<3;r++){
        for(int c=1;c<=5;c++)
            printf("%d%c",c,c==5?'\n':' ');
    }
    return 0;
}
