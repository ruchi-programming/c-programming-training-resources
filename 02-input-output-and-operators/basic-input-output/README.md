# Standard Input and Formatted Output

This example reads a quantity and unit price, validates the input and calculates a purchase total.

## Learning objectives

After completing this example, a learner should be able to:

- Read values with `scanf`
- Pass variable addresses using `&`
- Check the return value of `scanf`
- Validate numeric input
- Perform mixed integer and floating-point calculations
- Format decimal output
- Report errors through the standard error stream

## Source file

The complete program is available in [`purchase_total.c`](purchase_total.c).

## Input

The program expects:

```text
quantity unit_price
```

Example:

```text
4 125.50
```

## Output

```text
Quantity: 4
Unit price: 125.50
Total: 502.00
```

## Important C details

### Reading an integer

```c
scanf("%d", &quantity);
```

- `%d` reads an `int`.
- `&quantity` provides the address at which the value will be stored.

### Reading a double

```c
scanf("%lf", &unit_price);
```

When used with `scanf`, `%lf` reads a `double`.

When used with `printf`, `%f` prints a floating-point value because a `double` is passed to this variadic function.

### Checking input success

```c
if (scanf("%d %lf", &quantity, &unit_price) != 2)
```

`scanf` returns the number of input items successfully matched and assigned.

The program expects two successful assignments.

### Formatting decimal output

```c
printf("%.2f\n", total);
```

`%.2f` prints the value with two digits after the decimal point.

### Reporting an error

```c
fprintf(stderr, "Invalid input.\n");
```

`stderr` is the standard error stream.

A nonzero value returned from `main` indicates that the program did not complete successfully.

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic purchase_total.c -o purchase_total
./purchase_total
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic purchase_total.c -o purchase_total.exe
.\purchase_total.exe
```

## Test cases

| Test | Input | Expected result |
|---|---|---|
| Normal | `4 125.50` | Total is `502.00` |
| Zero quantity | `0 125.50` | Total is `0.00` |
| Zero price | `4 0` | Total is `0.00` |
| Negative quantity | `-2 100` | Error message |
| Invalid text | `four 100` | Invalid-input message |

## Knowledge check

1. Why is `&` used with the variables in `scanf`?
2. What does the return value of `scanf` represent?
3. Why does `scanf` use `%lf` for a `double`?
4. What does `%.2f` control?
5. Why does the program return `1` after an error?

## Practice extensions

1. Add a discount percentage.
2. Calculate the amount after discount.
3. Add a tax percentage.
4. Reject a quantity greater than a chosen maximum.
5. Display a formatted purchase summary.

## Common mistakes

- Forgetting `&` in `scanf`
- Using `%f` instead of `%lf` to read a `double`
- Ignoring the return value of `scanf`
- Accepting invalid negative values
- Using integer variables for decimal prices
- Expecting `%lf` in `printf`

## Standard used

This example uses standard C syntax and standard library facilities compatible with C17.
