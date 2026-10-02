# Project 3 — File Search & Report Utility

## Trainer Reference

> **Trainer-only material**
>
> This folder contains the complete reference solution, algorithms, test cases, expected results, common mistakes, and trainer notes.
>
> Do not distribute this folder with the student-version materials.

---

# 1. Project Overview

This project combines the concepts from:

- **Q115 — Count Characters, Words and Lines**
- **Q118 — Search a Word and Count Occurrences**

Students create a menu-driven utility that analyzes a text file.

The application supports:

1. Enter File Name
2. File Statistics
3. Search Word
4. Complete Report
5. Exit

---

# 2. Learning Objectives

Students should be able to:

- Open a text file for reading.
- Detect file-opening errors.
- Count characters.
- Count words.
- Count lines.
- Search for a word.
- Count word occurrences.
- Distinguish complete words from substrings.
- Use character classification functions.
- Organize functionality into functions.
- Build a reusable file-analysis utility.

---

# 3. File Analysis Rules

The reference solution uses the following definitions.

## Character Count

Every character read from the file is counted.

This includes:

- Letters
- Digits
- Spaces
- Tabs
- Punctuation
- Newline characters

Therefore:

```c id="ozkm3q"
characters++
```

is performed for every character returned by `fgetc()`.

---

# 4. Word Count

A word is defined as a sequence of non-whitespace characters.

The reference implementation uses:

```c id="x9uv2a"
isspace()
```

Whitespace includes characters such as:

- Space
- Tab
- Newline

Example:

```text id="5qqg5j"
C programming is useful.
```

contains four words:

```text id="m2eq4o"
C
programming
is
useful.
```

Punctuation remains attached to the word for the purpose of basic whitespace-based word counting.

---

# 5. Line Count

A line is counted whenever a newline character is encountered.

The reference implementation also handles a final line that does not end with `\n`.

For example:

```text id="0w2n4h"
Hello
World
```

contains two lines even if `World` has no final newline.

---

# 6. Word Search Definition

The reference solution performs a **complete-word search**.

For example, searching:

```text id="y5f5on"
program
```

should match:

```text id="9i8qyr"
program
```

but should not match:

```text id="u3n8g6"
programming
```

The reference implementation treats punctuation as a boundary.

Therefore:

```text id="y9o3i2"
program.
```

can match the word:

```text id="z7zq9d"
program
```

---

# 7. Case Sensitivity

The reference solution performs a **case-sensitive** search.

Therefore:

```text id="kq7l3x"
C
```

and:

```text id="0y2mt4"
c
```

are different search terms.

Case-insensitive search is provided as an extension task.

---

# 8. Menu

The program displays:

```text id="j4m3pr"
====================================
       FILE SEARCH & REPORT UTILITY
====================================
1. Enter File Name
2. File Statistics
3. Search Word
4. Complete Report
5. Exit
====================================
Enter your choice:
```

---

# 9. Algorithm — Set File Name

```text id="f4sz8f"
START

Ask user for filename.

Remove newline from input.

Check whether the file can be opened.

IF file cannot be opened:
    Display error.

ELSE:
    Close file.
    Store filename.

END
```

---

# 10. Algorithm — Count Characters

```text id="a6q8pn"
START

Open selected file.

characters = 0

Read one character.

WHILE character is not EOF:

    characters++

    Read next character.

Close file.

Return characters.

END
```

---

# 11. Algorithm — Count Words

```text id="pxo5ef"
START

Open selected file.

words = 0
insideWord = false

Read characters one at a time.

WHILE character is not EOF:

    IF character is whitespace:
        insideWord = false

    ELSE IF insideWord is false:
        words++
        insideWord = true

Close file.

Return words.

END
```

---

# 12. Algorithm — Count Lines

```text id="kmbdhi"
START

Open selected file.

lines = 0
hasCharacters = false
lastCharacter = '\0'

Read characters.

For each character:

    hasCharacters = true
    lastCharacter = character

    IF character == '\n':
        lines++

After EOF:

    IF hasCharacters == true
       AND lastCharacter != '\n':

        lines++

Close file.

Return lines.

END
```

This handles files where the final line does not end with a newline.

---

# 13. Algorithm — Search Word

```text id="6f0lh1"
START

Ask user for search word.

Open file.

Build a word character by character.

When a whitespace or punctuation boundary is reached:

    Compare the completed word
    with the search word.

    If they match:
        Increment occurrence count.

Continue until EOF.

Process the final word if necessary.

Close file.

Display occurrence count.

END
```

---

# 14. Why Not Use `strstr()`?

A common beginner solution is:

```c id="fzt4ea"
strstr()
```

But `strstr()` searches for a substring.

For example:

Searching for:

```text id="6csl8e"
program
```

would also match:

```text id="xypi8b"
programming
```

That is not the definition used by this project.

The reference implementation therefore tokenizes the file into words and compares complete words.

---

# 15. Complete Report

The Complete Report combines all analysis operations.

Example:

```text id="y4s4xk"
====================================
           FILE REPORT
====================================
File Name       : sample.txt
Characters      : 235
Words           : 35
Lines           : 7
====================================
```

The user is then asked for a search word:

```text id="f8gqv5"
Enter word to search: programming

Occurrences     : 3
```

---

# 16. Complete Reference Solution

The full implementation is stored in:

```text id="f1g9mx"
solution/file_search.c
```

The implementation demonstrates:

- `FILE`
- `fopen()`
- `fclose()`
- `fgetc()`
- `isspace()`
- `isalnum()`
- Character processing
- Word tokenization
- Searching
- File statistics
- Menu-driven programming
- Error handling

---

# 17. Trainer Teaching Sequence

## Stage 1 — Revisit Q115

Ask students to implement:

```text id="y1ibqk"
Character count
Word count
Line count
```

independently before introducing the complete project.

---

## Stage 2 — Revisit Q118

Ask:

> What is the difference between searching for a substring and searching for a complete word?

Demonstrate:

```text id="l7nj3s"
program
programming
programmer
```

A complete-word search for `program` should not count the other two.

---

## Stage 3 — Character Processing

Introduce:

```c id="vpr9th"
fgetc()
```

and:

```c id="0b9dyx"
EOF
```

Explain that `fgetc()` returns an `int`, not a `char`, because it must also represent `EOF`.

---

## Stage 4 — `isspace()`

Explain:

```c id="m27qyf"
isspace(character)
```

as a convenient way to identify whitespace.

Discuss:

- Space
- Tab
- Newline

---

## Stage 5 — Word Boundary

Explain that word searching requires determining where a word starts and ends.

A simple state machine is useful:

```text id="m0z4k7"
Outside Word
     |
     | non-whitespace
     v
Inside Word
     |
     | whitespace
     v
Outside Word
```

---

# 18. Common Student Mistakes

## Mistake 1 — Forgetting EOF

Incorrect:

```c id="9q9rga"
while (ch != EOF)
{
    ch = fgetc(fp);
}
```

The logic is backwards because `ch` must first receive a character.

Better:

```c id="q3ot8v"
while ((ch = fgetc(fp)) != EOF)
{
    /* process character */
}
```

---

## Mistake 2 — Using `char` for EOF

Prefer:

```c id="j0k10k"
int ch;
```

rather than:

```c id="4qv0pu"
char ch;
```

when reading with `fgetc()`.

---

## Mistake 3 — Counting Every Non-Space as a New Word

Incorrect logic:

```text id="t9a8ri"
every non-space character = word
```

A word may contain many characters.

The `insideWord` state prevents multiple counts.

---

## Mistake 4 — Incorrect Line Count

Students may forget the final line when a file does not end with `\n`.

---

## Mistake 5 — Substring Search

Using:

```c id="j2y8ly"
strstr()
```

can produce false matches for complete-word searching.

---

## Mistake 6 — Forgetting the Final Word

If the file ends immediately after a word, there may be no whitespace character to trigger processing.

The final word must therefore be handled after EOF.

---

# 19. Sample Analysis

Sample file:

```text id="0k7xxp"
C programming is useful.
Programming teaches problem solving.
C is used to build efficient programs.
File handling is an important part of C programming.
Practice makes programming skills stronger.
```

Note that the reference implementation uses case-sensitive word matching.

For:

```text id="z9c5b7"
programming
```

the exact lowercase word occurs where lowercase `programming` appears.

The uppercase:

```text id="w0e9yb"
Programming
```

is a different word for the default search.

---

# 20. Extension Tasks

### Extension 1 — Case-Insensitive Search

Make:

```text id="qf3v7u"
Programming
programming
PROGRAMMING
```

count as the same word.

---

### Extension 2 — Search Multiple Words

Allow:

```text id="c1q9pw"
programming
file
C
```

and report each count.

---

### Extension 3 — Most Frequent Word

Find the most frequently occurring word in the file.

This introduces:

- Arrays
- Structures
- Dynamic memory
- Searching/sorting

depending on the implementation.

---

### Extension 4 — Longest Line

Find and display the longest line.

---

### Extension 5 — Save Report

Write the generated report into:

```text id="7i9zv5"
report.txt
```

---

### Extension 6 — Multiple Files

Allow the user to analyze multiple files without restarting the program.

---

### Extension 7 — File Comparison

Compare two files and report whether their contents are identical.

---

# 21. Trainer Discussion Questions

Ask students:

1. Why does `fgetc()` return `int`?
2. What is `EOF`?
3. What counts as a character?
4. What is the definition of a word in this project?
5. Why is `isspace()` useful?
6. Why can `strstr()` give incorrect results?
7. How do you process the final word?
8. How do you handle a final line without `\n`?
9. How would you make searching case-insensitive?
10. How would you find the most frequent word?

---

# 22. Trainer Assessment

Suggested weighting:

| Area | Weight |
|---|---:|
| File handling | 20% |
| Character counting | 15% |
| Word counting | 20% |
| Line counting | 15% |
| Word search | 20% |
| Error handling/program structure | 10% |

These weights are suggestions and can be adjusted.

---

# 23. Trainer Checklist

- [ ] Student can open a text file.
- [ ] Student checks `fopen()`.
- [ ] Student understands `EOF`.
- [ ] Student can count characters.
- [ ] Student can count words.
- [ ] Student can count lines.
- [ ] Student understands word boundaries.
- [ ] Student can perform complete-word search.
- [ ] Student can count occurrences.
- [ ] Student handles final words correctly.
- [ ] Student handles final lines correctly.
- [ ] Student can explain the complete report.

---

# 24. Reference Folder

```text id="wmv5th"
project-03-file-search-and-report/
├── README.md
├── solution/
│   └── file_search.c
├── test-cases/
│   └── test-cases.md
└── sample-data/
    └── sample.txt
```

Keep this folder separate from:

```text id="u7a0ig"
student-version/project-03-file-search-and-report/
```

Students should receive only the student-version materials.