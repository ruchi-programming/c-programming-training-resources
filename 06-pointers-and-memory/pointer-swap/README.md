# Swapping Values Using Pointers

This example demonstrates how a function can modify variables belonging to its caller by receiving their addresses.

## Learning objectives

After completing this example, a learner should be able to:

- Declare pointer parameters
- Use the address-of operator
- Use the dereference operator
- Pass object addresses to a function
- Modify caller-owned objects through pointers
- Explain how C passes pointer values
- Trace a pointer-based swap

## Source file

The complete program is available in [`pointer_swap.c`](pointer_swap.c).

## Important terminology

C passes every function argument by value.

In this program, the values passed to `swap` are addresses. The pointer parameters receive copies of those addresses.

The function can modify the original objects because the copied addresses still identify those objects.

This technique is often informally called “call by reference,” but technically C uses call by value with pointer arguments.

## Function prototype

```c
void swap(int *first, int *second);
```

- `first` points to an `int`.
- `second` points to an `int`.
- `void` indicates that the function does not return a value.

## Passing addresses

```c
swap(&first_number, &second_number);
```

The address-of operator `&` obtains the addresses of the two variables.

## Dereferencing pointers

```c
*first
```

The dereference operator `*` accesses the `int` object identified by `first`.

An assignment through a dereferenced pointer changes that object.

## Swap logic

```c
int temporary = *first;

*first = *second;
*second = temporary;
```

The temporary variable preserves the original first value while the assignments are performed.

## Trace example

Assume:

```text
first_number = 10
second_number = 25
```

| Step | `first_number` | `second_number` | `temporary` |
|---|---:|---:|---:|
| Before function call | 10 | 25 | Not created |
| Save `*first` | 10 | 25 | 10 |
| Assign `*second` to `*first` | 25 | 25 | 10 |
| Assign `temporary` to `*second` | 25 | 10 | 10 |
| After function call | 25 | 10 | No longer exists |

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic pointer_swap.c -o pointer_swap
./pointer_swap
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic pointer_swap.c -o pointer_swap.exe
.\pointer_swap.exe
```

## Example

Input:

```text
10 25
```

Output:

```text
Before swap: first = 10, second = 25
After swap:  first = 25, second = 10
```

## Test cases

| Input | Expected result |
|---|---|
| `10 25` | Values exchange positions |
| `5 5` | Both values remain `5` |
| `-2 8` | Results become `8` and `-2` |
| `0 100` | Results become `100` and `0` |
| `ten 25` | Invalid-input message |

## Knowledge check

1. What does the `&` operator produce?
2. What does `*first` represent inside `swap`?
3. Are the original integers passed directly to the function?
4. Why is a temporary variable required?
5. Why can the function modify the caller’s variables?
6. Does C provide true call-by-reference parameter passing?

## Practice extensions

1. Write a function that sets an integer to zero.
2. Write a function that increments a caller-owned integer.
3. Return the smaller and larger values through two pointer parameters.
4. Create a function that returns both quotient and remainder through pointers.
5. Add null-pointer checks and discuss when they are useful.

## Common mistakes

- Passing a value instead of its address
- Forgetting to dereference a pointer
- Dereferencing an uninitialized pointer
- Using incompatible pointer types
- Losing a value by swapping without temporary storage
- Claiming that C directly passes parameters by reference

## Standard used

This example uses standard C syntax and standard library facilities compatible with C17.
