/*
Q55: Decreasing Number Pattern

EXPLANATION:
Print rows beginning at 5 and ending at progressively smaller numbers.

ALGORITHM:
For row length 5 down to 1, print 5 down to the row endpoint.
*/

#include <stdio.h>
int main(void){
    for(int end=1;end<=5;end++){
        for(int x=5;x>=end;x--)
            printf("%d%c",x,x==end?'\n':' ');
    }
    return 0;
}
