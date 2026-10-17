#include <stdio.h>

/*
 * Pattern: Hollow Pyramid
 * Difficulty: Moderate
 *
 * Problem:
 * Print leading spaces to center each row. Within the row, stars appear at the left edge, right edge, and entire base.
 *
 * Input / output:
 * Input: integer n. Output: centered hollow pyramid.
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

void hollowPattern(int n){
    // Outer loop for rows
    for (int i = 1; i <= n; i++) {
        // Print leading spaces for center alignment
        for (int k = i; k < n; k++) {
            printf(" ");
        }

        // Inner loop for columns in the current row
        for (int j = 1; j <= (2 * i - 1); j++) {
            // Print '*' for the left edge, right edge, or the entire bottom base row
            if (j == 1 || j == (2 * i - 1) || i == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        
        // Move to the next line after completing the row
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
    hollowPattern(n);
    return 0;
}
