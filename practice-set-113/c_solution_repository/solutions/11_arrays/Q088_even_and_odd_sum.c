/*
Q88: Even and Odd Sum

EXPLANATION:
Store 5 numbers and separately sum even and odd values.

ALGORITHM:
Read five integers; test parity and add to the appropriate total.
*/

#include <stdio.h>
int main(void){
    int a[5],e=0,o=0;
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0)
            e+=a[i];
        else 
            o+=a[i];
    }
    printf("Even sum: %d\nOdd sum: %d\n",e,o);
    return 0;
}
