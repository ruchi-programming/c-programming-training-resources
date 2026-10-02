/* Q116: Append a transaction record without erasing prior records.
Algorithm: collect fields; open log in append mode; write one line; close.
Format: ID|description|amount */
#include <stdio.h>
int main(void) {
 int id; char desc[160]; double amount; FILE *f;
 printf("Transaction ID: ");if(scanf("%d",&id)!=1)return 1;
 printf("Description: ");if(scanf(" %159[^\\n]",desc)!=1)return 1;
 printf("Amount: ");if(scanf("%lf",&amount)!=1)return 1;
 f=fopen("transactions.txt","a");if(!f){perror("transactions.txt");return 1;}
 if(fprintf(f,"%d|%s|%.2f\\n",id,desc,amount)<0){perror("write");fclose(f);return 1;}
 if(fclose(f)!=0){perror("close");return 1;}
 puts("Transaction appended.");return 0;
}