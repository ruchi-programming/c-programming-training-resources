/* Q117: Copy source file to destination, preserving arbitrary bytes.
Algorithm: open rb/wb; copy chunks with fread/fwrite; check errors; close.
Destination is overwritten if it already exists. */
#include <stdio.h>
int main(void) {
 char src[256],dst[256]; unsigned char buf[4096]; size_t n; FILE *in,*out;
 printf("Source file: ");if(scanf("%255s",src)!=1)return 1;
 printf("Destination file: ");if(scanf("%255s",dst)!=1)return 1;
 in=fopen(src,"rb");if(!in){perror(src);return 1;}
 out=fopen(dst,"wb");if(!out){perror(dst);fclose(in);return 1;}
 while((n=fread(buf,1,sizeof buf,in))>0)
  if(fwrite(buf,1,n,out)!=n){perror("write");fclose(in);fclose(out);return 1;}
 if(ferror(in)){perror("read");fclose(in);fclose(out);return 1;}
 if(fclose(in)!=0 || fclose(out)!=0){perror("close");return 1;}
 puts("Copy complete.");return 0;
}