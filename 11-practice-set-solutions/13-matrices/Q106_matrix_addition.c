/*
Q106: Matrix Addition

EXPLANATION:
Add two 3×3 matrices element by element.

ALGORITHM:
Read both matrices; for each cell calculate A[i][j]+B[i][j].
*/

#include <stdio.h>
int main(void){int a[3][3],b[3][3];for(int i=0;i<3;i++)for(int j=0;j<3;j++)scanf("%d",&a[i][j]);for(int i=0;i<3;i++)for(int j=0;j<3;j++)scanf("%d",&b[i][j]);for(int i=0;i<3;i++){for(int j=0;j<3;j++)printf("%d%c",a[i][j]+b[i][j],j==2?'\n':' ');}return 0;}
