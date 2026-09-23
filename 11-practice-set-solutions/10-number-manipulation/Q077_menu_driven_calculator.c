/*
Q77: Menu Driven Calculator

EXPLANATION:
Repeatedly calculate square, square root or cube until exit.

ALGORITHM:
Display menu; read choice; perform selected operation; repeat until exit choice.

SOURCE NOTE / ASSUMPTIONS:
The PPT does not specify menu numbers; this version uses 1=square, 2=square root, 3=cube, 4=exit.
*/

#include <stdio.h>
#include <math.h>
int main(void){int ch;double x;do{scanf("%d",&ch);if(ch==4)break;if(ch<1||ch>4){puts("Invalid choice");continue;}scanf("%lf",&x);if(ch==1)printf("%.6f\n",x*x);else if(ch==2){if(x<0)puts("Invalid square root");else printf("%.6f\n",sqrt(x));}else if(ch==3)printf("%.6f\n",x*x*x);}while(1);return 0;}
