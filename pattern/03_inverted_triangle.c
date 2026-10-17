#include <stdio.h>

/*
 * Pattern: Inverted Star Triangle
 * Difficulty: Easy
 *
 * Problem:
 * The number of stars decreases by one on each row. Row i prints n-i+1 stars.
 *
 * Input / output:
 * Input: integer n. Output: n rows from n stars down to 1.
 *
 * Step-by-step algorithm:
 * 1. Visit rows i = 1..n.
 *  * 2. Print n-i+1 stars on row i.
 *  * 3. End the row; the star count drops from n to 1.
 *
 * Suggested test: Try n=4.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void invertedTriangle2(int n){
for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
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
    invertedTriangle2(n);
    return 0;
}
