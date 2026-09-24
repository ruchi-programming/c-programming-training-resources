/*
Q98: Reverse a String

EXPLANATION:
Print characters from the last character to the first.

ALGORITHM:
Read a line; find its length; print backwards.
*/

#include <stdio.h>
#include <string.h>
int main(void){char s[500];fgets(s,sizeof s,stdin);s[strcspn(s,"\n")]=0;size_t n=strlen(s);for(size_t i=n;i>0;i--)putchar(s[i-1]);putchar('\n');return 0;}
