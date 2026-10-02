# Student Record Manager — Test Cases

## Test Environment

Compiler:

```text
GCC
```

Operating system:

```text
Windows
```

Expected source file:

```text
students.txt
```

---

# Test Case 1 — Add First Student

### Input

```text
1
101
Rahul
85.50
```

### Expected Result

```text
Student added successfully.
```

Expected file:

```text
101 Rahul 85.50
```

---

# Test Case 2 — Add Multiple Students

Add:

```text
102
Priya
91.00
```

and:

```text
103
Amit
76.50
```

Expected file:

```text
101 Rahul 85.50
102 Priya 91.00
103 Amit 76.50
```

---

# Test Case 3 — Display Students

### Input

```text
2
```

### Expected Result

The program should display all three records.

Example:

```text
Roll No    Name                 Marks
----------------------------------------
101        Rahul                85.50
102        Priya                91.00
103        Amit                 76.50
```

---

# Test Case 4 — Search Existing Student

### Input

```text
3
102
```

### Expected Result

```text
Student Found

Roll Number : 102
Name        : Priya
Marks       : 91.00
```

---

# Test Case 5 — Search Missing Student

### Input

```text
3
999
```

### Expected Result

```text
Student not found.
```

---

# Test Case 6 — Update Existing Student

### Input

```text
4
103
Amit Kumar
82.00
```

### Expected Result

```text
Student updated successfully.
```

Expected file:

```text
101 Rahul 85.50
102 Priya 91.00
103 Amit 82.00
```

---

# Test Case 7 — Verify Update

Run display again.

### Expected Result

```text
101 Rahul 85.50
102 Priya 91.00
103 Amit 82.00
```

The old marks:

```text
76.50
```

should no longer be present for roll number `103`.

---

# Test Case 8 — Duplicate Roll Number

Try:

```text
1
101
Another
90
```

### Expected Result

```text
A student with this roll number already exists.
```

The original record should remain unchanged.

---

# Test Case 9 — Invalid Marks

Try:

```text
1
104
Test
120
```

### Expected Result

```text
Marks must be between 0 and 100.
```

No invalid record should be added.

---

# Test Case 10 — Negative Marks

Try:

```text
1
104
Test
-10
```

### Expected Result

```text
Marks must be between 0 and 100.
```

---

# Test Case 11 — Invalid Roll Number

Try:

```text
1
-5
```

### Expected Result

```text
Roll number must be positive.
```

---

# Test Case 12 — Search Without Data File

Delete:

```text
students.txt
```

Then select:

```text
3
101
```

### Expected Result

```text
No student records found.
```

---

# Test Case 13 — Display Without Data File

Delete:

```text
students.txt
```

Then select:

```text
2
```

### Expected Result

```text
No student records found.
```

---

# Test Case 14 — Update Missing Student

Create records and search for:

```text
999
```

using update.

### Expected Result

```text
Student not found.
```

The original file must remain unchanged.

---

# Test Case 15 — Invalid Menu Choice

Input:

```text
99
```

### Expected Result

```text
Invalid choice. Please try again.
```

---

# Test Case 16 — Verify Append Behavior

Start with:

```text
101 Rahul 85.50
```

Add:

```text
102 Priya 91.00
```

### Expected Result

Both records must remain.

This confirms that append mode is being used.

---

# Trainer Verification Checklist

Before marking the project complete:

- [ ] Records are stored in a file.
- [ ] Add uses append behavior.
- [ ] Display reads all records.
- [ ] Search works for existing records.
- [ ] Search handles missing records.
- [ ] Update works.
- [ ] Temporary file is used during update.
- [ ] Duplicate roll numbers are prevented.
- [ ] Marks are validated.
- [ ] Roll numbers are validated.
- [ ] File-opening errors are handled.
- [ ] Files are closed.
- [ ] Temporary files are cleaned up.
- [ ] Invalid menu choices are handled.

---

# Expected Final Data

After successful completion of the main tests:

```text
101 Rahul 85.50
102 Priya 91.00
103 Amit 82.00
```