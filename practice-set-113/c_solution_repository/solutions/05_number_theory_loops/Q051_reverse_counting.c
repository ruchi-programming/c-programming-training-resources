/*
Q51: Reverse Counting

EXPLANATION:
Print 10 down to 1.

ALGORITHM:
Start at 10 and decrement until 1.
*/

#include <stdio.h>
int main(void){ 
    for(int i=10;i>=1;i--)
        printf("%d%c",i,i==1?'\n':' '); 
    return 0; 
}
