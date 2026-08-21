# Grade Classifier in C

This program demonstrates input validation and multi-way decision-making with `if`, `else if` and `else`.

## Learning objectives

After completing this example, a learner should be able to:

- Form relational and logical conditions
- Validate an input range
- Build an ordered `else if` ladder
- Explain why condition order matters
- Test threshold boundaries
- Distinguish invalid input from valid low marks

## Source file

The complete program is available in [`grade_classifier.c`](grade_classifier.c).

## Classification rules

| Marks | Result |
|---:|---|
| 80–100 | Grade A |
| 60–79 | Grade B |
| 40–59 | Grade C |
| 0–39 | Grade F |
| Below 0 or above 100 | Invalid |

## Why the conditions are ordered from highest to lowest

The first true branch is executed and the remaining branches are skipped.

Therefore:

```c
if (marks >= 80)
```

must appear before:

```c
else if (marks >= 60)
```

If the lower threshold were tested first, a mark such as `85` could be placed into the wrong category.

## Input validation

```c
if (scanf("%d", &marks) != 1)
```

This checks whether one integer was successfully read.

```c
if (marks < 0 || marks > 100)
```

The logical OR operator rejects a value when either invalid condition is true.

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic grade_classifier.c -o grade_classifier
./grade_classifier
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic grade_classifier.c -o grade_classifier.exe
.\grade_classifier.exe
```

## Boundary tests

| Input | Expected result |
|---:|---|
| `-1` | Invalid range |
| `0` | Grade F |
| `39` | Grade F |
| `40` | Grade C |
| `59` | Grade C |
| `60` | Grade B |
| `79` | Grade B |
| `80` | Grade A |
| `100` | Grade A |
| `101` | Invalid range |

## Knowledge check

1. Why is input validation performed before grade classification?
2. Why is the highest threshold tested first?
3. What does the `||` operator mean?
4. How many branches can execute in one `if`–`else if` ladder?
5. What grade is produced for each boundary value?

## Practice extensions

1. Add Grade D for marks from 30 to 39.
2. Print “Distinction” with Grade A.
3. Add attendance as a second eligibility condition.
4. Convert the grade letters to user-defined descriptions.
5. Create a menu that classifies multiple students.

## Common mistakes

- Testing thresholds in the wrong order
- Using `&&` instead of `||` for invalid-range detection
- Omitting an equality boundary
- Using separate `if` statements when only one result should be produced
- Using `=` instead of `==` when equality is required
- Testing only middle values and ignoring boundaries

## Standard used

This example uses standard C syntax and standard library facilities compatible with C17.
