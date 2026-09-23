/*
Q16: Divisible by 3 and 5

EXPLANATION:
Check both divisibility conditions.

ALGORITHM:
Read n; test n%3==0 && n%5==0.
*/

#include <stdio.h>
int main(void){ int n; scanf("%d",&n); printf(n%3==0 && n%5==0?"Divisible by 3 and 5\n":"Not divisible by both\n"); return 0; }
