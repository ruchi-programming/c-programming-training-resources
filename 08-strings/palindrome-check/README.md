08-strings/palindrome-check/README.md# Palindromic String in C

A palindrome reads the same from left to right and from right to left.

Examples include:

```text
level
radar
madam
```

This program performs an exact, case-sensitive comparison.

## Learning objectives

After completing this example, a learner should be able to:

- Store a string in a character array
- Read a line safely with `fgets`
- Remove the newline retained by `fgets`
- Determine string length with `strlen`
- Use `size_t` for string indices
- Compare mirrored characters
- Pass a string to a read-only function
- Handle empty and single-character strings safely

## Source file

The complete program is available in [`palindrome_check.c`](palindrome_check.c).

## Reading a line

```c
fgets(text, sizeof text, stdin)
```

`fgets` reads at most one less than the supplied array size and reserves space for the terminating null character.

Unlike:

```c
scanf("%s", text);
```

`fgets` can read spaces as part of the input.

## Removing the newline

When space is available, `fgets` normally stores the newline produced when the user presses Enter.

The following statement finds the first newline and replaces it with the null character:

```c
text[strcspn(text, "\n")] = '\0';
```

If no newline is present in the stored text, `strcspn` returns the position of the terminating null character. Assigning `'\0'` at that position remains valid.

## Palindrome logic

The algorithm uses two indices:

```text
left  → beginning of the string
right → end of the string
```

After comparing the two characters:

- `left` moves right.
- `right` moves left.
- The process stops when the indices meet or cross.
- The function returns zero immediately when a mismatch is found.

## Why short strings are handled separately

```c
if (length < 2)
{
    return 1;
}
```

An empty string and a one-character string are palindromes.

Handling them before calculating `length - 1` also prevents unsigned underflow when the length is zero.

## Case-sensitive behaviour

The program compares characters exactly.

Therefore:

```text
Level
```

is not considered a palindrome because uppercase `L` and lowercase `l` have different character codes.

Ignoring case and punctuation would require additional normalization rules.

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic palindrome_check.c -o palindrome_check
./palindrome_check
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic palindrome_check.c -o palindrome_check.exe
.\palindrome_check.exe
```

## Test cases

| Input | Expected result |
|---|---|
| `level` | Palindrome |
| `radar` | Palindrome |
| `abba` | Palindrome |
| `a` | Palindrome |
| Empty line | Palindrome |
| `hello` | Not a palindrome |
| `Level` | Not a palindrome |
| `nurses run` | Not a palindrome under exact comparison |

## Trace example

For:

```text
level
```

| `left` | `right` | Characters | Result |
|---:|---:|---|---|
| 0 | 4 | `l` and `l` | Match |
| 1 | 3 | `e` and `e` | Match |
| 2 | 2 | Same position | Stop |

The function returns `1`.

## Knowledge check

1. Why is `fgets` appropriate for line input?
2. What is the purpose of the terminating `'\0'`?
3. Why is the newline removed?
4. Why does the function use `size_t`?
5. Why must a zero-length string be handled before calculating `length - 1`?
6. Is the current comparison case-sensitive?

## Practice extensions

1. Compare letters without considering case.
2. Ignore spaces during comparison.
3. Ignore punctuation.
4. Count the number of character comparisons.
5. Implement a manual string-length function.
6. Create a version that uses pointer traversal.

## Common mistakes

- Using an unsafe unbounded input operation
- Forgetting to remove the newline from `fgets`
- Comparing only adjacent characters
- Starting the right index at `length`
- Using `left <= right` unnecessarily
- Subtracting one from a zero `size_t` value
- Assuming the program automatically ignores case or spaces

## Standard used

This example uses standard C syntax and standard library facilities compatible with C17.
