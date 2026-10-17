# Right-Angled Star Triangle

## Problem statement

Print `n` left-aligned rows. Row `i` contains exactly `i` stars.

## Sample input and output

Input: `4`

```text
*
* *
* * *
* * * *
```

## Step-by-step algorithm

1. Set `i` to 1 for the first row.
2. On row `i`, set `j` to 1 and print a star while `j <= i`.
3. When `j` becomes greater than `i`, stop that row and print a newline.
4. Increase `i`. The next row's star limit is one larger than the previous row.
5. Stop after row `n`; the final row contains `n` stars.

## Dry run: think through the counters

For `n = 4`, the inner-loop limits are 1, 2, 3, and 4. So the rows contain `*`; `* *`; `* * *`; and `* * * *`.

## Why this algorithm works

The row number itself is the star count. This is why the inner loop ends at `i`, not at `n`.

## Common mistakes to avoid

Using `j <= n` makes a square. Starting the inner loop at 0 while keeping `j <= i` prints one extra star.

## Pseudocode

```text
for i = 1..n:
    for j = 1..i:
        print "* "
    print newline
```

## Complexity

The total number of stars is `1 + 2 + ... + n = n(n+1)/2`, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
