# Inverted Star Triangle

## Problem statement

Print `n` rows, starting with `n` stars and removing one star from each following row.

## Sample input and output

Input: `4`

```text
* * * *
* * *
* *
*
```

## Step-by-step algorithm

1. Begin with row `i = 1`.
2. Calculate the number of stars for this row as `n - i + 1`.
3. Run the inner loop from `j = 1` through `n - i + 1`, printing one star per iteration.
4. Print a newline after that row, then increase `i`.
5. As `i` grows, the expression `n - i + 1` decreases: `n`, `n-1`, ..., 1.

## Dry run: think through the counters

For `n = 4`: row 1 has `4-1+1 = 4` stars; row 2 has `4-2+1 = 3`; row 3 has 2; row 4 has 1.

## Why this algorithm works

The expression subtracts the row's progress from the maximum width. The `+1` is necessary because row 1 must still print `n` stars.

## Common mistakes to avoid

Using `n-i` omits one star from every row. Using `j <= i` produces an increasing triangle instead.

## Pseudocode

```text
for i = 1..n:
    starCount = n - i + 1
    repeat starCount times:
        print "* "
    print newline
```

## Complexity

The number of stars is `n + (n-1) + ... + 1`, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
