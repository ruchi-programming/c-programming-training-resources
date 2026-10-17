# Hollow Right-Angled Triangle

## Problem statement

Print a left-aligned right triangle with stars on its two sloping/vertical edges and along the base; interior positions are blank.

## Sample input and output

Input: `5`

```text
X
X X
X   X
X     X
X X X X X
```

## Step-by-step algorithm

1. Choose row `i` from 1 to `n`. The row has positions `j = 1..i`, so the triangle's width grows with the row number.
2. For each position, test whether it is the left edge (`j == 1`), the diagonal/right edge (`j == i`), or the final row (`i == n`).
3. Print a star when any test is true. Otherwise print spaces to keep the triangle's interior hollow.
4. After processing positions 1 through `i`, print a newline.
5. On row `n`, the base condition is true for every column, so the entire last row is filled.

## Dry run: think through the counters

For `n = 4`: row 1 is both left edge and diagonal; row 2 has stars at columns 1 and 2; row 3 at columns 1 and 3; row 4 is entirely stars because `i == n`.

## Why this algorithm works

Within the triangular region, the diagonal is the last valid column, `j == i`. The base is handled separately because all its columns must be stars.

## Common mistakes to avoid

Without `i == n`, the bottom row has only its endpoints. Testing `j == n` instead of `j == i` does not track the sloping edge.

## Pseudocode

```text
for i = 1..n:
    for j = 1..i:
        if j==1 or j==i or i==n: print 'X'
        else: print spaces
    print newline
```

## Complexity

The triangle visits `n(n+1)/2` positions, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
