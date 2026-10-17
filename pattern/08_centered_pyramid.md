# Centered Solid Star Pyramid

## Problem statement

Print a centered pyramid. Row `i` has `2i-1` stars, with a decreasing number of leading blank groups.

## Sample input and output

Input: `4`

```text
      *
    * * *
  * * * * *
* * * * * * *
```

## Step-by-step algorithm

1. Start row `i` at 1.
2. Print `n-i` leading blank groups. This moves the shorter upper rows toward the center.
3. Print the rising half: `i` stars. The loop runs `k = 1..i`.
4. Print the falling half: `i-1` more stars. It starts at `i-1` so the peak is not printed twice.
5. End the line and increase `i`. The total star count is `i + (i-1) = 2i-1`.

## Dry run: think through the counters

For `n = 3`: row 1 has 2 blank groups and 1 star; row 2 has 1 blank group and 3 stars; row 3 has no leading blank groups and 5 stars.

## Why this algorithm works

A centered pyramid needs both indentation and an odd star count. Splitting the stars into `i` and `i-1` produces 1, 3, 5, ... stars.

## Common mistakes to avoid

Using `i` for both star loops produces `2i` stars, an even count. Starting the second loop at `i` repeats the peak star.

## Pseudocode

```text
for i = 1..n:
    print n-i blank groups
    print i stars
    print i-1 stars
    print newline
```

## Complexity

The row widths grow linearly and there are `n` rows, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
