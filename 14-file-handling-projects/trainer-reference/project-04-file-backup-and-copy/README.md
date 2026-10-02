# Project 4 — File Backup & Copy Utility

## Trainer Reference

> **TRAINER ONLY — DO NOT DISTRIBUTE THE `trainer-reference` FOLDER TO STUDENTS.**

---

# 1. Project Overview

This project extends **Q117 — Copy a File** into a practical file backup and verification utility.

The original exercise introduces copying data from one file to another.

This project adds:

- Source-file selection
- Source-file display
- File copying
- Backup tracking
- Byte/character counting during copy
- Backup verification
- Error handling
- Menu-driven program design

The project is intended to reinforce fundamental C file handling before students move toward larger file-processing applications.

---

# 2. Learning Objectives

Students should demonstrate understanding of:

- `FILE *`
- `fopen()`
- `fgetc()`
- `fputc()`
- `fclose()`
- `EOF`
- Reading files character by character
- Writing files character by character
- File-open error handling
- File comparison
- Functions
- Global state versus local variables
- Menu-driven programming
- Input validation

---

# 3. Connection to Q117

### Q117 Concept

Copy one file into another.

### Project Extension

Build a utility that can:

1. Select a source file
2. Display the source file
3. Copy the source into a backup file
4. Remember the backup filename
5. Verify that source and backup are identical

This transforms a single file-copy exercise into a complete mini-project.

---

# 4. Program Menu

```text
====================================
       FILE BACKUP & COPY UTILITY
====================================
1. Enter Source File
2. Display Source File
3. Copy / Backup File
4. Verify Backup
5. Exit
====================================
```

---

# 5. Functional Requirements

## 5.1 Enter Source File

The user enters a source filename.

The program should:

- Store the filename
- Remove the trailing newline
- Check whether the file can be opened
- Reject an empty filename
- Clear the previous selection if the file does not exist

---

## 5.2 Display Source File

The selected file is opened using read mode.

The contents are displayed character by character.

Important teaching point:

```c
int ch;
```

should be used for the result of `fgetc()`.

Correct pattern:

```c
while ((ch = fgetc(fp)) != EOF)
{
    putchar(ch);
}
```

---

## 5.3 Copy / Backup File

The user supplies a destination filename.

The program should:

- Verify that a source file has been selected
- Reject an empty destination
- Prevent source and destination from being the same filename
- Open source for reading
- Open destination for writing
- Copy every byte/character
- Count copied bytes
- Close both files
- Remember the backup filename

The trainer solution uses:

```text
rb
wb
```

rather than:

```text
r
w
```

This allows the implementation to copy arbitrary file data safely rather than only ordinary text.

---

## 5.4 Verify Backup

The source and backup files are compared byte by byte.

The files are considered identical only when:

- Every corresponding byte matches
- Both files reach the end at the same time

Examples:

```text
Source:  ABC
Backup:  ABC

Result: Identical
```

```text
Source:  ABC
Backup:  ABD

Result: Different
```

```text
Source:  ABC
Backup:  ABCD

Result: Different
```

---

# 6. File Modes

The reference implementation uses binary-safe modes:

### Source

```c
fopen(filename, "rb");
```

### Destination

```c
fopen(filename, "wb");
```

Although the sample data is text, using binary modes makes the copy operation appropriate for both text and binary files.

Trainer discussion:

- `"r"` / `"w"` are text-oriented modes.
- `"rb"` / `"wb"` explicitly request binary mode.
- On some platforms, especially Windows, text mode can translate certain characters such as newline sequences.
- Binary mode is therefore preferable for a general-purpose copy utility.

---

# 7. Algorithm — Select Source File

```text
START
  |
Ask for source filename
  |
Read filename
  |
Remove newline
  |
Is filename empty?
  |---- YES ---> Display error
  |
  NO
  |
Open source file in "rb"
  |
Was file opened?
  |---- NO ---> Display error and clear selection
  |
  YES
  |
Close file
  |
Store source filename
  |
Display success
  |
END
```

---

# 8. Algorithm — Display Source File

```text
START
  |
Has source file been selected?
  |---- NO ---> Display warning
  |
  YES
  |
Open source file
  |
Was it opened successfully?
  |---- NO ---> Display error
  |
  YES
  |
Read one byte
  |
Is it EOF?
  |---- YES ---> Close file
  |
  NO
  |
Display byte
  |
Read next byte
  |
Repeat
  |
END
```

---

# 9. Algorithm — Copy File

```text
START
  |
Has source file been selected?
  |---- NO ---> Display warning
  |
  YES
  |
Ask for destination filename
  |
Read filename
  |
Is destination empty?
  |---- YES ---> Display error
  |
  NO
  |
Are source and destination names identical?
  |---- YES ---> Reject operation
  |
  NO
  |
Open source in "rb"
  |
Open destination in "wb"
  |
Read one byte from source
  |
Is EOF reached?
  |---- YES ---> Close files
  |
  NO
  |
Write byte to destination
  |
Increase copied-byte counter
  |
Repeat
  |
Close both files
  |
Remember backup filename
  |
Display success
  |
END
```

---

# 10. Algorithm — Verify Backup

```text
START
  |
Has source been selected?
  |---- NO ---> Display warning
  |
  YES
  |
Has backup been created?
  |---- NO ---> Display warning
  |
  YES
  |
Open source
  |
Open backup
  |
Read one byte from source
  |
Read one byte from backup
  |
Do bytes differ?
  |---- YES ---> Files are different
  |
  NO
  |
Are both EOF?
  |---- YES ---> Files are identical
  |
  NO
  |
Repeat
  |
END
```

---

# 11. Why Compare Until Both Files End?

Checking only the bytes that exist in the first file is insufficient.

Example:

```text
Source  = HELLO
Backup  = HELLO123
```

The first five bytes match.

However, the files are not identical.

The comparison must therefore continue until the end of both streams is reached.

A useful condition is:

```c
while (sourceChar != EOF || backupChar != EOF)
```

Inside the loop, a difference exists if:

```c
sourceChar != backupChar
```

---

# 12. Important `fgetc()` Concept

`fgetc()` returns an `int`.

This is important because the return value must be able to represent:

- Every possible byte value
- `EOF`

Therefore:

```c
int ch;
```

is correct.

Avoid:

```c
char ch;
```

for storing the direct return value of `fgetc()` when testing against `EOF`.

---

# 13. Why `fputc()` Is Used

The copy operation can be implemented as:

```c
while ((ch = fgetc(source)) != EOF)
{
    fputc(ch, destination);
}
```

This directly demonstrates the fundamental relationship:

```text
fgetc()  ---> read one byte
fputc()  ---> write one byte
```

It is simple enough for beginners to understand and powerful enough to demonstrate the basic file-copy operation.

---

# 14. Same-File Protection

The solution rejects:

```text
source.txt
```

as the destination when the selected source is also:

```text
source.txt
```

Without this check, opening the destination using `"wb"` would truncate the source file before copying it.

That would destroy the original contents.

The basic implementation compares the filenames as strings.

Trainer extension:

Two different path strings can still refer to the same physical file.

For example:

```text
source.txt
.\source.txt
```

A more advanced implementation would resolve paths or compare file metadata.

That is outside the required beginner-level scope.

---

# 15. Error Handling

The reference implementation handles:

- No source file selected
- Source file does not exist
- Source file cannot be opened
- Empty source filename
- Empty backup filename
- Destination cannot be created
- Source and destination filenames are identical
- Backup not yet created
- Verification open failure

The program should never silently continue after a critical file-open failure.

---

# 16. Trainer Teaching Sequence

Recommended sequence:

### Stage 1 — Review Q117

Ask students to explain:

```c
FILE *source;
FILE *destination;
```

and:

```c
while ((ch = fgetc(source)) != EOF)
{
    fputc(ch, destination);
}
```

---

### Stage 2 — Discuss File Modes

Ask:

- Why do we open the source for reading?
- Why do we open the destination for writing?
- What happens to an existing destination file when `"wb"` is used?

---

### Stage 3 — Implement Display

Have students read the source file character by character.

---

### Stage 4 — Implement Copy

Students implement the basic copy algorithm.

---

### Stage 5 — Add Verification

Students compare source and destination independently.

This is an important distinction:

**Copying** writes data.

**Verification** reads two files and compares data.

---

### Stage 6 — Add Error Handling

Introduce:

```c
if (fp == NULL)
```

and discuss why every `fopen()` should be checked.

---

# 17. Common Student Mistakes

## Mistake 1 — Using `char` for `fgetc()`

Incorrect:

```c
char ch;
while ((ch = fgetc(fp)) != EOF)
```

Explain that `fgetc()` returns `int`.

---

## Mistake 2 — Forgetting `fclose()`

Students may open several files and forget to close them.

Emphasize:

```c
fclose(fp);
```

---

## Mistake 3 — Not Checking `fopen()`

Incorrect:

```c
fp = fopen(filename, "rb");
fgetc(fp);
```

If the file cannot be opened, this is unsafe.

---

## Mistake 4 — Using `"w"` on the Source

The source must never be opened for writing during a normal copy.

Opening with `"w"` can truncate the file.

---

## Mistake 5 — Copying Only Until the Source Ends

The copy itself is straightforward, but verification must ensure both files end together.

---

## Mistake 6 — No Same-File Check

If:

```text
source.txt
```

is copied to:

```text
source.txt
```

the destination opening can destroy the source before copying.

---

## Mistake 7 — Forgetting to Remember the Backup

If verification happens later, the program needs to know which backup file to compare.

---

# 18. Sample Data

File:

```text
sample-data/source.txt
```

Contents:

```text
C programming is useful.
File handling is important.
Reading and writing files is a practical C skill.
Practice makes programming easier.
```

---

# 19. Expected Copy Result

If the destination is:

```text
backup.txt
```

then the destination should contain exactly:

```text
C programming is useful.
File handling is important.
Reading and writing files is a practical C skill.
Practice makes programming easier.
```

The copy operation should report the number of bytes copied.

---

# 20. Assessment Criteria

Suggested assessment:

| Area | Marks |
|---|---:|
| Menu and program flow | 10 |
| Source-file selection | 10 |
| File display | 10 |
| File copying | 20 |
| Backup verification | 20 |
| Error handling | 10 |
| Correct use of file functions | 10 |
| Code quality | 10 |
| **Total** | **100** |

---

# 21. Extension Activities

Advanced students can implement:

1. File-size reporting
2. Automatic backup filenames
3. Backup directory support
4. Multiple backup versions
5. Backup history
6. Timestamped backup names
7. Recursive directory backup
8. Binary-file testing
9. Copy progress reporting
10. Checksum/hash-based verification

For checksum/hash functionality, introduce the concept separately rather than requiring students to implement a cryptographic algorithm from scratch.

---

# 22. Trainer Discussion Questions

1. Why does `fgetc()` return `int`?
2. What happens when a file is opened using `"wb"`?
3. Why should a source file be protected from being used as its own destination?
4. Why is binary mode useful for a general-purpose copy utility?
5. How can two files be compared?
6. Why is checking only the first file's EOF insufficient?
7. What happens if the backup file is longer than the source?
8. What happens if the backup file is shorter?
9. Why should files be closed?
10. What resources does a `FILE *` represent?
11. Why should every `fopen()` be checked?
12. How could the utility be extended to create timestamped backups?

---

# 23. Trainer Checklist

Before marking the project complete, verify:

- [ ] Menu works
- [ ] Source file can be selected
- [ ] Missing source file is handled
- [ ] Source contents can be displayed
- [ ] Destination filename can be entered
- [ ] File copy works
- [ ] Number of copied bytes is reported
- [ ] Backup filename is remembered
- [ ] Same source/destination is rejected
- [ ] Backup verification works
- [ ] Different files are detected
- [ ] Different file lengths are detected
- [ ] Files are closed
- [ ] `EOF` is handled correctly
- [ ] `fgetc()` results are stored in `int`
- [ ] Program compiles without warnings
- [ ] Test cases pass

---

# 24. Key Concepts Reinforced

This project reinforces:

```text
Q117
  |
  v
Copy a File
  |
  +-- fopen()
  |
  +-- fgetc()
  |
  +-- fputc()
  |
  +-- fclose()
  |
  v
Project 4
  |
  +-- Source selection
  +-- File display
  +-- File copying
  +-- Backup tracking
  +-- File comparison
  +-- Error handling
  +-- Verification
```

The project should prepare students for more advanced file-processing applications involving multiple records, searching, reporting, and persistent data.