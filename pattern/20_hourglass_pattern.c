#include <stdio.h>

/*
 * Pattern: Hollow Hourglass
 * Difficulty: Moderate
 *
 * Problem:
 * The upper half narrows to a single star and the lower half widens again. Stars are printed on the outline and the top/bottom edges.
 *
 * Input / output:
 * Input: odd integer n recommended. Output: hollow hourglass.
 *
 * Step-by-step algorithm:
 * 1. Compute mid=n/2 and print the upper half with growing indentation and width 2(mid-i)+1.
 *  * 2. Keep stars on both edges; fill the top row to make the top edge solid.
 *  * 3. Print the lower half with width 2i+1; fill the last row to close the bottom edge.
 *
 * Suggested test: Try n=7.
 * Constraint: Use an odd n from 3 to 31 for a symmetric hourglass.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void hourglassPattern(int n){
    int mid = n / 2;

    // --- UPPER HALF (including the middle vertex row) ---
    for (int i = 0; i <= mid; i++) {
        // Print leading spaces
        for (int space = 0; space < i; space++) {
            printf(" ");
        }
        // Print stars and inner spaces
        for (int j = 0; j < (2 * (mid - i) + 1); j++) {
            // Print '*' on the outer boundaries or the very first row
            if (i == 0 || j == 0 || j == (2 * (mid - i))) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // --- LOWER HALF ---
    for (int i = 1; i <= mid; i++) {
        // Print leading spaces
        for (int space = 0; space < mid - i; space++) {
            printf(" ");
        }
        // Print stars and inner spaces
        for (int j = 0; j < (2 * i + 1); j++) {
            // Print '*' on the outer boundaries or the very last row
            if (i == mid || j == 0 || j == (2 * i)) {
                printf("*");
            } else {
                printf(" ");
            }
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
    hourglassPattern(n);
    return 0;
}
