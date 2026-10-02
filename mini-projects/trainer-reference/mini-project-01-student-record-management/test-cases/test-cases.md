# Student Record Management System — Test Cases

## Test Case 1 — Display Records

Start with the sample `students.txt`.

Choose:

```text
2
```

Expected: all five records are displayed.

---

## Test Case 2 — Add Student

Add:

```text
106 Riya 82.50
```

Expected:

```text
Student added successfully.
```

---

## Test Case 3 — Duplicate Roll Number

Try:

```text
101 Arjun 75
```

Expected:

```text
Roll number already exists.
```

---

## Test Case 4 — Search Existing Student

Search:

```text
103
```

Expected:

```text
Roll Number : 103
Name        : Amit
Marks       : 76.50
```

---

## Test Case 5 — Search Missing Student

Search:

```text
999
```

Expected:

```text
Student not found.
```

---

## Test Case 6 — Update Student

Update roll number:

```text
102
```

New values:

```text
PriyaNew
95
```

Expected: record 102 is changed.

---

## Test Case 7 — Delete Student

Delete:

```text
104
```

Expected: record 104 is removed.

---

## Test Case 8 — Invalid Marks

Enter:

```text
-10
```

Expected:

```text
Marks must be between 0 and 100.
```

Also test:

```text
101
```

Expected rejection because marks cannot exceed 100.

---

## Test Case 9 — Invalid Roll Number

Enter:

```text
-5
```

Expected:

```text
Roll number must be positive.
```

---

## Test Case 10 — Statistics

Using the original sample data, expected:

```text
Total Students : 5
Average Marks  : 75.80
Highest Marks  : 91.00
Lowest Marks   : 38.00
Passed         : 4
Failed         : 1
```

---

## Test Case 11 — Empty Database

Use an empty `students.txt`.

Choose statistics.

Expected:

```text
No student records available.
```

---

## Test Case 12 — Invalid Menu Input

Enter:

```text
abc
```

Expected: program displays an input error and continues.

---

## Test Case 13 — Delete Missing Student

Try deleting:

```text
999
```

Expected:

```text
Student not found.
```

---

## Test Case 14 — Update Missing Student

Try updating:

```text
999
```

Expected:

```text
Student not found.
```