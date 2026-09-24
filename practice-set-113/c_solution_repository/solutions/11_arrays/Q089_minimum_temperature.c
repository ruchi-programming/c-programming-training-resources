/*
Q89: Minimum Temperature

EXPLANATION:
Store 30 temperatures and find the minimum.

ALGORITHM:
Read 30 values; track the smallest.
*/

#include <stdio.h>
int main(void){double a[30],m;for(int i=0;i<30;i++)scanf("%lf",&a[i]);m=a[0];for(int i=1;i<30;i++)if(a[i]<m)m=a[i];printf("%.2f\n",m);return 0;}
