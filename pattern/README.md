# C Pattern Printing Programs

Each pattern is provided as a separate, standalone C program with a detailed source-code comment and a matching Markdown explanation.

## How to compile and run
Compile one source file at a time:

```bash
gcc -std=c11 -Wall -Wextra -pedantic 01_solid_square.c -o pattern
./pattern
```

Enter the size `n` when prompted by the input format. On Windows, run `pattern.exe` after compilation.

## Program index

| C file | Pattern | Difficulty |
|---|---|---|
| [`01_solid_square.c`](01_solid_square.c) · [Explanation](01_solid_square.md) | Solid Square | Very Easy |
| [`02_right_triangle.c`](02_right_triangle.c) · [Explanation](02_right_triangle.md) | Right-Angled Star Triangle | Very Easy |
| [`03_inverted_triangle.c`](03_inverted_triangle.c) · [Explanation](03_inverted_triangle.md) | Inverted Star Triangle | Easy |
| [`04_number_triangle.c`](04_number_triangle.c) · [Explanation](04_number_triangle.md) | Number Triangle | Easy |
| [`05_repeated_number_triangle.c`](05_repeated_number_triangle.c) · [Explanation](05_repeated_number_triangle.md) | Repeated-Number Triangle | Easy |
| [`06_consecutive_number_triangle.c`](06_consecutive_number_triangle.c) · [Explanation](06_consecutive_number_triangle.md) | Consecutive-Number Triangle | Easy |
| [`07_right_aligned_triangle.c`](07_right_aligned_triangle.c) · [Explanation](07_right_aligned_triangle.md) | Right-Aligned Star Triangle | Easy |
| [`08_centered_pyramid.c`](08_centered_pyramid.c) · [Explanation](08_centered_pyramid.md) | Centered Star Pyramid | Easy–Moderate |
| [`09_inverted_centered_pyramid.c`](09_inverted_centered_pyramid.c) · [Explanation](09_inverted_centered_pyramid.md) | Inverted Centered Pyramid | Easy–Moderate |
| [`10_hollow_square.c`](10_hollow_square.c) · [Explanation](10_hollow_square.md) | Hollow Square | Moderate |
| [`11_hollow_triangle.c`](11_hollow_triangle.c) · [Explanation](11_hollow_triangle.md) | Hollow Right-Angled Triangle | Moderate |
| [`12_multiplication_grid.c`](12_multiplication_grid.c) · [Explanation](12_multiplication_grid.md) | Multiplication Table Grid | Moderate |
| [`13_checkerboard.c`](13_checkerboard.c) · [Explanation](13_checkerboard.md) | Checkerboard | Moderate |
| [`14_floyd_triangle.c`](14_floyd_triangle.c) · [Explanation](14_floyd_triangle.md) | Floyd's Triangle | Easy–Moderate |
| [`15_butterfly_pattern.c`](15_butterfly_pattern.c) · [Explanation](15_butterfly_pattern.md) | Butterfly Pattern | Moderate |
| [`16_diamond_pattern.c`](16_diamond_pattern.c) · [Explanation](16_diamond_pattern.md) | Diamond Pattern | Moderate |
| [`17_x_pattern.c`](17_x_pattern.c) · [Explanation](17_x_pattern.md) | X Pattern | Easy–Moderate |
| [`18_plus_pattern.c`](18_plus_pattern.c) · [Explanation](18_plus_pattern.md) | Plus Sign Pattern | Easy |
| [`19_hollow_pyramid.c`](19_hollow_pyramid.c) · [Explanation](19_hollow_pyramid.md) | Hollow Pyramid | Moderate |
| [`20_hourglass_pattern.c`](20_hourglass_pattern.c) · [Explanation](20_hourglass_pattern.md) | Hollow Hourglass | Moderate |
| [`21_binary_triangle.c`](21_binary_triangle.c) · [Explanation](21_binary_triangle.md) | Alternating Binary Triangle | Easy–Moderate |
| [`22_palindromic_number_pyramid.c`](22_palindromic_number_pyramid.c) · [Explanation](22_palindromic_number_pyramid.md) | Palindromic Number Pyramid | Moderate |
| [`23_prime_product_grid.c`](23_prime_product_grid.c) · [Explanation](23_prime_product_grid.md) | Prime-Product Grid | Moderate |

## Learning order
1. Basic loops: square, right triangle, inverted triangle.
2. Numeric patterns: number triangle, repeated numbers, consecutive numbers, Floyd's triangle.
3. Alignment: right-aligned triangle, centered pyramid, inverted pyramid, diamond.
4. Boundary conditions: hollow square, hollow triangle, hollow pyramid, X, plus, hourglass.
5. Pattern rules: checkerboard, binary triangle, butterfly, palindromic pyramid.
6. Conditional helper logic: multiplication grid and prime-product grid.

## Notes
- Every `.c` file has its own `main()` and should be compiled independently.
- `scanf` uses the address of a scalar variable for input; no pointer manipulation or pointer-based data structures are used.
- The source algorithms are based on the user's supplied `patterns.C`.
- The `printPrimeProductGrid` program includes the required `stdbool.h` header for the supplied `bool` helper.
