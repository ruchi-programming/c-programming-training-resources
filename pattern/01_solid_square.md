# Solid Square Pattern

## Problem statement

Read `n` and print an `n × n` block of stars. Every row has exactly `n` stars.

## Sample input and output

Input: `4`

```text
* * * *
* * * *
* * * *
* * * *
```

## Step-by-step algorithm

1. Start the row counter `i` at 1. It identifies which line is being printed.
2. For each row, start a fresh column counter `j` at 1. The column loop runs all the way to `n`, regardless of the row number.
3. Print `* ` once for every column. Because every row uses the same column limit, every line has the same width.
4. After the inner loop finishes, print a newline. Then advance to the next row.
5. Stop after row `n`; the result has `n` rows and `n` stars per row.

## Dry run: think through the counters

For `n = 3`: row 1 prints at columns 1, 2, 3; row 2 again prints at columns 1, 2, 3; row 3 does the same. No condition is needed inside the grid because every position is filled.

## Why this algorithm works

A filled square has no special border or interior rule. Every `(row, column)` position is a star, so the inner loop has the constant limit `n`.

## Common mistakes to avoid

Using `j <= i` accidentally makes a triangle. Forgetting the newline puts all stars on one line.

## Pseudocode

```text
for each row i = 1..n:
    for each column j = 1..n:
        print "* "
    print newline
```

## Complexity

The program prints `n²` stars, so time is O(n²). It uses only loop counters, so extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
