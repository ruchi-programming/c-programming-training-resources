# Structure of a C Program

This example demonstrates how a small C program can be organized into declarations, processing, output and program termination.

## Learning objectives

After completing this example, a learner should be able to:

- Identify the main components of a C program
- Declare and initialize variables
- Use `const` for values that should not change
- Perform an arithmetic calculation
- Print integer values using `%d`
- Explain the purpose of `return 0`

## Source file

The complete program is available in [`program_structure.c`](program_structure.c).

## Program organization

### 1. Preprocessor directive

```c
#include <stdio.h>
```

This directive includes the declarations needed to use standard input and output functions such as `printf`.

### 2. Main function

```c
int main(void)
```

Execution begins in the `main` function.

### 3. Declarations and initialization

```c
const int length = 8;
const int width = 5;
int area;
```

- `length` and `width` are initialized when declared.
- `const` indicates that these values should not be modified.
- `area` stores the result of the calculation.

### 4. Processing

```c
area = length * width;
```

The multiplication operator calculates the area of the rectangle.

### 5. Output

```c
printf("Area: %d\n", area);
```

The `%d` format specifier prints an `int` value.

### 6. Program termination

```c
return 0;
```

A return value of zero indicates successful program termination.

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic program_structure.c -o program_structure
./program_structure
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic program_structure.c -o program_structure.exe
.\program_structure.exe
```

## Expected output

```text
Length: 8
Width: 5
Area: 40
```

## Trace table

| Statement | `length` | `width` | `area` |
|---|---:|---:|---:|
| After declarations | 8 | 5 | Not assigned |
| After calculation | 8 | 5 | 40 |
| After output | 8 | 5 | 40 |

An uninitialized local variable must not be read before a value is assigned to it.

## Knowledge check

1. Why are `length` and `width` declared with `const`?
2. What type of value does `area` store?
3. Which operator calculates the area?
4. Why is `%d` used?
5. What does `return 0` communicate?

## Practice tasks

1. Change the dimensions and verify the output.
2. Add a calculation for the perimeter.
3. Print the perimeter after the area.
4. Create a similar program that calculates the area of a square.

## Common mistakes

- Reading an uninitialized variable
- Omitting a semicolon
- Using an incorrect format specifier
- Misspelling a variable name
- Using a variable outside its scope
- Modifying an object declared with `const`

## Standard used

This example uses standard C syntax and is suitable for compilation with C17 options.
