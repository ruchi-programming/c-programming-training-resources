#include <stdio.h>

/*
 * Pattern: Hollow Right-Angled Triangle
 * Difficulty: Moderate
 *
 * Problem:
 * Stars form the first column, diagonal edge, and complete base. Interior positions are spaces.
 *
 * Input / output:
 * Input: integer n. Output: hollow right triangle.
 *
 * How the algorithm works:
 * - The outer loop controls the current row.
 * - The inner loop controls columns, spaces, or values printed on that row.
 * - Conditional patterns decide whether a position is a border, diagonal,
 *   center line, or ordinary interior position.
 *
 * Suggested test: Try n=5.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void hollowTriangle(int n){
 for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
             if(i==n || j==1 || j==i)
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
    hollowTriangle(n);
    return 0;
}
