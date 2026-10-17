#include <stdio.h>

/*
 * Pattern: Plus Sign Pattern
 * Difficulty: Easy
 *
 * Problem:
 * Print stars across the middle row and middle column. Even n is increased to the next odd size by the supplied function.
 *
 * Input / output:
 * Input: integer n. Output: plus sign; even input is adjusted to odd.
 *
 * How the algorithm works:
 * - The outer loop controls the current row.
 * - The inner loop controls columns, spaces, or values printed on that row.
 * - Conditional patterns decide whether a position is a border, diagonal,
 *   center line, or ordinary interior position.
 *
 * Suggested test: Try n=5.
 * Constraint: n must be between 1 and 50. If n is even, the supplied function increases it by one.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void plusPattern(int n){
    if(n%2==0)n++;
    int mid = n / 2; // Calculate the middle index

    // Outer loop for rows
    for (int i = 0; i < n; i++) {
        // Inner loop for columns
        for (int j = 0; j < n; j++) {
            // Check if current position is on the middle row or middle column
            if (i == mid || j == mid) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        // Move to the next line after each row is complete
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
    plusPattern(n);
    return 0;
}
