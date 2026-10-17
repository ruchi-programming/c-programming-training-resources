# Hollow Square Pattern

## Problem statement

Print an `n × n` square with stars only on the outside border. Interior positions are spaces.

## Sample input and output

Input: `5`

```text
X X X X X
X       X
X       X
X       X
X X X X X
```

## Step-by-step algorithm

1. Loop over every row `i` from 1 to `n`, and every column `j` from 1 to `n`.
2. At each position, ask whether it lies on the border: first row (`i == 1`), last row (`i == n`), first column (`j == 1`), or last column (`j == n`).
3. If any one of those tests is true, print a star; otherwise print a blank field.
4. After all `n` columns are processed, print a newline.
5. Repeat for all rows. The condition fills all four edges while leaving the interior empty.

## Dry run: think through the counters

For `n = 4`, all positions in rows 1 and 4 are stars. In rows 2 and 3, only columns 1 and 4 are stars; columns 2 and 3 are blank.

## Why this algorithm works

A border cell must touch at least one edge. The condition is an OR (`||`) because touching any edge is enough.

## Common mistakes to avoid

Using `&&` would require a position to be on all edges simultaneously, so most border stars disappear. Forgetting `i == n` or `j == n` leaves the bottom or right edge open.

## Pseudocode

```text
for i = 1..n:
    for j = 1..n:
        if i==1 or i==n or j==1 or j==n: print '*'
        else: print ' '
    print newline
```

## Complexity

Every grid position is visited, giving O(n²) time and O(1) extra space.

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
