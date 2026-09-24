/*
Q42: Salary Category

EXPLANATION:
Use nested if to classify salary as Low, Medium or High.

ALGORITHM:
Read salary; compare against thresholds.

SOURCE NOTE / ASSUMPTIONS:
The PPT gives categories but no salary thresholds; 30,000 and 70,000 are explicit assumptions.
*/

#include <stdio.h>
int main(void){ 
    double s; 
    scanf("%lf",&s); 
    if(s<30000)
        puts("Low"); 
    else { 
        if(s<70000)
            puts("Medium"); 
        else 
            puts("High"); 
    } 
    return 0; 
}
