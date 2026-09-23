/*
Q92: Largest and Second Largest

EXPLANATION:
Find the largest and second-largest values in an array of five.

ALGORITHM:
Track the top two distinct values while scanning.
*/

#include <stdio.h>
#include <limits.h>
int main(void){int a[5];for(int i=0;i<5;i++)scanf("%d",&a[i]);long long first=LLONG_MIN,second=LLONG_MIN;for(int i=0;i<5;i++){if(a[i]>first){second=first;first=a[i];}else if(a[i]>second&&a[i]!=first)second=a[i];}if(second==LLONG_MIN)puts("No distinct second largest value");else printf("Largest: %lld\nSecond largest: %lld\n",first,second);return 0;}
