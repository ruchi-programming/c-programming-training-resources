/*
Q102: String Palindrome

EXPLANATION:
A string is a palindrome when it equals its reverse.

ALGORITHM:
Read a line; compare symmetric characters from both ends.
*/

#include <stdio.h>
#include <string.h>
int main(void){char s[500];fgets(s,sizeof s,stdin);s[strcspn(s,"\n")]=0;size_t i=0,j=strlen(s);int ok=1;if(j)j--;while(i<j)if(s[i++]!=s[j--]){ok=0;break;}puts(ok?"Palindrome":"Not Palindrome");return 0;}
