/*
Q91: Divisibility Count

EXPLANATION:
Store 5 numbers and count values divisible by both 3 and 5.

ALGORITHM:
Read five integers; increment the counter when both modulo tests are zero.
*/

#include <stdio.h>
int main(void){
    int a[5],count=0;
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
        if(a[i]%3==0&&a[i]%5==0)count++;
    }
    printf("%d\n",count);
    return 0;
}
