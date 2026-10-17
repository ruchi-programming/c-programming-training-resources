# Floyd's Triangle

## Problem statement

Print consecutive positive integers in rows of increasing length: row 1 has one value, row 2 has two, and so on.

## Sample input and output

Input: `4`

```text
1
2 3
4 5 6
7 8 9 10
```

## Step-by-step algorithm

1. Initialize a single counter `value = 1` before entering the outer loop.
2. Choose row `i`. Its inner loop runs `i` times because the row must contain `i` values.
3. Print `value`, then increment it so the next position receives the next integer.
4. After `i` values, end the line. Keep the counter unchanged except for the increments; do not restart it on a new row.
5. Repeat until row `n` is complete.

## Dry run: think through the counters

For `n = 4`, the rows consume 1 value, then 2, then 3, then 4. The consecutive ranges are `1`; `2–3`; `4–6`; `7–10`.

## Why this algorithm works

The row loop determines the number of entries; the separate persistent counter determines their values. This is the key difference from a number triangle that restarts at 1.

## Common mistakes to avoid

Putting `value = 1` inside the outer loop restarts the sequence. Incrementing before printing makes the first number 2.

## Pseudocode

```text
value = 1
for i = 1..n:
    repeat i times:
        print value
        value = value + 1
    print newline
```

## Complexity

It prints `n(n+1)/2` numbers, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
