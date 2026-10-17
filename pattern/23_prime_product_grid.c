#include <stdio.h>
#include <stdbool.h>

/*
 * Pattern: Prime-Product Grid
 * Difficulty: Moderate
 *
 * Problem:
 * Print an n-by-n grid. At row i and column j, calculate i*j.
 * Print P if the product is prime; otherwise print C.
 *
 * Algorithm:
 * 1. isPrime checks whether a number has a divisor from 2 through sqrt(number).
 * 2. The outer loop chooses each row.
 * 3. The inner loop chooses each column and computes row*col.
 * 4. Print P or C based on the primality test.
 *
 * Sample input: 3
 * Sample output:
 * C C P
 * C C C
 * P C C
 *
 * Time complexity: O(n^3) for this simple grid and divisor-checking method.
 * Extra space: O(1).
 * No arrays, strings, dynamic memory allocation, or data structures are used.
 */

bool isPrime(int number)
{
    if (number < 2) {
        return false;
    }

    for (int divisor = 2; divisor * divisor <= number; divisor++) {
        if (number % divisor == 0) {
            return false;
        }
    }
    return true;
}

void printPrimeProductGrid(int n)
{
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            int product = row * col;
            printf("%c ", isPrime(product) ? 'P' : 'C');
        }
        printf("\n");
    }
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n < 2 || n > 20) {
        return 1;
    }

    printPrimeProductGrid(n);
    return 0;
}
