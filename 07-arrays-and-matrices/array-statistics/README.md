# One-Dimensional Array Statistics

This example reads a collection of integers and reports its sum, minimum, maximum and average.

The program separates the calculations into focused functions.

## Learning objectives

After completing this example, a learner should be able to:

- Declare a fixed-capacity array
- Maintain a separate logical size
- Access elements with zero-based indices
- Traverse an array safely
- Pass an array to a function
- Use `const` for read-only array parameters
- Calculate sum, minimum, maximum and average
- Convert an integer before floating-point division

## Source file

The complete program is available in [`array_statistics.c`](array_statistics.c).

## Capacity and logical size

```c
#define MAX_SIZE 20
```

`MAX_SIZE` specifies the physical capacity of the array.

```c
int values[MAX_SIZE];
int size;
```

- `values` can store at most 20 integers.
- `size` records how many elements are currently being used.

The program validates `size` before reading elements.

## Valid indices

For an array containing `size` elements, the valid indices are:

```text
0 through size - 1
```

The traversal condition is therefore:

```c
index < size
```

Using `index <= size` would access one element beyond the logical array boundary.

## Passing an array to a function

```c
int calculate_sum(const int values[], int size);
```

The function receives:

- Access to the array elements
- The number of valid elements

The `const` qualifier indicates that the function must not modify the elements through this parameter.

The array size is passed separately because an array parameter does not automatically provide its element count.

## Minimum and maximum initialization

```c
int minimum = values[0];
```

The first valid element provides the initial candidate.

Initializing the minimum to zero would produce an incorrect result when every array element is positive. Similarly, initializing the maximum to zero would fail when every element is negative.

## Calculating the average

```c
double average = (double)sum / size;
```

The cast converts `sum` to `double` before division.

Without the conversion, dividing two integers would perform integer division and discard the fractional part.

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic array_statistics.c -o array_statistics
./array_statistics
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic array_statistics.c -o array_statistics.exe
.\array_statistics.exe
```

## Example

Input:

```text
5
8 3 12 -2 9
```

Output:

```text
Sum: 30
Minimum: -2
Maximum: 12
Average: 6.00
```

## Trace example

For the array:

```text
8 3 12 -2 9
```

| Index | Element | Running sum | Minimum | Maximum |
|---:|---:|---:|---:|---:|
| 0 | 8 | 8 | 8 | 8 |
| 1 | 3 | 11 | 3 | 8 |
| 2 | 12 | 23 | 3 | 12 |
| 3 | -2 | 21 | -2 | 12 |
| 4 | 9 | 30 | -2 | 12 |

## Test cases

| Elements | Expected result |
|---|---|
| `5` | Sum, minimum and maximum are `5` |
| `2 4` | Average is `3.00` |
| `-8 -3 -12` | Maximum is `-3` |
| `4 4 4` | Minimum and maximum are both `4` |
| Size `0` | Rejected |
| Size `21` | Rejected |
| Invalid element | Error message |

## Knowledge check

1. What is the difference between capacity and logical size?
2. Why does array traversal use `index < size`?
3. Why is the first element used to initialize minimum and maximum?
4. Why is the size passed separately to each function?
5. What does `const` communicate?
6. Why is `sum` converted to `double`?

## Practice extensions

1. Count positive, negative and zero elements.
2. Search for a user-supplied value.
3. Count occurrences of a value.
4. Print the array in reverse order.
5. Add a function that calculates the range.
6. Add overflow checks to the sum calculation.

## Common mistakes

- Accessing index `size`
- Accepting a size larger than the array capacity
- Reading an invalid element without checking `scanf`
- Initializing minimum or maximum to zero
- Forgetting to pass the logical size
- Performing integer division when calculating the average
- Modifying an array through a read-only parameter

## Standard used

This example uses standard C syntax and standard library facilities compatible with C17.
