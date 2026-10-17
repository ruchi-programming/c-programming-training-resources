# Increasing Number Triangle

## Problem statement

In row `i`, print the numbers from 1 through `i`.

## Sample input and output

Input: `4`

```text
1
1 2
1 2 3
1 2 3 4
```

## Step-by-step algorithm

1. Choose row `i`, beginning at 1.
2. Start column counter `j` at 1. In this pattern, `j` is also the value to print.
3. Print `j` while `j <= i`, so each row counts upward from 1 to its row number.
4. After `j` passes `i`, end the line and advance to the next row.
5. The counter restarts at 1 for every new row; it does not continue from the previous row.

## Dry run: think through the counters

For `n = 3`: row 1 prints `j=1`; row 2 prints `j=1,2`; row 3 prints `j=1,2,3`. The value sequence restarts on each row.

## Why this algorithm works

The column index doubles as the displayed number. The row number determines the largest value allowed on that line.

## Common mistakes to avoid

Printing `i` instead of `j` repeats the row number. Declaring `j` outside the inner loop and not resetting it prevents later rows from starting at 1.

## Pseudocode

```text
for i = 1..n:
    for j = 1..i:
        print j
    print newline
```

## Complexity

There are `n(n+1)/2` printed numbers, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
