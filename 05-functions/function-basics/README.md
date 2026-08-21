# Functions, Prototypes and Return Values

This example separates two calculations into reusable functions:

- Testing whether an integer is even
- Calculating its factorial

## Learning objectives

After completing this example, a learner should be able to:

- Declare a function prototype
- Define a function
- Call a function
- Pass an argument by value
- Receive a returned result
- Select an appropriate return type
- Decompose a program into focused units
- Test functions with boundary values

## Source file

The complete program is available in [`number_functions.c`](number_functions.c).

## Function prototypes

```c
int is_even(int number);
unsigned long long factorial(int number);
```

A function prototype tells the compiler:

- The function name
- The return type
- The number of parameters
- The type of every parameter

The prototype, function call and function definition must agree.

## Calling a function

```c
is_even(number)
```

The value stored in `number` is passed to the function.

C passes function arguments by value. The parameter receives a copy of the argument value.

## Boolean-style result in C

```c
int is_even(int number)
{
    return number % 2 == 0;
}
```

The relational expression evaluates to:

- `1` when the condition is true
- `0` when the condition is false

The returned integer can therefore be tested directly by an `if` statement.

## Factorial function

```c
unsigned long long factorial(int number)
```

The function returns an `unsigned long long` because factorial values grow quickly.

The program restricts the input to `0` through `20` because:

```text
20! = 2432902008176640000
```

This value fits in the commonly supported 64-bit `unsigned long long` range. The exact range of integer types is implementation-defined, so production code should confirm the limits provided by the implementation.

## Why zero factorial equals one

By definition:

```text
0! = 1
```

The `result` variable begins at one. When the input is zero or one, the loop does not execute and the function correctly returns one.

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic number_functions.c -o number_functions
./number_functions
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic number_functions.c -o number_functions.exe
.\number_functions.exe
```

## Example

Input:

```text
5
```

Output:

```text
5 is odd.
5! = 120
```

## Test cases

| Input | Parity | Factorial |
|---:|---|---:|
| `0` | Even | `1` |
| `1` | Odd | `1` |
| `2` | Even | `2` |
| `5` | Odd | `120` |
| `10` | Even | `3628800` |
| `20` | Even | `2432902008176640000` |
| `-1` | Rejected | Not calculated |
| `21` | Rejected | Not calculated |

## Knowledge check

1. What information does a function prototype provide?
2. What is passed to `is_even`?
3. What does `is_even` return for an odd number?
4. Why is the factorial result initialized to one?
5. Why is the input restricted to a maximum of 20?
6. What happens if a prototype and definition use different types?

## Practice extensions

1. Add a function that returns the square of the number.
2. Add a function that finds the sum from `1` to the number.
3. Create a function that checks whether the number is prime.
4. Move the input-validation logic into a separate function.
5. Build a menu that calls the different number functions.

## Common mistakes

- Calling a function before declaring it
- Using incompatible parameter or return types
- Omitting the returned value
- Initializing the factorial result to zero
- Using a type too small for the result
- Assuming that changing a value parameter changes the caller’s variable
- Failing to test `0!` and `1!`

## Standard used

This example uses standard C syntax and standard library facilities compatible with C17.
