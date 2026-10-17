# Prime-Product Grid

## Problem statement

For each cell in an `n × n` grid, multiply the row number by the column number. Print `P` if the product is prime and `C` otherwise.

## Sample input and output

Input: `3`

```text
C P P
P C C
P C C
```

## Step-by-step algorithm

1. Understand the helper `isPrime(number)` first. Numbers below 2 are not prime, so return false for 0 and 1.
2. For a number 2 or greater, try possible divisors starting at 2. Continue while `divisor * divisor <= number`; if the number divides evenly (`number % divisor == 0`), it is composite and the helper returns false.
3. If no divisor is found, return true. Checking only through the square root is sufficient because any composite number has a factor no larger than its square root.
4. Now build the grid. For each row `row = 1..n` and column `col = 1..n`, calculate `product = row * col`.
5. Call `isPrime(product)`. Print `P` when true and `C` when false. After each row's columns, print a newline.

## Dry run: think through the counters

For `n = 3`: row 1 has products 1,2,3 → C,P,P; row 2 has 2,4,6 → P,C,C; row 3 has 3,6,9 → P,C,C.

## Why this algorithm works

The grid loop decides which products to test; the helper function decides whether each product is prime. Keeping those jobs separate makes the code easier to reason about.

## Common mistakes to avoid

Treating 1 as prime is incorrect. Checking divisors only up to `number/2` works but is slower. Forgetting to return true after the loop would mark primes as non-prime.

## Pseudocode

```text
function isPrime(x):
    if x < 2: return false
    for d = 2 while d*d <= x:
        if x % d == 0: return false
    return true

for row = 1..n:
    for col = 1..n:
        product = row*col
        if isPrime(product): print 'P'
        else: print 'C'
    print newline
```

## Complexity

There are `n²` cells. A primality test for a product up to `n²` checks up to O(n) divisors, so the straightforward overall bound is O(n³); extra space is O(1).

## Practice challenge

Change the input size and predict the output before running the program. Then explain what each loop counter represents and why its stopping condition matches this specific shape.
