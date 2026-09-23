/*
Q20: Discount Based on Quantity

EXPLANATION:
Apply a 10% discount when quantity exceeds 1000.

ALGORITHM:
Read quantity and unit price; compute amount; if quantity>1000 reduce by 10%.
*/

#include <stdio.h>
int main(void){ int q; double p,total; scanf("%d%lf",&q,&p); total=q*p; if(q>1000) total*=.90; printf("%.2f\n",total); return 0; }
