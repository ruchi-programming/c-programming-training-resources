/*
Q39: Leap Year Validation

EXPLANATION:
Determine whether a year has 366 days.

ALGORITHM:
Use the standard leap-year condition.
*/

#include <stdio.h>
int main(void){ 
    int y; 
    scanf("%d",&y); 
    puts((y%400==0||(y%4==0&&y%100!=0))?"366 days":"365 days"); 
    return 0; 
}
