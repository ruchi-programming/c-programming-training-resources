/*
Q108: Matrix Multiplication

EXPLANATION:
Multiply A(m×n) by B(p×q) only when n=p.

ALGORITHM:
Read dimensions and matrices; validate n==p; compute C[i][j] as the sum of A[i][k]B[k][j].

SOURCE NOTE / ASSUMPTIONS:
The PPT does not specify a maximum dynamic matrix size; this implementation supports dimensions up to 50×50.
*/

#include <stdio.h>
int main(void){int m,n,p,q;scanf("%d%d%d%d",&m,&n,&p,&q);if(m<=0||n<=0||p<=0||q<=0||n!=p){puts("Invalid dimensions for multiplication");return 0;}int A[50][50],B[50][50],C[50][50]={0};for(int i=0;i<m;i++)for(int j=0;j<n;j++)scanf("%d",&A[i][j]);for(int i=0;i<p;i++)for(int j=0;j<q;j++)scanf("%d",&B[i][j]);for(int i=0;i<m;i++)for(int j=0;j<q;j++)for(int k=0;k<n;k++)C[i][j]+=A[i][k]*B[k][j];for(int i=0;i<m;i++){for(int j=0;j<q;j++)printf("%d%c",C[i][j],j==q-1?'\n':' ');}return 0;}
