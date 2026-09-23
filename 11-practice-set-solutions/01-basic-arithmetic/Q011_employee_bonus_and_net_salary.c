/*
Q11: Employee Bonus and Net Salary

EXPLANATION:
A 12% bonus is added to salary.

ALGORITHM:
Read number of employees and each salary; bonus=12%; net=salary+bonus; print each result.

SOURCE NOTE / ASSUMPTIONS:
The PPT says 'for employees' but does not specify the employee count/input format, so this solution reads n followed by n salaries.
*/

#include <stdio.h>
int main(void){ int n; scanf("%d",&n); for(int i=1;i<=n;i++){ double s; scanf("%lf",&s); double b=.12*s; printf("Employee %d: Bonus=%.2f Net=%.2f\n",i,b,s+b); } return 0; }
