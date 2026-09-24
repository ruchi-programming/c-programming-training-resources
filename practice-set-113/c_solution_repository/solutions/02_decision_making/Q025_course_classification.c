/*
Q25: Course Classification

EXPLANATION:
Classify a student by marks into Degree, Diploma or Certificate.

ALGORITHM:
Read marks; use ordered ranges for the three categories.

SOURCE NOTE / ASSUMPTIONS:
The PPT gives category names but no mark cut-offs. The thresholds 75/50 are explicit assumptions for a runnable example.
*/

#include <stdio.h>
int main(void){ 
    double marks; 
    scanf("%lf",&marks); 
    if(marks>=75) 
        puts("Degree"); 
    else if(marks>=50) 
        puts("Diploma"); 
    else 
        puts("Certificate"); 
    return 0; 
}
