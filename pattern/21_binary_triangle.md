# Alternating Binary Triangle

## Problem statement

Print a triangular arrangement of 1s and 0s. The value is determined by the parity of the zero-based row and column indices.

## Sample input and output

Input: `5`

```text
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
```

## Step-by-step algorithm

1. Use zero-based row index `i = 0..n-1`.
2. For row `i`, visit columns `j = 0..i`; this gives row lengths 1,2,...,n.
3. Add the indices. If `(i+j) % 2 == 0`, print `1`; otherwise print `0`.
4. After the row's `i+1` values are printed, move to the next line.
5. Because each step right or down changes the parity, the binary value alternates across rows and columns.

## Dry run: think through the counters

For `n = 4`: row `i=0` has sum 0 → `1`; row `i=1` has sums 1,2 → `0 1`; row `i=2` has sums 2,3,4 → `1 0 1`; row `i=3` has sums 3,4,5,6 → `0 1 0 1`.

## Why this algorithm works

The test uses zero-based indices, so the first cell `(0,0)` has an even sum and prints 1. This explains why the first row starts with 1.

## Common mistakes to avoid

Using 1-based row/column counters with the same parity rule can flip the starting value. Testing only `i % 2` would make an entire row the same value.

## Pseudocode

```text
for i = 0..n-1:
    for j = 0..i:
        if (i+j)%2 == 0: print 1
        else: print 0
    print newline
```

## Complexity

The triangle has `n(n+1)/2` cells, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
