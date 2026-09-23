/*
Q29: Day of Week

EXPLANATION:
Map integers 1–7 to day names using the stated range.

ALGORITHM:
Read n; select the corresponding day.

SOURCE NOTE / ASSUMPTIONS:
The PPT specifies only '1–7'; Monday=1 through Sunday=7 is a conventional assumption.
*/

#include <stdio.h>
int main(void){ int n; scanf("%d",&n); const char *d[]={"","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"}; if(n>=1&&n<=7) puts(d[n]); else puts("Invalid day"); return 0; }
