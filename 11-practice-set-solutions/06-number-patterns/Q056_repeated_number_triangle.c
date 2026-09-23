/*
Q56: Repeated Number Triangle

EXPLANATION:
Row r contains r repeated r times.

ALGORITHM:
Outer loop chooses row; inner loop prints row number.
*/

#include <stdio.h>
int main(void){for(int r=1;r<=4;r++){for(int c=1;c<=r;c++)printf("%d%c",r,c==r?'\n':' ');}return 0;}
