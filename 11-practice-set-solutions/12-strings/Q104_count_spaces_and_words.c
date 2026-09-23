/*
Q104: Count Spaces and Words

EXPLANATION:
Count spaces and infer words in a whitespace-separated line.

ALGORITHM:
Count spaces; count transitions from whitespace to non-whitespace as word starts.
*/

#include <stdio.h>
#include <ctype.h>
int main(void){char s[1000];fgets(s,sizeof s,stdin);int spaces=0,words=0,in=0;for(int i=0;s[i];i++){if(s[i]==' ')spaces++;if(isspace((unsigned char)s[i]))in=0;else if(!in){words++;in=1;}}printf("Spaces: %d\nWords: %d\n",spaces,words);return 0;}
