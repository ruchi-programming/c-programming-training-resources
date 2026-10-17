#include <stdio.h>

/*
 * Pattern: Right-Aligned Star Triangle
 * Difficulty: Easy
 *
 * Problem:
 * Each row first prints n-i leading blank groups, then i stars. The blank groups align the right edges.
 *
 * Input / output:
 * Input: integer n. Output: right-aligned triangle.
 *
 * Step-by-step algorithm:
 * 1. For row i, print n-i leading blank groups.
 *  * 2. Print i stars after the blanks.
 *  * 3. End the row; indentation decreases as the star count increases.
 *
 * Suggested test: Try n=4.
 * Constraint: Use n from 1 to 50.
 *
 * The implementation below follows the function provided in the supplied
 * patterns.C file. Each file is standalone and includes its own main().
 * Time complexity is generally O(n^2); extra space is O(1).
 */

void rightAlignedtriangle(int n,char c){
 for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            printf("  ");
        }
        for(int k=1;k<=i;k++){
            printf("%c ",c);
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
    rightAlignedtriangle(n, '*');
    return 0;
}
