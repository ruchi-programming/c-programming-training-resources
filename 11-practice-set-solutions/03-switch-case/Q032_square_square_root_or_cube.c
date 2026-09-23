/*
Q32: Square Square Root or Cube

EXPLANATION:
Perform an operation selected by the user.

ALGORITHM:
Read choice and number; switch: 1 square, 2 square root, 3 cube.

SOURCE NOTE / ASSUMPTIONS:
The PPT does not specify numeric menu values; this implementation uses 1/2/3.
*/

#include <stdio.h>
#include <math.h>
int main(void){ int ch; double x; scanf("%d%lf",&ch,&x); switch(ch){case 1:printf("%.6f\n",x*x);break;case 2: if(x<0)puts("Invalid square root"); else printf("%.6f\n",sqrt(x));break;case 3:printf("%.6f\n",x*x*x);break;default:puts("Invalid choice");} return 0; }
