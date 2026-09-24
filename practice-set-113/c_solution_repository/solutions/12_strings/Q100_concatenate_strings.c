/*
Q100: Concatenate Strings

EXPLANATION:
Append one string to another.

ALGORITHM:
Read two lines; find end of first; copy second from there.
*/

#include <stdio.h>
#include <string.h>
int main(void){
    char a[1000],b[500];
    fgets(a,sizeof a,stdin);
    fgets(b,sizeof b,stdin);
    a[strcspn(a,"\n")]=0;
    b[strcspn(b,"\n")]=0;
    size_t i=strlen(a),j=0;
    while(b[j])
        a[i++]=b[j++];
    a[i]=0;
    puts(a);
    return 0;
}
