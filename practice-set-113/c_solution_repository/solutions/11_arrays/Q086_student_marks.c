/*
Q86: Student Marks

EXPLANATION:
Store 5 subject marks; calculate total and percentage.

ALGORITHM:
Read five marks into an array; sum them; divide by 5 for percentage when each subject is out of 100.
*/

#include <stdio.h>
int main(void){
    double m[5],sum=0;
    for(int i=0;i<5;i++){
        scanf("%lf",&m[i]);
        sum+=m[i];
    }
    printf("Total: %.2f\nPercentage: %.2f\n",sum,sum/5.0);
    return 0;
}
