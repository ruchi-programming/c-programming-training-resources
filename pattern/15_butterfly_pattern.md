# Butterfly Pattern

## Problem statement

Print a symmetric butterfly made of two star wings. The upper half widens its wings while the middle gap shrinks; the lower half mirrors this.

## Sample input and output

Input: `5`

```text
*            *
* *        * *
* * *    * * *
* * * *  * * * *
* * *    * * *
* *        * *
*            *
```

## Step-by-step algorithm

1. Treat the design as two halves: an upper half of `n` rows and a lower half of `n-1` rows, so the center row is not repeated.
2. For upper row `i = 1..n`, print `i` stars on the left wing.
3. Print the middle gap. Its width decreases as the wings grow; in the standard layout it is proportional to `2*(n-i)`.
4. Print another `i` stars for the right wing, then end the line.
5. For the lower half, count the wing size down from `n-1` to 1. Use the same rule: left stars, gap based on the wing size, right stars.
6. Because the lower half reverses the upper wing sizes, the figure is vertically symmetric.

## Dry run: think through the counters

For `n = 5`, `half = (5+1)/2 = 3`. Upper wing sizes are 1,2,3; lower wing sizes are 2,1. The widest wings appear on row 3, and the gap is smallest there.

## Why this algorithm works

The two star loops are mirror wings. Keeping their counts equal makes each row balanced; reversing the wing count creates the lower reflection.

## Common mistakes to avoid

Printing `n` rows in both halves duplicates the widest middle row. Increasing the lower wing count makes a second pyramid instead of a butterfly.

## Pseudocode

```text
half = (n+1)/2
for i = 1..half:
    print i left stars
    print middle gap for n-i
    print i right stars
for i = n-1 down to 1:
    print i left stars
    print middle gap for n-i
    print i right stars
```

## Complexity

The nested row/column printing produces O(n²) output; extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
