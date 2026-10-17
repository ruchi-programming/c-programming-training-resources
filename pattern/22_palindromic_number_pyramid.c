#include <stdio.h>

/*
 * Pattern: Palindromic Number Pyramid
 * Difficulty: Moderate
 *
 * Problem:
 * Each row prints 1 through the row number, then returns downward to 1. Leading spaces center the row.
 *
 * Input / output:
 * Input: integer n. Output: centered palindromic number pyramid.
 *
 * How the algorithm works:
 * - The outer loop controls the current row.
 * - The inner loop controls columns, spaces, or values printed on that row.
 * - Conditional patterns decide whether a position is a border, diagonal,
 *   center line, or ordinary interior position.
 *
 * Suggested test: Try n=5.
 * Constraint: Use n from 1 to 9 for clean single-digit alignment.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void printPalindromicPyramid(int n) {
    int i, j, space;

    // Outer loop for each row
    for (i = 1; i <= n; i++) {
        // 1. Print leading spaces for center alignment
        for (space = i; space < n; space++) {
            printf("  "); // Using double spaces for clean spacing with double-digit numbers
        }

        // 2. Print increasing numbers from 1 to i
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        // 3. Print decreasing numbers from i-1 down to 1 (the palindrome second half)
        for (j = i - 1; j >= 1; j--) {
            printf("%d ", j);
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
    printPalindromicPyramid(n);
    return 0;
}
