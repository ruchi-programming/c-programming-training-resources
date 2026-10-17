#include <stdio.h>

/*
 * Pattern: Solid Square
 * Difficulty: Very Easy
 *
 * Problem:
 * Print n rows and n columns of stars. The outer loop selects each row; the inner loop prints n stars.
 *
 * Input / output:
 * Input: integer n. Output: n lines with n stars each.
 *
 * Step-by-step algorithm:
 * 1. Visit each row from 1 to n.
 *  * 2. For every row, visit all n columns and print a star at every position.
 *  * 3. Print a newline after each complete row.
 *
 * Suggested test: Try n=4.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void solidSquare(int n){
for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c ",'*');
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
    solidSquare(n);
    return 0;
}
