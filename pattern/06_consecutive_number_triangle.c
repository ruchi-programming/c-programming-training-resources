#include <stdio.h>

/*
 * Pattern: Consecutive-Number Triangle
 * Difficulty: Easy
 *
 * Problem:
 * A single counter is initialized before the outer loop and continues increasing across row boundaries.
 *
 * Input / output:
 * Input: integer n. Output: consecutive integers in triangular rows.
 *
 * Step-by-step algorithm:
 * 1. Initialize x=1 once, before the row loop.
 *  * 2. On row i, print i values; after each print, increment x.
 *  * 3. Keep x across row boundaries so the sequence never restarts.
 *
 * Suggested test: Try n=4.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void ConsecutiveNumberTriangle(int n){
    int x=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%3d ",x++);
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
    ConsecutiveNumberTriangle(n);
    return 0;
}
