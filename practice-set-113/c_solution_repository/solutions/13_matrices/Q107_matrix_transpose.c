/*
Q107: Matrix Transpose

EXPLANATION:
Swap rows and columns of a 3×3 matrix.

ALGORITHM:
Read A; output A[j][i] at row i, column j.
*/

#include <stdio.h>
int main(void){
    int a[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%d%c",a[j][i],j==2?'\n':' ');
    }
    return 0;
}
