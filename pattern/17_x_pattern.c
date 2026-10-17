#include <stdio.h>

/*
 * Pattern: X Pattern
 * Difficulty: Easy–Moderate
 *
 * Problem:
 * Print a star when the position lies on either diagonal; print a space elsewhere. Even n is increased to the next odd size by the supplied function.
 *
 * Input / output:
 * Input: integer n. Output: X pattern; even input is adjusted to odd.
 *
 * Step-by-step algorithm:
 * 1. If n is even, increase it by one so the diagonals cross at the center.
 *  * 2. Visit every zero-based cell (i,j).
 *  * 3. Print a star when i==j or i+j==n-1; otherwise print a space.
 *
 * Suggested test: Try n=5.
 * Constraint: n must be between 1 and 50. If n is even, the supplied function increases it by one.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void xPattern(int n){
    if(n%2==0)n++;
    // Outer loop for rows
    for (int i = 0; i < n; i++) {
        // Inner loop for columns
        for (int j = 0; j < n; j++) {
            // Check if current position is on the main diagonal or anti-diagonal
            if (i == j || (i + j) == n - 1) {
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
    xPattern(n);
    return 0;
}
