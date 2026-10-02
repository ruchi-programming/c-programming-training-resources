/* Q114: Write student details to a file and read them back.
Algorithm: read roll/name/marks; write a delimited record; reopen; read/display.
Assumption: one record per run; write mode replaces the previous file. */
#include <stdio.h>
int main(void) {
 int roll, r; char name[100], n[100]; float marks, m; FILE *f;
 printf("Roll number: "); if(scanf("%d",&roll)!=1) return 1;
 printf("Name: "); if(scanf(" %99[^\\n]",name)!=1) return 1;
 printf("Marks: "); if(scanf("%f",&marks)!=1) return 1;
 f=fopen("students.txt","w"); if(!f){perror("students.txt");return 1;}
 if(fprintf(f,"%d|%s|%.2f\\n",roll,name,marks)<0){perror("write");fclose(f);return 1;}
 if(fclose(f)!=0){perror("close");return 1;}
 f=fopen("students.txt","r"); if(!f){perror("students.txt");return 1;}
 if(fscanf(f,"%d|%99[^|]|%f",&r,n,&m)!=3){fprintf(stderr,"Invalid record\\n");fclose(f);return 1;}
 printf("\\nRoll: %d\\nName: %s\\nMarks: %.2f\\n",r,n,m); fclose(f); return 0;
}