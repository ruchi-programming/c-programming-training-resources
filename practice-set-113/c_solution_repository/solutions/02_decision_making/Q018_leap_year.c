/*
Q18: Leap Year

EXPLANATION:
A leap year is divisible by 400, or divisible by 4 but not 100.

ALGORITHM:
Read year; apply the standard leap-year condition.
*/

#include <stdio.h>
int main(void){ 
    int y; 
    scanf("%d",&y); 
    puts((y%400==0||(y%4==0&&y%100!=0))?"Leap Year":"Non-Leap Year"); 
    return 0;
}
