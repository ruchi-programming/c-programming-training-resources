# Hello World in C

This introductory program demonstrates the basic structure of a C program and prints a message to standard output.

## Learning objectives

After completing this example, a learner should be able to:

- Identify the header-file inclusion
- Recognize the `main` function
- Use `printf`
- Explain the purpose of `return 0`
- Compile and execute a basic C program

## Program

The source code is available in [`hello_world.c`](hello_world.c).

## Code explanation

### Header file

```c
#include <stdio.h>
```

The `stdio.h` header provides the declaration of the standard input and output functions, including `printf`.

### Main function

```c
int main(void)
```

Program execution begins in `main`.

The `void` parameter list explicitly indicates that the function does not receive arguments.

### Output statement

```c
printf("Hello, World!\n");
```

`printf` writes formatted output to the standard output stream.

The `\n` escape sequence moves the cursor to the next line.

### Return statement

```c
return 0;
```

Returning zero indicates successful program termination to the host environment.

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic hello_world.c -o hello_world
./hello_world
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic hello_world.c -o hello_world.exe
.\hello_world.exe
```

## Expected output

```text
Hello, World!
```

## Knowledge check

1. Why is `stdio.h` included?
2. Where does program execution begin?
3. What does `\n` represent?
4. What does `return 0` indicate?
5. What happens if the semicolon after `printf` is removed?

## Practice extension

Modify the program to print:

- Your name
- Your role or course
- Each item on a separate line

## Common mistakes

- Writing `Printf` instead of `printf`
- Omitting the semicolon
- Using mismatched quotation marks
- Forgetting the closing brace
- Typing `/n` instead of `\n`

## Standard used

The example is compatible with standard C and can be compiled using C17 options.
