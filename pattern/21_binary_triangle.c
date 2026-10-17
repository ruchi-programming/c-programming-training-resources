#include <stdio.h>

/*
 * Pattern: Alternating Binary Triangle
 * Difficulty: Easy–Moderate
 *
 * Problem:
 * The parity of row+column decides whether to print 1 or 0. The first value is 1.
 *
 * Input / output:
 * Input: integer n. Output: binary triangle.
 *
 * Step-by-step algorithm:
 * 1. Use zero-based rows i=0..n-1; row i has columns 0..i.
 *  * 2. Print 1 when i+j is even and 0 when it is odd.
 *  * 3. End each row; parity causes the values to alternate.
 *
 * Suggested test: Try n=5.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void printBinaryTriangle(int n) {
    int i, j;

    // Outer loop for rows
    for (i = 0; i < n; i++) {
        // Inner loop for columns (up to the current row number)
        for (j = 0; j <= i; j++) {
            // If the sum of row and column indices is even, print 1; else print 0
            if ((i + j) % 2 == 0) {
                printf("1 ");
            } else {
                printf("0 ");
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
    printBinaryTriangle(n);
    return 0;
}
