# FizzBuzz in C

FizzBuzz is a beginner-friendly exercise combining loops, modulo and ordered decision-making.

This repository uses an independently written console-based formulation for learning purposes.

## Problem

Given an upper limit, process every integer from `1` through that limit.

For each integer:

- Print `FizzBuzz` when it is divisible by both 3 and 5.
- Otherwise, print `Fizz` when it is divisible by 3.
- Otherwise, print `Buzz` when it is divisible by 5.
- Otherwise, print the integer.

## Learning objectives

After completing this example, a learner should be able to:

- Use a count-controlled loop
- Test divisibility with the modulo operator
- Order overlapping conditions correctly
- Produce exact output
- Test representative and boundary values
- Explain why the combined rule must be tested first

## Source file

The complete program is available in [`fizzbuzz.c`](fizzbuzz.c).

## Why condition order matters

A multiple of 15 is also a multiple of 3 and 5.

If this condition appears first:

```c
number % 3 == 0
```

then `15` would produce only:

```text
Fizz
```

The combined condition must therefore be tested first:

```c
number % 15 == 0
```

## Divisibility test

```c
number % divisor == 0
```

The remainder is zero when `number` is exactly divisible by `divisor`.

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic fizzbuzz.c -o fizzbuzz
./fizzbuzz
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic fizzbuzz.c -o fizzbuzz.exe
.\fizzbuzz.exe
```

## Example

Input:

```text
15
```

The final part of the output is:

```text
11
Fizz
13
14
FizzBuzz
```

## Critical test values

| Value | Expected output |
|---:|---|
| 1 | `1` |
| 3 | `Fizz` |
| 5 | `Buzz` |
| 6 | `Fizz` |
| 10 | `Buzz` |
| 15 | `FizzBuzz` |
| 30 | `FizzBuzz` |

## Input tests

| Input | Expected behaviour |
|---|---|
| `1` | Prints one line |
| `15` | Includes all four output categories |
| `1000` | Accepted upper boundary |
| `0` | Rejected |
| `1001` | Rejected |
| Invalid text | Input error |

## Complexity

For an upper limit `n`:

- Time complexity: O(n)
- Auxiliary space: O(1)

## Knowledge check

1. What does the modulo operator return?
2. Why is divisibility by both numbers tested first?
3. Why can `number % 15 == 0` represent divisibility by both 3 and 5?
4. How many loop iterations occur for a limit of 20?
5. Why must output capitalization remain consistent?

## Practice extensions

1. Use separate conditions without printing multiple results.
2. Accept two divisors and two replacement words.
3. Count how many times each category appears.
4. Store the category logic in a function.
5. Compare two correct implementations for readability.
6. Adapt the logic to a coding platform’s supplied function signature.

## Coding-platform guidance

When solving a platform version:

1. Read its exact input and output requirements.
2. Use the function signature supplied by the platform.
3. Do not add prompts unless the problem permits them.
4. Test locally before submission.
5. Record the verdict and the test that fixed an error.
6. Write your own solution rather than copying another submission.

## Common mistakes

- Testing divisibility by 3 before the combined condition
- Printing more than one result for a number
- Using division instead of modulo
- Starting the loop at zero unintentionally
- Using a strict `<` boundary and omitting the limit
- Adding prompts to a judge submission
- Producing incorrect capitalization

## Standard used

This example uses standard C syntax and standard library facilities compatible with C17.
