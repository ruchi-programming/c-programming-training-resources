# Project 1 — Student Record Manager

## Trainer Reference

> **Trainer-only material**
>
> This folder contains the complete solution, algorithm, test cases, expected results, and teaching notes.
>
> Do not distribute this folder with the student project materials.

---

# 1. Project Overview

This project extends the file-handling concepts introduced in **Q114 — Student Details Write/Read File**.

Students build a menu-driven application that stores student records in a text file.

Each student record contains:

- Roll Number
- Name
- Marks

The application supports:

1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Exit

The project reinforces:

- Structures
- Text files
- File modes
- Functions
- Searching
- Updating records
- Temporary files
- Error handling
- Menu-driven programming

---

# 2. Learning Objectives

After completing this project, students should understand:

- How to store structures in text files.
- How to append records without deleting existing records.
- How to read records using `fscanf()`.
- How to search records.
- How to update an existing record.
- Why a temporary file is useful for updating text files.
- How to validate file operations.
- How to separate program functionality into functions.

---

# 3. Data Format

The application stores records in:

```text
students.txt
```

Each line follows:

```text
rollNumber name marks
```

Example:

```text
101 Rahul 85.50
102 Priya 91.00
103 Amit 76.50
```

---

# 4. Algorithm

## Add Student

```text
START

Open students.txt in append mode.

If file cannot be opened:
    Display error.
    Return.

Read roll number.
Read student name.
Read marks.

Validate input.

Write student record to file.

Close file.

Display success message.

END
```

---

## Display Students

```text
START

Open students.txt in read mode.

If file cannot be opened:
    Display error.
    Return.

Read one student record.

While a record is available:
    Display the record.
    Read the next record.

Close file.

END
```

---

## Search Student

```text
START

Ask for roll number.

Open students.txt in read mode.

If file cannot be opened:
    Display error.
    Return.

Set found = 0.

Read each record.

If roll number matches:
    Display student.
    Set found = 1.
    Stop searching.

If found == 0:
    Display "Student not found."

Close file.

END
```

---

## Update Student

A text file should not normally be modified directly in the middle of an existing record.

Therefore, use a temporary file.

```text
START

Ask for roll number to update.

Open students.txt for reading.

Open temp.txt for writing.

If either file fails:
    Display error.
    Close any opened files.
    Return.

Read each student record.

If roll number matches:
    Ask for new name.
    Ask for new marks.
    Write updated record to temp.txt.
    Set found = 1.
Else:
    Write original record to temp.txt.

Close both files.

If found == 1:
    Delete students.txt.
    Rename temp.txt to students.txt.
    Display success.
Else:
    Delete temp.txt.
    Display "Student not found."

END
```

---

# 5. File Modes Used

| Operation | Mode | Reason |
|---|---|---|
| Add student | `"a"` | Preserve existing records |
| Display | `"r"` | Read records |
| Search | `"r"` | Read records |
| Update source | `"r"` | Read existing records |
| Update temporary file | `"w"` | Create replacement file |

### Important Teaching Point

Students should understand why `"w"` must not be used for adding records.

Using:

```c
fopen(FILE_NAME, "w");
```

would overwrite the existing file.

For adding records:

```c
fopen(FILE_NAME, "a");
```

is appropriate.

---

# 6. Complete Solution

The complete trainer solution is available in:

```text
solution/student_record_manager.c
```

The solution demonstrates:

- Structure definition
- Function prototypes
- Menu-driven programming
- File opening and closing
- Append mode
- Reading records
- Searching
- Updating using a temporary file
- Basic validation

---

# 7. Expected Program Flow

Example:

```text
====================================
      STUDENT RECORD MANAGER
====================================
1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Exit
====================================
Enter your choice: 1

Enter roll number: 101
Enter name: Rahul
Enter marks: 85.50

Student added successfully.
```

Display:

```text
====================================
      STUDENT RECORD MANAGER
====================================

Roll No    Name                 Marks
----------------------------------------
101        Rahul                85.50
102        Priya                91.00
103        Amit                 76.50
```

Search:

```text
Enter roll number to search: 102

Student Found

Roll Number: 102
Name: Priya
Marks: 91.00
```

Update:

```text
Enter roll number to update: 103

Enter new name: Amit Kumar
Enter new marks: 82.00

Student updated successfully.
```

---

# 8. Trainer Teaching Notes

## Before the Project

Ask students:

1. What is a file?
2. Why do we need files?
3. What is the difference between `"r"`, `"w"` and `"a"`?
4. What happens when `fopen()` fails?
5. Why should `fclose()` be called?

---

## During Add Student

Emphasize:

```c
"a"
```

rather than:

```c
"w"
```

Ask students:

> "What would happen if we used `"w"` every time the user added a student?"

Expected answer:

> Existing data would be overwritten.

---

## During Display

Explain the relationship between:

```c
fopen()
fscanf()
fclose()
```

Students should understand that records are read sequentially.

---

## During Search

Introduce the concept:

```text
Sequential Search
```

The program checks each record until:

- The student is found, or
- End of file is reached.

---

## During Update

This is the most important teaching section.

Explain why the program uses:

```text
students.txt
       ↓
     READ
       ↓
   temp.txt
       ↓
 updated records
```

Then:

```text
Delete students.txt
Rename temp.txt → students.txt
```

This is a common technique for modifying text-file records.

---

# 9. Common Student Mistakes

### Mistake 1 — Using `"w"` for Add

Incorrect:

```c
fopen(FILE_NAME, "w");
```

This can erase existing records.

---

### Mistake 2 — Not Checking `fopen()`

Incorrect:

```c
FILE *fp = fopen(FILE_NAME, "r");

fscanf(fp, ...);
```

If the file cannot be opened, `fp` may be `NULL`.

---

### Mistake 3 — Forgetting `fclose()`

Every successfully opened file should eventually be closed.

---

### Mistake 4 — Incorrect Update Logic

Students may attempt to modify an existing text-file record directly.

Explain why using a temporary file is simpler and safer for this beginner project.

---

### Mistake 5 — Incorrect `fscanf()` Loop

Students sometimes create an infinite loop by not checking the return value.

A suitable pattern is:

```c
while (fscanf(fp, "%d %49s %f",
              &student.rollNumber,
              student.name,
              &student.marks) == 3)
{
    /* process record */
}
```

---

# 10. Validation

The reference solution performs basic validation.

Recommended rules:

### Roll Number

- Must be positive.
- Duplicate roll numbers should ideally be prevented.

### Name

- Must not be empty.

### Marks

- Should be between `0` and `100`.

### Menu

- Invalid choices should display an error.

---

# 11. Extension Tasks

After students complete the required project, assign optional extensions.

### Extension 1

Prevent duplicate roll numbers.

### Extension 2

Delete a student.

### Extension 3

Calculate average marks.

### Extension 4

Find the student with the highest marks.

### Extension 5

Count the number of students.

### Extension 6

Display students whose marks are above a specified value.

### Extension 7

Allow names containing spaces.

### Extension 8

Sort students by marks.

---

# 12. Trainer Assessment

Suggested assessment areas:

| Area | Suggested Weight |
|---|---:|
| File handling | 25% |
| Structure usage | 15% |
| Functions | 15% |
| Add/display/search | 20% |
| Update implementation | 15% |
| Validation/error handling | 10% |

These weights are suggested for trainer use and can be changed according to the course.

---

# 13. Discussion Questions

Ask students:

1. Why does the program use `"a"` when adding records?
2. What happens if `students.txt` does not exist?
3. How does the search operation work?
4. Why is a temporary file useful during update?
5. What does `fscanf()` return?
6. How can duplicate roll numbers be prevented?
7. How would you support names containing spaces?
8. How would you delete a record?
9. How would you sort the records?
10. What would change if binary files were used?

---

# 14. Trainer Checklist

- [ ] Student understands file modes.
- [ ] Student understands structures.
- [ ] Student can append records.
- [ ] Student can read records.
- [ ] Student can search records.
- [ ] Student understands sequential search.
- [ ] Student understands temporary-file updates.
- [ ] Student checks `fopen()`.
- [ ] Student closes files.
- [ ] Student validates input.
- [ ] Student can explain the program logic.

---

# 15. Reference Files

```text
project-01-student-record-manager/
├── README.md
├── solution/
│   └── student_record_manager.c
└── test-cases/
    └── test-cases.md
```

This trainer-reference project should remain separate from:

```text
student-version/
```

Students should receive only the student-version materials.