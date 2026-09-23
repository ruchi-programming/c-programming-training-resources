/*
Q34: Circle Operations

EXPLANATION:
Choose area, circumference or diameter.

ALGORITHM:
Read radius and choice; switch to calculate the requested property.

SOURCE NOTE / ASSUMPTIONS:
The PPT does not specify menu values; this implementation uses 1=area, 2=circumference, 3=diameter.
*/

#include <stdio.h>
int main(void){ double r; int ch; const double pi=3.141592653589793; scanf("%lf%d",&r,&ch); switch(ch){case 1:printf("%.6f\n",pi*r*r);break;case 2:printf("%.6f\n",2*pi*r);break;case 3:printf("%.6f\n",2*r);break;default:puts("Invalid choice");} return 0; }
