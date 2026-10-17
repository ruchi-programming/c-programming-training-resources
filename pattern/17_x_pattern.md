# X Pattern

**Difficulty:** Easy–Moderate

## Problem statement
Print a star when the position lies on either diagonal; print a space elsewhere. Even n is increased to the next odd size by the supplied function.

## Input
integer n.

## Output
X pattern; even input is adjusted to odd.

## Algorithm explanation
1. Read `n` from standard input.
2. Use the outer loop to select the current row.
3. Use inner loops to print columns, symbols, spaces, or numeric values.
4. Use conditions where needed to identify boundaries, diagonals, the center, or prime products.
5. Print a newline after each completed row.

## Dry-run guidance
Try n=5. Trace the outer-loop row value, inner-loop counter, and any condition that determines the printed character.

## Complexity
- **Time:** O(n²) for the pattern loops. The prime-product grid additionally checks each product for primality.
- **Extra space:** O(1).

## Source
[`17_x_pattern.c`](17_x_pattern.c)

## Restrictions
No arrays, strings, dynamic memory allocation, or data structures are used. The programs use scalar variables, loops, conditions, and formatted input/output.
