# Project 1 – Student Record Manager

## Overview

In Q114, you learned how to write student details to a file and read them back.

Now you will extend that idea into a small **Student Record Manager**.

The goal of this project is to practice file handling in C while building a menu-driven application.

> **Prerequisite:** Complete Q114–Q118 before starting this project.

---

## Learning Objectives

By completing this project, you will practice:

- Opening and closing files
- Reading data from files
- Writing data to files
- Appending records
- Searching records
- Updating records
- Working with structures
- Using functions
- Building menu-driven programs
- Handling file-opening errors
- Testing a program with multiple records

---

# Problem Statement

Create a menu-driven C program that manages student records using a file.

Each student record should contain:

- Roll Number
- Student Name
- Marks

The program should store the records in a file so that the data is available even after the program exits.

---

# Menu Requirements

Your program should display a menu similar to:

```text
====================================
       STUDENT RECORD MANAGER
====================================

1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Exit

Enter your choice:
```

You may design your own menu appearance.

---

# Functional Requirements

## 1. Add Student

The user should be able to enter:

```text
Roll Number
Name
Marks
```

The record must be stored in the student data file.

### Requirements

- Do not overwrite existing records.
- A new student should be added to the existing data.
- Check whether the file can be opened.
- Close the file after use.

---

# 2. Display All Students

Read all student records from the file and display them.

Example format:

```text
====================================
          STUDENT RECORDS
====================================

Roll No    Name                 Marks
-----------------------------------------
101        Rahul                85.50
102        Priya                91.00
103        Amit                 76.50
```

If there are no records, display an appropriate message.

---

# 3. Search Student

Allow the user to search for a student using the **roll number**.

Example:

```text
Enter roll number to search: 102

Student Found

Roll Number : 102
Name        : Priya
Marks       : 91.00
```

If the roll number does not exist:

```text
Student not found.
```

---

# 4. Update Student

Allow the user to update the marks of an existing student.

Example:

```text
Enter roll number to update: 103

Current Marks: 76.50
Enter new marks: 82.00

Record updated successfully.
```

If the student does not exist:

```text
Student not found.
```

---

# 5. Exit

The program should terminate when the user selects Exit.

---

# File Requirements

Use a file to permanently store student records.

Suggested filename:

```text
students.txt
```

You may choose another filename if you prefer.

The file should contain enough information to reconstruct each student record.

For example:

```text
101 Rahul 85.50
102 Priya 91.00
103 Amit 76.50
```

You may use another suitable format.

---

# Programming Requirements

Your program should use:

- `FILE`
- `fopen()`
- `fclose()`
- Appropriate file modes
- Functions
- A structure for student data
- A menu
- Error checking

You should divide the program into functions rather than putting all logic inside `main()`.

Suggested functions:

```c
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
```

You may change the function names or design if you have a better approach.

---

# Suggested Structure

You may define a structure such as:

```c
struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};
```

You are free to improve this design.

---

# Milestones

Complete the project step by step.

## Milestone 1 — Create the Student Structure

Create a structure containing:

- Roll number
- Name
- Marks

### Checkpoint

You should be able to declare and use a `Student` variable.

---

## Milestone 2 — Open the File

Create the logic required to open the student file.

Handle the situation where the file cannot be opened.

### Checkpoint

Your program should not crash when the file cannot be opened.

---

## Milestone 3 — Add Student

Implement the Add Student functionality.

Test by adding one student.

Then add at least three students.

### Checkpoint

After restarting the program, the previously saved records should still exist.

---

## Milestone 4 — Display Students

Read all records and display them in a readable table.

### Checkpoint

Verify that all saved students appear correctly.

---

## Milestone 5 — Search Student

Implement search by roll number.

Test:

- Existing roll number
- Non-existing roll number

---

## Milestone 6 — Update Student

Allow the marks of an existing student to be changed.

Test:

- Existing student
- Non-existing student

---

## Milestone 7 — Complete the Menu

Combine all functions into one menu-driven application.

The program should continue running until the user chooses Exit.

---

# Testing Requirements

Before submitting, test the following cases.

| Test | Action | Expected Result |
|---|---|---|
| 1 | Add one student | Record saved |
| 2 | Add multiple students | All records saved |
| 3 | Restart program | Previous records remain |
| 4 | Display students | All records displayed |
| 5 | Search existing roll number | Correct record displayed |
| 6 | Search invalid roll number | Not-found message |
| 7 | Update existing student | Marks updated |
| 8 | Update invalid roll number | Not-found message |
| 9 | Empty/new file | Appropriate message |
| 10 | File cannot be opened | Error handled |

---

# Sample Test Data

You can use:

```text
Roll Number: 101
Name: Rahul
Marks: 85.5
```

```text
Roll Number: 102
Name: Priya
Marks: 91.0
```

```text
Roll Number: 103
Name: Amit
Marks: 76.5
```

---

# Challenge Tasks

After completing the basic requirements, try these improvements.

## Challenge 1 — Prevent Duplicate Roll Numbers

Do not allow two students to have the same roll number.

---

## Challenge 2 — Calculate Average Marks

Add a menu option:

```text
Calculate Average
```

Display the average marks of all students.

---

## Challenge 3 — Find Highest Marks

Display the student who has the highest marks.

---

## Challenge 4 — Count Students

Display the total number of students stored in the file.

---

## Challenge 5 — Delete Student

Add:

```text
6. Delete Student
```

Allow the user to delete a student record.

---

# Coding Guidelines

Follow these practices:

1. Use meaningful variable names.
2. Keep functions small and focused.
3. Check the return value of `fopen()`.
4. Close every file that you open.
5. Avoid unnecessary global variables.
6. Add comments where the logic is not obvious.
7. Test each milestone before moving to the next.
8. Do not copy a complete solution from another student.

---

# Submission Requirements

Submit:

### 1. C Source Code

```text
student_record_manager.c
```

### 2. Sample Data

Include a sample student data file.

### 3. Test Evidence

Provide screenshots showing:

- Adding students
- Displaying students
- Searching
- Updating
- Handling an invalid roll number

### 4. Short Explanation

Write a short explanation covering:

- How the file is opened
- How records are stored
- How records are read
- How searching works
- How updating works

### 5. Reflection

Answer these questions:

1. Which file mode did you use for adding records? Why?
2. What happens if the file does not exist?
3. How did you search for a roll number?
4. Why might a temporary file be useful when updating records?
5. What was the most difficult part of the project?

---

# Completion Checklist

Before submitting, confirm:

- [ ] Student structure created
- [ ] File opening implemented
- [ ] File error handling implemented
- [ ] Add Student completed
- [ ] Display Students completed
- [ ] Search completed
- [ ] Update completed
- [ ] Menu completed
- [ ] Multiple records tested
- [ ] Program tested after restart
- [ ] Invalid input cases tested
- [ ] Code commented
- [ ] Source code submitted
- [ ] Screenshots submitted
- [ ] Reflection completed

---

# Expected Learning Outcome

After completing this project, you should be able to design a small C application that uses files as persistent storage.

You should also be comfortable moving from individual file-handling exercises such as Q114–Q118 to a larger, multi-function C program.