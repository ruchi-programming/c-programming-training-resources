# Hollow Hourglass

## Problem statement

Print a hollow hourglass with an upper triangle narrowing to a one-star center row, then a lower triangle widening back out. Use an odd `n` for the intended symmetry.

## Sample input and output

Input: `5`

```text
*****
 * *
  *
 * *
*****
```

## Step-by-step algorithm

1. Compute `mid = n/2`. The upper half loops `i` from 0 through `mid`, inclusive, so it includes the narrow center row.
2. On upper row `i`, print `i` leading spaces. The row's width is `2*(mid-i)+1`, which shrinks by two each time.
3. Print a star at both ends of the row. The first upper row is a special case: `i == 0` fills the whole top edge with stars.
4. After the center row, print the lower half for `i = 1..mid`. Its leading spaces are `mid-i`, and its width grows as `2*i+1`.
5. On lower rows, print stars at the two edges; the final row is special (`i == mid`) and is filled to make the bottom edge solid.
6. End each row with a newline. The center row is printed once because the lower half begins at 1 rather than 0.

## Dry run: think through the counters

For `n = 5`, `mid = 2`. Upper widths are 5,3,1 with indentation 0,1,2. Lower widths are 3,5 with indentation 1,0. The top and bottom rows are solid.

## Why this algorithm works

The upper width formula decreases while the lower width formula increases. Edge conditions keep the interior hollow, and the first/last-row conditions close the shape.

## Common mistakes to avoid

Starting the lower loop at 0 duplicates the center. Using an even `n` can produce an uneven shape because the code assumes a central row.

## Pseudocode

```text
mid = n/2
for i = 0..mid:
    print i spaces
    width = 2*(mid-i)+1
    print width positions; star if i==0 or at either edge
for i = 1..mid:
    print mid-i spaces
    width = 2*i+1
    print width positions; star if i==mid or at either edge
```

## Complexity

The loops visit O(n²) positions in total; extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
