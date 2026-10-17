# Inverted Centered Pyramid

## Problem statement

Print a centered pyramid upside down: the first row is widest and each following row loses two stars while gaining indentation.

## Sample input and output

Input: `4`

```text
* * * * * * *
  * * * * *
    * * *
      *
```

## Step-by-step algorithm

1. Begin at row `i = 1`.
2. Print `i-1` leading blank groups, so indentation grows as the pyramid narrows.
3. Calculate the star count as `2*(n-i)+1`: it begins at `2n-1` and drops by two each row.
4. Print that many stars, then end the line.
5. Advance `i` until `n`. On the final row, the formula gives one star.

## Dry run: think through the counters

For `n = 4`, star counts are 7, 5, 3, 1 and blank-group counts are 0, 1, 2, 3.

## Why this algorithm works

The expression `2*(n-i)+1` is the reverse of the solid pyramid's `2*i-1`: the row index grows, but the available width shrinks.

## Common mistakes to avoid

Using `2*i-1` creates an upright pyramid. Forgetting the `+1` gives zero stars on the final row.

## Pseudocode

```text
for i = 1..n:
    print i-1 blank groups
    starCount = 2*(n-i)+1
    print starCount stars
    print newline
```

## Complexity

The total printed width over all rows is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
