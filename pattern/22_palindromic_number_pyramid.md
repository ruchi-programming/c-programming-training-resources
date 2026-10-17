# Palindromic Number Pyramid

## Problem statement

Print a centered number pyramid where each row increases from 1 to its row number, then decreases back to 1.

## Sample input and output

Input: `4`

```text
      1
    1 2 1
  1 2 3 2 1
1 2 3 4 3 2 1
```

## Step-by-step algorithm

1. For row `i = 1..n`, first print `n-i` pairs of spaces. Double spaces are used so the numbers line up visually.
2. Print the increasing sequence `1, 2, ..., i` using a loop from `j=1` through `i`.
3. Then print the decreasing sequence `i-1, i-2, ..., 1`. Start at `i-1` so the peak value `i` is not repeated.
4. Print a newline and move to the next row.
5. Keep `n` small (the code recommends at most 9) if you want clean alignment with single-digit values.

## Dry run: think through the counters

For row `i = 3`, indentation is `n-3` pairs of spaces; the rising loop prints `1 2 3`; the falling loop prints `2 1`. Combined row: `1 2 3 2 1`.

## Why this algorithm works

The row is palindromic because the second sequence mirrors the first around the single peak `i`. The two loops separate the rising and falling sequences.

## Common mistakes to avoid

Starting the decreasing loop at `i` prints the peak twice. Omitting the decreasing loop produces a simple increasing triangle rather than a palindrome.

## Pseudocode

```text
for i = 1..n:
    print n-i pairs of spaces
    for j = 1..i: print j
    for j = i-1 down to 1: print j
    print newline
```

## Complexity

Each row prints O(i) values and there are `n` rows, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
