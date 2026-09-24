/*
Q40: Electricity Bill

EXPLANATION:
Calculate a bill based on units consumed.

ALGORITHM:
Read units and apply slab rates.

SOURCE NOTE / ASSUMPTIONS:
The PPT does not provide slab rates. The rates in this file are explicit assumptions for a runnable example.
*/

#include <stdio.h>
int main(void){ 
    double u,b=0;
    scanf("%lf",&u); 
    if(u<=100)b=u*1.5; 
    else if(u<=200)
        b=100*1.5+(u-100)*2.5; 
    else if(u<=500)
        b=100*1.5+100*2.5+(u-200)*4.0; 
    else 
        b=100*1.5+100*2.5+300*4.0+(u-500)*6.0; 
        printf("%.2f\n",b); 
    return 0; 
}
