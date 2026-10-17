# Solid Diamond Pattern

## Problem statement

Print a centered solid diamond by widening from one star to a widest row, then narrowing back to one star.

## Sample input and output

Input: `3`

```text
  *
 * * *
* * * * *
 * * *
  *
```

## Step-by-step algorithm

1. Build the upper half including the widest row. For each row `i = 1..n`, print `n-i` leading blank groups.
2. Print `i` stars for the rising side, then `i-1` stars for the falling side. The row width is `2i-1` stars.
3. Build the lower half starting at `i = n-1` and decreasing to 1. This avoids printing the widest row twice.
4. For each lower row, print `n-i` blank groups and the same `2i-1` star structure.
5. Stop after the lower row with one star. The two halves are mirror images around the widest row.

## Dry run: think through the counters

For `n = 3`, upper star counts are 1,3,5; lower star counts are 3,1. The indentation counts are 2,1,0,1,2 blank groups.

## Why this algorithm works

A diamond is an increasing centered pyramid joined to a decreasing centered pyramid. The second half begins at `n-1` to avoid duplicating the center.

## Common mistakes to avoid

Starting the lower loop at `n` duplicates the widest row. Forgetting to increase indentation in the lower half breaks symmetry.

## Pseudocode

```text
for i = 1..n:
    print n-i blank groups
    print 2*i-1 stars
for i = n-1 down to 1:
    print n-i blank groups
    print 2*i-1 stars
```

## Complexity

The total output area is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
