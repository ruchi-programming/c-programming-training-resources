/*
Q73: exit Function

EXPLANATION:
Terminate when incorrect credentials are entered.

ALGORITHM:
Read username/password; if they do not match the expected values, call exit(EXIT_FAILURE).

SOURCE NOTE / ASSUMPTIONS:
The PPT does not specify credential values; 'admin'/'1234' are demonstration values.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){char u[64],p[64];scanf("%63s%63s",u,p);if(strcmp(u,"admin")!=0||strcmp(p,"1234")!=0){puts("Incorrect credentials");exit(EXIT_FAILURE);}puts("Access granted");return 0;}
