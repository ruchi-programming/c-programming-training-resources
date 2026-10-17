# Prime-Product Grid

**Difficulty:** Moderate

## Problem statement
For each cell, multiply its row and column. A helper function checks whether the product is prime; print P for prime and C otherwise.

## Input
integer n.

## Output
P/C grid.

## Algorithm explanation
1. Read `n` from standard input.
2. Use the outer loop to select the current row.
3. Use inner loops to print columns, symbols, spaces, or numeric values.
4. Use conditions where needed to identify boundaries, diagonals, the center, or prime products.
5. Print a newline after each completed row.

## Dry-run guidance
Try n=3. Trace the outer-loop row value, inner-loop counter, and any condition that determines the printed character.

## Complexity
- **Time:** O(n²) for the pattern loops. The prime-product grid additionally checks each product for primality.
- **Extra space:** O(1).

## Source
[`23_prime_product_grid.c`](23_prime_product_grid.c)

## Restrictions
No arrays, strings, dynamic memory allocation, or data structures are used. The programs use scalar variables, loops, conditions, and formatted input/output.
