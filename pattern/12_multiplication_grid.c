#include <stdio.h>

/*
 * Pattern: Multiplication Table Grid
 * Difficulty: Moderate
 *
 * Problem:
 * The cell at row i and column j prints i*j. Two loops enumerate every cell.
 *
 * Input / output:
 * Input: integer n. Output: n-by-n multiplication grid.
 *
 * How the algorithm works:
 * - The outer loop controls the current row.
 * - The inner loop controls columns, spaces, or values printed on that row.
 * - Conditional patterns decide whether a position is a border, diagonal,
 *   center line, or ordinary interior position.
 *
 * Suggested test: Try n=3.
 * Constraint: Use n from 1 to 12.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void multiplicationTableGrid(int n){
for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%2d ",i*j);
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
    multiplicationTableGrid(n);
    return 0;
}
