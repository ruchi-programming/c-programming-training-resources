/*
Q71: Break Statement

EXPLANATION:
Use break to stop at 4.

ALGORITHM:
Loop from 1 upward; break when the value reaches 5.
*/

#include <stdio.h>
int main(void){
    for(int i=1;i<=10;i++){
        if(i==5)
            break;
        printf("%d ",i);
    }
    putchar('\n');
    return 0;
}
