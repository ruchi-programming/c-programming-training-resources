/*
Q95: String Length

EXPLANATION:
Count characters until the null terminator.

ALGORITHM:
Read a line; count characters excluding the newline.
*/

#include <stdio.h>
#include <string.h>
int main(void){char s[500];fgets(s,sizeof s,stdin);s[strcspn(s,"\n")]=0;printf("%zu\n",strlen(s));return 0;}
