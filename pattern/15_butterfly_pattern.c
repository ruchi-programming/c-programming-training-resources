#include <stdio.h>

/*
 * Pattern: Butterfly Pattern
 * Difficulty: Moderate
 *
 * Problem:
 * The upper half widens toward the center; the lower half mirrors it. Each row prints left stars, a gap, and right stars.
 *
 * Input / output:
 * Input: odd integer n. Output: butterfly with n rows.
 *
 * How the algorithm works:
 * - The outer loop controls the current row.
 * - The inner loop controls columns, spaces, or values printed on that row.
 * - Conditional patterns decide whether a position is a border, diagonal,
 *   center line, or ordinary interior position.
 *
 * Suggested test: Try n=5.
 * Constraint: Use an odd n from 3 to 31 for a symmetric butterfly.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void butterflyPattern(int n){
    int half = (n + 1) / 2;

    for (int i = 1; i <= half; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        for (int j = 1; j <= n - 2 * i + 1; j++) {
            printf("  ");
        }
        for (int k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }

    for (int i = half - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        for (int j = 1; j <= n - 2 * i + 1; j++) {
            printf("  ");
        }
        for (int k = 1; k <= i; k++) {
            printf("* ");
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
    butterflyPattern(n);
    return 0;
}
