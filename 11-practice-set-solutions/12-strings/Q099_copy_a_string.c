/*
Q99: Copy a String

EXPLANATION:
Copy one character array into another.

ALGORITHM:
Read a source string; copy each character including '\0'.
*/

#include <stdio.h>
int main(void){char a[500],b[500];fgets(a,sizeof a,stdin);int i=0;while((b[i]=a[i])!='\0')i++;printf("%s",b);return 0;}
