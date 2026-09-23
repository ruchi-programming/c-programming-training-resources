/*
Q31: Day Using Switch Case

EXPLANATION:
Use switch-case to map 1–7 to days.

ALGORITHM:
Read n; switch on n; print the matching day.
*/

#include <stdio.h>
int main(void){ int n; scanf("%d",&n); switch(n){case 1:puts("Monday");break;case 2:puts("Tuesday");break;case 3:puts("Wednesday");break;case 4:puts("Thursday");break;case 5:puts("Friday");break;case 6:puts("Saturday");break;case 7:puts("Sunday");break;default:puts("Invalid day");} return 0; }
