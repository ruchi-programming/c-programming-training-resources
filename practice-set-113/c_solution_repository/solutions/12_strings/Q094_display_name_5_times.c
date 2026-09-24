/*
Q94: Display Name 5 Times

EXPLANATION:
Print the input name five times.

ALGORITHM:
Read the name; loop five times.
*/

#include <stdio.h>
int main(void){
    char name[200];
    scanf("%199s",name);
    for(int i=0;i<5;i++)
        puts(name);
    return 0;
}
