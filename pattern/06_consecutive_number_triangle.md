# Consecutive-Number Triangle (Filling Across Rows)

## Problem statement

Print consecutive integers in triangular rows. Unlike the increasing-number triangle, the number does not restart at 1 on each row.

## Sample input and output

Input: `4`

```text
  1
  2   3
  4   5   6
  7   8   9  10
```

## Step-by-step algorithm

1. Create one value counter `x = 1` before the outer row loop. Its position outside the loop is important: it must survive row changes.
2. Choose row `i`. The row needs `i` values, so run the inner loop `i` times.
3. Print `x`, then increment `x` immediately. The next column receives the next integer.
4. After printing `i` values, move to the next line. Do not reset `x`.
5. Continue until `n` rows have been printed. Row lengths grow, while the value counter keeps increasing continuously.

## Dry run: think through the counters

For `n = 4`: row 1 consumes `1`; row 2 consumes `2,3`; row 3 consumes `4,5,6`; row 4 consumes `7,8,9,10`. The counter after row 4 is 11.

## Why this algorithm works

The inner loop controls how many values belong in the current row; `x` independently tracks the next value globally. `%3d` in the code reserves a fixed-width field to align values.

## Common mistakes to avoid

Resetting `x = 1` inside the outer loop restarts every row. Forgetting `x++` repeats the same number.

## Pseudocode

```text
x = 1
for i = 1..n:
    repeat i times:
        print x in a fixed-width field
        x = x + 1
    print newline
```

## Complexity

Exactly `n(n+1)/2` values are printed, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
