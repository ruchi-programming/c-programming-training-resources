/*
Q105: Student Marks Matrix

EXPLANATION:
Store marks for 3 students and 5 subjects and display the two requested cells.

ALGORITHM:
Read a 3×5 matrix; print element [0][1] and [2][4].
*/

#include <stdio.h>
int main(void){int a[3][5];for(int i=0;i<3;i++)for(int j=0;j<5;j++)scanf("%d",&a[i][j]);printf("Student 1, Subject 2: %d\n",a[0][1]);printf("Student 3, Subject 5: %d\n",a[2][4]);return 0;}
