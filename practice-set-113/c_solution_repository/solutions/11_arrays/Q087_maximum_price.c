/*
Q87: Maximum Price

EXPLANATION:
Store prices of 10 items and find the maximum.

ALGORITHM:
Read 10 prices; track the largest value.
*/

#include <stdio.h>
int main(void){
    double a[10],m;
    for(int i=0;i<10;i++)
        scanf("%lf",&a[i]);
    m=a[0];
    for(int i=1;i<10;i++)
        if(a[i]>m)
            m=a[i];
    printf("%.2f\n",m);
    return 0;
}
