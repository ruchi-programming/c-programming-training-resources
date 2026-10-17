# Multiplication Table Grid

## Problem statement

Print an `n × n` multiplication grid where the value at row `i`, column `j` is `i*j`.

## Sample input and output

Input: `4`

```text
 1  2  3  4
 2  4  6  8
 3  6  9 12
 4  8 12 16
```

## Step-by-step algorithm

1. Select row multiplier `i`, from 1 through `n`.
2. For each column multiplier `j`, from 1 through `n`, calculate `product = i * j`.
3. Print the product using a fixed-width format so one- and two-digit values line up.
4. After the inner loop has produced all multiples of `i`, print a newline.
5. Move to the next row multiplier. Each new row is the next number's multiplication table.

## Dry run: think through the counters

For `n = 3`: row `i=1` prints 1,2,3; row `i=2` prints 2,4,6; row `i=3` prints 3,6,9. The cell in row 2, column 3 is `2*3 = 6`.

## Why this algorithm works

The row counter fixes the number being multiplied; the column counter selects which multiple. Swapping them gives the same numeric grid because multiplication is commutative, but the roles are still useful to understand.

## Common mistakes to avoid

Printing `i+j` instead of `i*j` creates a sum grid. Resetting `j` incorrectly can omit columns.

## Pseudocode

```text
for i = 1..n:
    for j = 1..n:
        product = i*j
        print product in a fixed-width field
    print newline
```

## Complexity

There are `n²` products, so time is O(n²); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
