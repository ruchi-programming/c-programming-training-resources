# Plus Pattern

## Problem statement

Print a plus sign inside an `n × n` grid: the complete middle row and complete middle column are stars. The supplied program increases even `n` to odd.

## Sample input and output

Input: `5`

```text
  *
  *
*****
  *
  *
```

## Step-by-step algorithm

1. If `n` is even, increment it to make the grid size odd.
2. Compute the middle index as `mid = n/2`. Because the indices are zero-based, this identifies the exact center row and column.
3. Visit every cell `(i,j)`.
4. If `i == mid`, the cell lies in the middle row; if `j == mid`, it lies in the middle column.
5. Print a star when either condition is true; otherwise print a space. End each row with a newline.

## Dry run: think through the counters

For `n = 5`, `mid = 2`. Every cell in row 2 is a star, and every cell in column 2 is a star. The center cell satisfies both tests but is printed only once.

## Why this algorithm works

A plus is the union of one horizontal line and one vertical line. The OR operator includes cells belonging to either line.

## Common mistakes to avoid

Using `i == mid && j == mid` prints only the center point. Using `mid = (n-1)/2` also works for odd `n`, but it is not the expression used here.

## Pseudocode

```text
if n is even: n = n+1
mid = n/2
for i = 0..n-1:
    for j = 0..n-1:
        if i==mid or j==mid: print '*'
        else: print ' '
    print newline
```

## Complexity

Every grid position is tested once, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
