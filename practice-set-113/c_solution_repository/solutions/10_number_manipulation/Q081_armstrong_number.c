/*
Q81: Armstrong Number

EXPLANATION:
Check whether a number equals the sum of the cubes of its digits.

ALGORITHM:
Extract each digit, cube it, add cubes, compare with original.

SOURCE NOTE / ASSUMPTIONS:
The PPT's example/definition specifically uses cubes, so this implementation follows that definition.
*/

#include <stdio.h>
int main(void){
    int n,t,sum=0;
    scanf("%d",&n);
    if(n<0){
        puts("Not Armstrong");
        return 0;
    }
    t=n;
    do{
        int d=t%10;
        sum+=d*d*d;
        t/=10;
    }while(t);
    puts(sum==n?"Armstrong":"Not Armstrong");
    return 0;
}
