/*
Q93: Hello + Name

EXPLANATION:
Read a name and display it with Hello.

ALGORITHM:
Read a whitespace-free name; prefix with Hello.

SOURCE NOTE / ASSUMPTIONS:
The PPT does not specify whether names may contain spaces; this version reads one token.
*/

#include <stdio.h>
int main(void){char name[200];scanf("%199s",name);printf("Hello %s\n",name);return 0;}
