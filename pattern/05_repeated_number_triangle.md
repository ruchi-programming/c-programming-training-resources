# Repeated-Number Triangle

## Problem statement

Print row number `i` exactly `i` times on row `i`.

## Sample input and output

Input: `4`

```text
1
2 2
3 3 3
4 4 4 4
```

## Step-by-step algorithm

1. Start the outer loop at row `i = 1`.
2. Run the inner loop from `j = 1` to `j = i`. The counter `j` controls how many copies appear, not which number appears.
3. Inside the loop, print `i`, not `j`. Since `i` stays fixed throughout that row, the same number repeats.
4. Print a newline after the inner loop completes.
5. Advance `i`; the next row both has a new repeated value and one more copy.

## Dry run: think through the counters

For `n = 3`: row 1 repeats `1` once; row 2 repeats `2` twice; row 3 repeats `3` three times.

## Why this algorithm works

Two counters have different jobs: `i` chooses the value, while `j` counts repetitions. Mixing them up changes the pattern into an increasing number triangle.

## Common mistakes to avoid

Printing `j` gives `1`; `1 2`; `1 2 3`. Printing `i` only once gives one number per row.

## Pseudocode

```text
for i = 1..n:
    for j = 1..i:
        print i
    print newline
```

## Complexity

The total number of outputs is `n(n+1)/2`, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
