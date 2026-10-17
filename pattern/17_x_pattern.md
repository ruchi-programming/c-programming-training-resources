# X Pattern

## Problem statement

Print an `n × n` grid with stars on the two diagonals and spaces elsewhere. The supplied program increments even `n` to the next odd number.

## Sample input and output

Input: `5`

```text
*   *
 * *
  *
 * *
*   *
```

## Step-by-step algorithm

1. If `n` is even, increase it by one. This makes a single central row and column possible, though the requested size changes by one for even inputs.
2. Visit every position `(i,j)` in the square using zero-based indices.
3. A position belongs to the main diagonal when `i == j`.
4. It belongs to the opposite diagonal when `i + j == n - 1`.
5. Print a star if either diagonal test is true; otherwise print a space. Finish each row with a newline.

## Dry run: think through the counters

For `n = 5`, the main diagonal positions are `(0,0)` through `(4,4)`. The opposite diagonal positions are `(0,4)`, `(1,3)`, `(2,2)`, `(3,1)`, `(4,0)`. They cross at `(2,2)`.

## Why this algorithm works

The main diagonal keeps row and column indices equal. The opposite diagonal has indices whose sum is the last valid index, `n-1`.

## Common mistakes to avoid

Using `i+j == n` shifts the opposite diagonal out of place. Using `&&` instead of `||` prints only the crossing point.

## Pseudocode

```text
if n is even: n = n+1
for i = 0..n-1:
    for j = 0..n-1:
        if i==j or i+j==n-1: print '*'
        else: print ' '
    print newline
```

## Complexity

All `n²` positions are tested, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
