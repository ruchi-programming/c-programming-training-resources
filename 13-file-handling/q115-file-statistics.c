/* Q115: Count bytes, whitespace-delimited words, and lines in a text file.
Algorithm: scan with fgetc; count bytes/newlines; detect word starts after whitespace.
A final nonempty line without newline counts as a line. */
#include <stdio.h>
#include <ctype.h>
int main(void) {
 char file[256]; FILE *f; int c,last='\\n',prev_space=1;
 long chars=0,words=0,lines=0;
 printf("File name: "); if(scanf("%255s",file)!=1)return 1;
 f=fopen(file,"r"); if(!f){perror(file);return 1;}
 while((c=fgetc(f))!=EOF){chars++; if(c=='\\n')lines++;
  if(isspace((unsigned char)c))prev_space=1;
  else {if(prev_space)words++;prev_space=0;} last=c;
 }
 if(ferror(f)){perror("read");fclose(f);return 1;}
 if(chars>0 && last!='\\n')lines++;
 printf("Characters (bytes): %ld\\nWords: %ld\\nLines: %ld\\n",chars,words,lines);
 fclose(f);return 0;
}