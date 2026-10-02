/* Q118: Count exact matches of a word in a file.
Algorithm: read whitespace-separated tokens and compare with strcmp.
Assumption: case-sensitive; punctuation stays attached to a token. */
#include <stdio.h>
#include <string.h>
int main(void) {
 char file[256],target[100],token[256]; FILE *f; long count=0;
 printf("File name: ");if(scanf("%255s",file)!=1)return 1;
 printf("Word to find: ");if(scanf("%99s",target)!=1)return 1;
 f=fopen(file,"r");if(!f){perror(file);return 1;}
 while(fscanf(f,"%255s",token)==1)if(strcmp(token,target)==0)count++;
 if(ferror(f)){perror("read");fclose(f);return 1;}
 printf("Occurrences of %s: %ld\\n",target,count);fclose(f);return 0;
}