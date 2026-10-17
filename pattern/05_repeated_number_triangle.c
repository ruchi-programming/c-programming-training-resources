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
 * Step-by-step algorithm:
 * 1. Visit rows i = 1..n.
 *  * 2. Repeat i times, printing i each time; i chooses the value and j counts copies.
 *  * 3. End the row.
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
