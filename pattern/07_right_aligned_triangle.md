# Right-Aligned Star Triangle

## Problem statement

Print an increasing triangle whose right edge stays aligned. Each row has leading blank groups followed by stars.

## Sample input and output

Input: `4`

```text
      *
    * *
  * * *
* * * *
```

## Step-by-step algorithm

1. Choose row `i`, from 1 through `n`.
2. First print `n-i` blank groups. The first row gets `n-1` groups; every next row gets one fewer.
3. Then print `i` stars using a separate loop. Do not mix the space count and star count into one loop because they follow different formulas.
4. Print a newline and advance to the next row.
5. At the last row, `n-i` is zero, so no leading blanks remain and all `n` stars begin at the left.

## Dry run: think through the counters

For `n = 4`: row 1 prints 3 blank groups + 1 star; row 2 prints 2 + 2; row 3 prints 1 + 3; row 4 prints 0 + 4. Each blank group is two spaces in this implementation.

## Why this algorithm works

The leading whitespace decreases while the number of stars increases. These opposite trends keep the triangle's right edge aligned.

## Common mistakes to avoid

Using `n-i+1` for spaces leaves an extra gap on the last row. Printing spaces after stars rather than before them left-aligns the triangle.

## Pseudocode

```text
for i = 1..n:
    repeat n-i times: print two spaces
    repeat i times: print "* "
    print newline
```

## Complexity

Across all rows, spaces and stars total O(n²), so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
