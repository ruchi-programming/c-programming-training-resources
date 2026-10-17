# Hollow Centered Pyramid

## Problem statement

Print a centered pyramid whose sloping left and right edges are stars, while the inside is blank. The entire bottom row is filled to form the base.

## Sample input and output

Input: `5`

```text
    *
   * *
  *   *
 *     *
*********
```

## Step-by-step algorithm

1. For each row `i = 1..n`, print `n-i` leading spaces to center the row.
2. The row has `2*i-1` positions, which grows from 1 at the top to `2n-1` at the base.
3. Walk through each position `j` in that row. Print a star if `j == 1` (left edge) or `j == 2*i-1` (right edge).
4. Also print a star at every position when `i == n`, because the bottom row is the solid base.
5. Otherwise print an interior space. End the row with a newline.

## Dry run: think through the counters

For `n = 4`, row widths are 1,3,5,7 and leading spaces are 3,2,1,0. Rows 1–3 have stars only at the first and last positions; row 4 is all stars.

## Why this algorithm works

The first and last position of each row form the two sloping sides. The base condition fills the final row regardless of column position.

## Common mistakes to avoid

Leaving out `i == n` makes the base hollow. Using `j == 2*i` shifts the right edge one position too far.

## Pseudocode

```text
for i = 1..n:
    print n-i leading spaces
    for j = 1..(2*i-1):
        if j==1 or j==2*i-1 or i==n: print '*'
        else: print ' '
    print newline
```

## Complexity

The total row widths add up to O(n²), so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
