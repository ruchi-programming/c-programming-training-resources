#include <stdio.h>

/*
 * Pattern: Checkerboard
 * Difficulty: Moderate
 *
 * Problem:
 * The parity of row+column chooses X or O. Adjacent cells therefore alternate.
 *
 * Input / output:
 * Input: integer n. Output: n-by-n checkerboard.
 *
 * Step-by-step algorithm:
 * 1. Visit every row i and column j.
 *  * 2. Print X when i+j is even and O when it is odd.
 *  * 3. Adjacent cells flip parity, so neighboring symbols alternate.
 *
 * Suggested test: Try n=4.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void checkerboard(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c ",(i+j)%2==0?'X':'O');
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
    checkerboard(n);
    return 0;
}
