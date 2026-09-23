/*
Q35: Largest of Two Without If Else

EXPLANATION:
Use the conditional operator to select the larger value.

ALGORITHM:
Read a,b; result=(a>b)?a:b.
*/

#include <stdio.h>
int main(void){ int a,b; scanf("%d%d",&a,&b); printf("%d\n",a>b?a:b); return 0; }
