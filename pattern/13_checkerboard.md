# Checkerboard Pattern

## Problem statement

Print an `n × n` grid whose adjacent positions alternate between two symbols/values according to the parity of row plus column.

## Sample input and output

Input: `4`

```text
X O X O
O X O X
X O X O
O X O X
```

## Step-by-step algorithm

1. Visit each row `i` and each column `j`.
2. Add the row and column indices: `i + j`.
3. If the sum is even, print the first symbol; if odd, print the second symbol. In a 1-based grid, `(1,1)` has sum 2, so it gets the first symbol.
4. Continue across the row, then print a newline.
5. On the next row, the parity flips for each same column, so the starting symbol alternates.

## Dry run: think through the counters

For a 4×4 grid, row 1 has sums 2,3,4,5 → first, second, first, second. Row 2 has sums 3,4,5,6 → second, first, second, first.

## Why this algorithm works

Moving one step right or down changes `i+j` by exactly 1, which flips even/odd parity. That guarantees neighboring cells alternate.

## Common mistakes to avoid

Using only `i % 2` makes each row uniform. Reversing the even/odd outputs swaps the starting symbol but keeps the checkerboard property.

## Pseudocode

```text
for i = 1..n:
    for j = 1..n:
        if (i+j) is even: print first symbol
        else: print second symbol
    print newline
```

## Complexity

Every cell is visited once, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
