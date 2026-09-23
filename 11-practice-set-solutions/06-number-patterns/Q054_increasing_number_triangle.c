/*
Q54: Increasing Number Triangle

EXPLANATION:
Print rows whose length increases from 1 to 5.

ALGORITHM:
For row r, print numbers 1..r.
*/

#include <stdio.h>
int main(void){for(int r=1;r<=5;r++){for(int c=1;c<=r;c++)printf("%d%c",c,c==r?'\n':' ');}return 0;}
