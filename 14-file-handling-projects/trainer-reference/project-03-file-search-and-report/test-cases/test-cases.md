# File Search & Report Utility — Test Cases

## Test Data

Use:

```text id="c6d8an"
sample-data/sample.txt
```

Contents:

```text id="slp8jf"
C programming is useful.
Programming teaches problem solving.
C is used to build efficient programs.
File handling is an important part of C programming.
Practice makes programming skills stronger.
```

---

# Test 1 — Set Valid File

### Input

```text id="h6qqt8"
1
sample-data/sample.txt
```

### Expected

```text id="3e7u8z"
File selected successfully.
```

---

# Test 2 — Missing File

### Input

```text id="3jlv7k"
1
missing.txt
```

### Expected

```text id="1z1v9s"
Error: Unable to open file.
```

---

# Test 3 — Statistics

Select:

```text id="avw8rm"
2
```

The program should display:

- File name
- Character count
- Word count
- Line count

The exact character count depends on the line-ending format used by the file.

---

# Test 4 — Search Existing Lowercase Word

### Input

```text id="9w0vbn"
3
programming
```

### Expected

The lowercase occurrences should be counted.

The uppercase:

```text id="b6ndy7"
Programming
```

should not be counted because the reference search is case-sensitive.

---

# Test 5 — Search Uppercase Word

### Input

```text id="bqv4a6"
3
Programming
```

### Expected

The uppercase occurrence should be found.

---

# Test 6 — Search Missing Word

### Input

```text id="4q4j2h"
3
database
```

### Expected

```text id="9mb8nj"
Occurrences : 0
```

---

# Test 7 — Complete Word Matching

Use a test file containing:

```text id="p2m35f"
program
programming
program.
program_test
```

Search:

```text id="uxy9j6"
program
```

### Expected

Only:

```text id="4c7g6r"
program
program.
```

should be counted.

`programming` should not match.

---

# Test 8 — Punctuation Handling

Test data:

```text id="4e4kqi"
C, C. C! C? C;
```

Search:

```text id="7v5q3d"
C
```

### Expected

All five occurrences should be recognized as the complete word `C`.

---

# Test 9 — Final Word Without Newline

Create:

```text id="z4y6lw"
hello world
```

with no newline at the end.

Search:

```text id="ys8w6o"
world
```

### Expected

```text id="l8e2f3"
Occurrences: 1
```

---

# Test 10 — Empty File

Create an empty file.

Expected:

```text id="fj2z3q"
Characters : 0
Words      : 0
Lines      : 0
```

---

# Test 11 — Whitespace-Only File

Create:

```text id="i5f0go"
     
```

containing only spaces/tabs/newlines.

Expected:

```text id="y4i4sk"
Words : 0
```

---

# Test 12 — File With Multiple Spaces

Input:

```text id="v1j3l9"
C    programming     is     useful
```

### Expected

Word count:

```text id="w0g5cz"
4
```

---

# Test 13 — File With Tabs

Input:

```text id="c4g8dz"
C	programming	is	useful
```

### Expected

Word count:

```text id="m9x2b4"
4
```

---

# Test 14 — No File Selected

Start the program and select:

```text id="j1h4y9"
2
```

without selecting a file first.

### Expected

```text id="xw4zcb"
Please enter a file name first.
```

---

# Test 15 — Empty Search Word

Select a valid file and choose Search Word.

Press Enter without entering a word.

### Expected

```text id="7j3v1z"
Search word cannot be empty.
```

---

# Test 16 — Invalid Menu Choice

Input:

```text id="9z9j5y"
99
```

### Expected

```text id="n2q0t7"
Invalid choice. Please try again.
```

---

# Trainer Verification Checklist

- [ ] File selection works.
- [ ] Missing files are handled.
- [ ] Character count works.
- [ ] Word count works.
- [ ] Line count works.
- [ ] Search works.
- [ ] Search is case-sensitive as documented.
- [ ] Complete-word matching works.
- [ ] Punctuation boundaries work.
- [ ] Final word is processed.
- [ ] Empty files are handled.
- [ ] Whitespace-only files are handled.
- [ ] Invalid menu choices are handled.
- [ ] Files are closed properly.
- [ ] `fgetc()` uses an `int` variable.