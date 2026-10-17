#include <stdio.h>

/*
 * Pattern: Number Triangle
 * Difficulty: Easy
 *
 * Problem:
 * The inner loop prints the column counter, from 1 through the current row number.
 *
 * Input / output:
 * Input: integer n. Output: row i contains 1 through i.
 *
 * Step-by-step algorithm:
 * 1. Visit rows i = 1..n.
 *  * 2. Print column counter j from 1 through i, so the values restart at 1 on each row.
 *  * 3. End the row.
 *
 * Suggested test: Try n=4.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void numberTriangle(int n){
 for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",j);
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
    numberTriangle(n);
    return 0;
}
