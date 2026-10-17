#include <stdio.h>

/*
 * Pattern: Floyd's Triangle
 * Difficulty: Easy–Moderate
 *
 * Problem:
 * A single counter continues increasing as triangular rows are printed.
 *
 * Input / output:
 * Input: integer n. Output: consecutive integers in triangular rows.
 *
 * Step-by-step algorithm:
 * 1. Initialize value=1 before the row loop.
 *  * 2. On row i, print i consecutive values, incrementing after each print.
 *  * 3. Preserve value across rows and end each row after i numbers.
 *
 * Suggested test: Try n=4.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void floydTriangle(int n){
    int x=1;
 for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",x++);
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
    floydTriangle(n);
    return 0;
}
