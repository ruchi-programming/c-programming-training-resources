/*
Q96: Convert to Lowercase

EXPLANATION:
Convert every character to lowercase.

ALGORITHM:
Read a line; traverse characters with tolower.
*/

#include <stdio.h>
#include <ctype.h>
int main(void){
    char s[500];
    fgets(s,sizeof s,stdin);
    for(int i=0;s[i];i++)
    s[i]=(char)tolower((unsigned char)s[i]);printf("%s",s);
    return 0;
}
