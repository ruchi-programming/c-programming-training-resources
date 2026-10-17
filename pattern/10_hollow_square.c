#include <stdio.h>

/*
 * Pattern: Hollow Square
 * Difficulty: Moderate
 *
 * Problem:
 * A position is on the border if it is in the first/last row or first/last column. All other positions are blank.
 *
 * Input / output:
 * Input: integer n. Output: hollow n-by-n square.
 *
 * Step-by-step algorithm:
 * 1. Visit every cell in the n-by-n grid.
 *  * 2. Print X if the cell is in the first/last row or first/last column.
 *  * 3. Print spaces for interior cells, then end each row.
 *
 * Suggested test: Try n=5.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void hollowSquare(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1 || i==n || j==1 || j==n)
                printf("%c ",'X');
            else
                printf("  ");
        }
        printf("\n");
    }
}


int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Please enter one integer n.\\n");
        return 1;
    }
    hollowSquare(n);
    return 0;
}
