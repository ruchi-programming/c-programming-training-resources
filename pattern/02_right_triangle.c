#include <stdio.h>

/*
 * Pattern: Right-Angled Star Triangle
 * Difficulty: Very Easy
 *
 * Problem:
 * Each row i prints i stars. The outer loop selects the row and the inner loop stops at that row number.
 *
 * Input / output:
 * Input: integer n. Output: n left-aligned rows.
 *
 * Step-by-step algorithm:
 * 1. Visit rows i = 1..n.
 *  * 2. On row i, print stars for columns j = 1..i.
 *  * 3. End the row; the star count therefore grows by one each time.
 *
 * Suggested test: Try n=4.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void rightTriangle(int n){
 for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
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
    rightTriangle(n);
    return 0;
}
