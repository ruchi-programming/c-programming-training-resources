/*
Q90: Employee Salary Statistics

EXPLANATION:
Store salaries of 10 employees and calculate total and average.

ALGORITHM:
Read 10 salaries; sum them; divide by 10.
*/

#include <stdio.h>
int main(void){double s[10],total=0;for(int i=0;i<10;i++){scanf("%lf",&s[i]);total+=s[i];}printf("Total: %.2f\nAverage: %.2f\n",total,total/10.0);return 0;}
