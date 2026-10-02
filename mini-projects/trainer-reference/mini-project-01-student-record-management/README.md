# Mini Project 01 — Student Record Management System

## Trainer Reference

> **TRAINER ONLY — DO NOT DISTRIBUTE THIS FOLDER AS THE STUDENT SOLUTION.**

---

## 1. Project Overview

The Student Record Management System is a menu-driven C application for maintaining student records.

The project combines several fundamental C programming concepts:

- Structures
- Arrays
- Functions
- File handling
- Searching
- Updating
- Deleting
- Input validation
- Menu-driven programming

The project is suitable as a capstone exercise after students have learned basic structures and file handling.

---

# 2. Student Record

Each student contains:

```c
struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};
```

---

# 3. Required Features

The program provides:

```text
1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Student Statistics
7. Exit
```

---

# 4. File Storage

Student records are stored in:

```text
students.txt
```

Example:

```text
101 Rahul 85.50
102 Priya 91.00
103 Amit 76.50
```

The program uses text-file storage.

---

# 5. Learning Objectives

Students should learn to:

- Define and use structures
- Store multiple records in a file
- Append new records
- Read records sequentially
- Search records
- Update records
- Delete records
- Calculate statistics
- Validate user input
- Work with temporary files

---

# 6. Menu Algorithms

## Add Student

```text
START
 |
Read roll number
 |
Check duplicate roll number
 |
Read student name
 |
Read marks
 |
Validate marks
 |
Open file in append mode
 |
Write record
 |
Close file
 |
END
```

---

## Display Students

```text
START
 |
Open students.txt
 |
Read one student
 |
Display student
 |
Read next student
 |
Repeat until EOF
 |
Close file
 |
END
```

---

## Search Student

```text
START
 |
Read roll number
 |
Open file
 |
Read records
 |
Compare roll number
 |
If found -> display record
 |
Continue/end
 |
Close file
 |
END
```

---

## Update Student

The update operation uses a temporary file.

```text
Open original file
       |
       v
Open temporary file
       |
       v
Read each student
       |
       +---- matching roll?
       |          |
       |         YES
       |          |
       |     Read new data
       |          |
       v          v
Write record to temporary file
       |
       v
Continue until EOF
       |
       v
Close files
       |
       v
Replace original file
```

This demonstrates an important real-world file technique.

---

## Delete Student

Deletion follows a similar temporary-file approach.

```text
Original file
     |
     v
Read each record
     |
     +---- Target student?
     |          |
     |         YES
     |          |
     |      Skip record
     |
     NO
     |
Write record to temp file
     |
     v
Replace original file
```

---

# 7. Statistics

The statistics option should calculate:

- Total students
- Average marks
- Highest marks
- Lowest marks
- Number of students passing

For this project:

```text
Pass marks = 40.00
```

---

# 8. Validation Rules

### Roll Number

Must be positive.

### Duplicate Roll Number

Not allowed.

### Name

Must not be empty.

### Marks

Valid range:

```text
0.00 to 100.00
```

---

# 9. Trainer Teaching Sequence

### Stage 1

Review structures.

### Stage 2

Create a single student record.

### Stage 3

Write one record to a file.

### Stage 4

Read all records.

### Stage 5

Add searching.

### Stage 6

Introduce temporary-file updating.

### Stage 7

Introduce deletion.

### Stage 8

Add statistics.

---

# 10. Common Mistakes

Students commonly:

- Forget to check `fopen()`
- Use `"w"` instead of `"a"` when adding
- Forget to close files
- Allow duplicate roll numbers
- Forget to remove `\n` from `fgets()`
- Corrupt the original file during update
- Forget to replace the temporary file
- Divide by zero when there are no records

---

# 11. Extension Ideas

Advanced students can add:

- Student grade
- Date of birth
- Course/department
- Phone number
- Sorting
- Top-performing student
- Subject-wise marks
- CSV export
- Login system
- Attendance
- Multiple classes
- Binary file storage

---

# 12. Trainer Assessment

| Area | Marks |
|---|---:|
| Structures | 10 |
| Add | 10 |
| Display | 10 |
| Search | 10 |
| Update | 15 |
| Delete | 15 |
| Statistics | 10 |
| Validation | 10 |
| File handling | 5 |
| Code quality | 5 |
| **Total** | **100** |