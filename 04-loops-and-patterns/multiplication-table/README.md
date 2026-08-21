# Multiplication Table Using a `for` Loop

This example uses a count-controlled `for` loop to generate a multiplication table.

## Learning objectives

After completing this example, a learner should be able to:

- Explain the three parts of a `for` statement
- Use a loop counter
- Define inclusive loop boundaries
- Validate the number of iterations
- Generate formatted output repeatedly
- Identify common off-by-one errors

## Source file

The complete program is available in [`multiplication_table.c`](multiplication_table.c).

## Input

Enter:

```text
number limit
```

Example:

```text
5 4
```

## Expected output

```text
5 x 1 = 5
5 x 2 = 10
5 x 3 = 15
5 x 4 = 20
```

## Understanding the loop

```c
for (int multiplier = 1; multiplier <= limit; multiplier++)
```

The loop contains three control expressions.

### Initialization

```c
int multiplier = 1
```

This executes once before the first condition check.

### Condition

```c
multiplier <= limit
```

The loop body executes while this condition is true.

Using `<=` includes the value stored in `limit`.

### Update

```c
multiplier++
```

The counter increases by one after each iteration.

## Execution order

The loop follows this sequence:

1. Initialize `multiplier`.
2. Test the condition.
3. Execute the body when the condition is true.
4. Update `multiplier`.
5. Test the condition again.
6. Stop when the condition becomes false.

## Trace example

For input `5 4`:

| Iteration | `multiplier` | Condition | Printed result |
|---:|---:|---|---|
| 1 | 1 | `1 <= 4` | `5 x 1 = 5` |
| 2 | 2 | `2 <= 4` | `5 x 2 = 10` |
| 3 | 3 | `3 <= 4` | `5 x 3 = 15` |
| 4 | 4 | `4 <= 4` | `5 x 4 = 20` |
| Stop | 5 | `5 <= 4` is false | No output |

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic multiplication_table.c -o multiplication_table
./multiplication_table
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic multiplication_table.c -o multiplication_table.exe
.\multiplication_table.exe
```

## Test cases

| Input | Expected behaviour |
|---|---|
| `5 4` | Prints four lines |
| `7 1` | Prints one line |
| `0 5` | Prints five zero products |
| `-3 3` | Prints a table for `-3` |
| `5 0` | Rejects the limit |
| `5 101` | Rejects the limit |
| `five 10` | Reports invalid input |

## Knowledge check

1. Which part of the `for` statement executes only once?
2. Why is `<=` used instead of `<`?
3. When does the update expression execute?
4. How many iterations occur when the limit is `10`?
5. What happens when the input cannot be read as two integers?

## Practice extensions

1. Print the table in reverse order.
2. Allow the user to provide the starting multiplier.
3. Calculate the sum of all generated products.
4. Print tables for several numbers using nested loops.
5. Create a formatted multiplication grid.

## Common mistakes

- Starting the counter at the wrong value
- Using `<` when the final limit must be included
- Updating the counter in the wrong direction
- Adding an unintended semicolon after the `for` statement
- Changing the loop counter inside the body unnecessarily
- Failing to validate the iteration limit

## Standard used

This example uses standard C syntax compatible with C17.
