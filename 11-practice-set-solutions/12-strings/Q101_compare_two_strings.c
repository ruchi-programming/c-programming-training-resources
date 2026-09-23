/*
Q101: Compare Two Strings

EXPLANATION:
Determine whether two strings are equal.

ALGORITHM:
Read two lines; compare characters or use strcmp.
*/

#include <stdio.h>
#include <string.h>
int main(void){char a[500],b[500];fgets(a,sizeof a,stdin);fgets(b,sizeof b,stdin);a[strcspn(a,"\n")]=0;b[strcspn(b,"\n")]=0;puts(strcmp(a,b)==0?"Equal":"Not Equal");return 0;}
