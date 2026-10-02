# Project 4 — File Backup & Copy Utility

## Trainer Test Cases

---

## Test Case 1 — Select Valid Source

**Input**

```text
1
..\sample-data\source.txt
```

**Expected**

```text
Source file selected successfully.
```

**Result:** Pass / Fail

---

## Test Case 2 — Select Missing Source

**Input**

```text
1
missing.txt
```

**Expected**

```text
Error: Unable to open source file.
```

**Result:** Pass / Fail

---

## Test Case 3 — Empty Source Filename

**Input**

```text
1

```

**Expected**

```text
Source filename cannot be empty.
```

**Result:** Pass / Fail

---

## Test Case 4 — Display Source

First select:

```text
..\sample-data\source.txt
```

Then choose:

```text
2
```

**Expected**

The complete sample file contents are displayed.

**Result:** Pass / Fail

---

## Test Case 5 — Display Without Source

Start the program and immediately choose:

```text
2
```

**Expected**

```text
Please select a source file first.
```

**Result:** Pass / Fail

---

## Test Case 6 — Create Backup

Select the sample source and choose:

```text
3
```

Enter:

```text
backup.txt
```

**Expected**

```text
Backup completed successfully.
```

A `backup.txt` file should be created in the current working directory.

**Result:** Pass / Fail

---

## Test Case 7 — Verify Identical Backup

After creating the backup, choose:

```text
4
```

**Expected**

```text
Verification successful.
Source and backup files are identical.
```

**Result:** Pass / Fail

---

## Test Case 8 — Modify Backup

After creating `backup.txt`, modify one character manually.

Then run:

```text
4
```

**Expected**

```text
Verification failed.
Source and backup files are different.
```

**Result:** Pass / Fail

---

## Test Case 9 — Backup Is Longer

Change the backup so it contains additional text.

Example:

```text
C programming is useful.
File handling is important.
Reading and writing files is a practical C skill.
Practice makes programming easier.
EXTRA DATA
```

Run verification.

**Expected**

Files are reported as different.

**Result:** Pass / Fail

---

## Test Case 10 — Backup Is Shorter

Remove the last line from the backup.

Run verification.

**Expected**

Files are reported as different.

**Result:** Pass / Fail

---

## Test Case 11 — Same Source and Destination

Select:

```text
..\sample-data\source.txt
```

Choose copy and enter:

```text
..\sample-data\source.txt
```

**Expected**

```text
Error: Source and destination cannot be the same file.
```

The original source file must remain unchanged.

**Result:** Pass / Fail

---

## Test Case 12 — Empty Backup Filename

Choose copy and enter an empty filename.

**Expected**

```text
Backup filename cannot be empty.
```

**Result:** Pass / Fail

---

## Test Case 13 — Verify Before Backup

Start a new program session.

Select the source but do not create a backup.

Choose:

```text
4
```

**Expected**

```text
No backup file is available for verification.
Please create a backup first.
```

**Result:** Pass / Fail

---

## Test Case 14 — Copy Empty File

Create an empty file and use it as the source.

Copy it.

**Expected**

- Backup is created successfully.
- Bytes copied should be `0`.
- Verification should report identical files.

**Result:** Pass / Fail

---

## Test Case 15 — Invalid Menu Choice

Enter:

```text
99
```

**Expected**

```text
Invalid choice. Please try again.
```

**Result:** Pass / Fail

---

## Test Case 16 — Non-Numeric Menu Input

Enter:

```text
abc
```

**Expected**

```text
Invalid input. Please enter a number.
```

The program should continue running.

**Result:** Pass / Fail

---

# Expected Core Behavior

The completed program should satisfy:

```text
Valid source
     |
     v
Display
     |
     v
Copy
     |
     v
Backup created
     |
     v
Verify
     |
     v
Identical
```

If the backup is modified:

```text
Source
  |
  +-------> Backup
               |
               v
          Modified
               |
               v
          Verification
               |
               v
           Different
```

---

# Trainer Observation Points

During evaluation, check whether the student:

- Uses `FILE *`
- Checks `fopen()` results
- Uses `fgetc()` correctly
- Stores `fgetc()` results in `int`
- Uses `fputc()` for copying
- Uses `fclose()`
- Handles `EOF`
- Prevents same-file copying
- Detects files of different lengths
- Handles missing files
- Organizes the program into functions