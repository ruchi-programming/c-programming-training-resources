#include <stdio.h>

/*
 * Pattern: Repeated-Number Triangle
 * Difficulty: Easy
 *
 * Problem:
 * The row counter is printed repeatedly. Row i prints the value i exactly i times.
 *
 * Input / output:
 * Input: integer n. Output: n rows of repeated row values.
 *
 * How the algorithm works:
 * - The outer loop controls the current row.
 * - The inner loop controls columns, spaces, or values printed on that row.
 * - Conditional patterns decide whether a position is a border, diagonal,
 *   center line, or ordinary interior position.
 *
 * Suggested test: Try n=4.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void repeatedNumberTriangle(int n){
 for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",i);
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
    repeatedNumberTriangle(n);
    return 0;
}
