/*
Q97: Convert to Uppercase

EXPLANATION:
Convert every character to uppercase.

ALGORITHM:
Read a line; traverse characters with toupper.
*/

#include <stdio.h>
#include <ctype.h>
int main(void){
    char s[500];
    fgets(s,sizeof s,stdin);
    for(int i=0;s[i];i++)
        s[i]=(char)toupper((unsigned char)s[i]);printf("%s",s);
    return 0;
}
