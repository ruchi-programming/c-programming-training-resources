#include <stdio.h>

/*
 * Pattern: Diamond Pattern
 * Difficulty: Moderate
 *
 * Problem:
 * Print an increasing pyramid, then a decreasing pyramid without repeating the widest row.
 *
 * Input / output:
 * Input: integer n. Output: centered diamond.
 *
 * Step-by-step algorithm:
 * 1. Print an increasing centered pyramid: n-i blank groups and 2i-1 stars.
 *  * 2. Print a decreasing half starting at i=n-1, so the widest row is not duplicated.
 *  * 3. Each lower row uses the same indentation and star-width formulas.
 *
 * Suggested test: Try n=4.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void diamondPattern(int n){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
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
    diamondPattern(n);
    return 0;
}
