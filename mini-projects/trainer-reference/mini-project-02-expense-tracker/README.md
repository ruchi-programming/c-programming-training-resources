# Mini Project 02 — Expense Tracker

## Trainer Reference

> **TRAINER ONLY — DO NOT DISTRIBUTE THIS FOLDER AS THE STUDENT SOLUTION.**

---

# 1. Project Overview

The Expense Tracker is a menu-driven C application that stores and analyzes personal expense records.

The project reinforces:

- Structures
- File handling
- Functions
- Searching
- Filtering
- Calculations
- Input validation
- Persistent data

---

# 2. Expense Record

Each expense contains:

```c
struct Expense
{
    int id;
    char category[30];
    float amount;
    char description[100];
};
```

---

# 3. Required Menu

```text
1. Add Expense
2. Display Expenses
3. Search by Category
4. Total Expenses
5. Highest Expense
6. Delete Expense
7. Exit
```

---

# 4. File Format

Records are stored in:

```text
expenses.txt
```

Format:

```text
ID CATEGORY AMOUNT DESCRIPTION
```

Example:

```text
1 Food 250.00 Lunch
2 Transport 120.00 Metro
3 Food 450.00 Dinner
4 Bills 1500.00 Electricity
```

The reference implementation uses a simple space-separated format.

Because descriptions cannot contain spaces in this format, the implementation treats the description as a single word.

This is intentional for the beginner-level version.

A CSV or delimiter-based format can be introduced as an extension.

---

# 5. Learning Objectives

Students should be able to:

- Define an expense structure
- Append records to a file
- Display stored records
- Search by category
- Calculate totals
- Find the highest expense
- Delete records
- Validate amounts
- Work with persistent data

---

# 6. Add Expense Algorithm

```text
START
 |
Read ID
 |
Check duplicate ID
 |
Read category
 |
Read amount
 |
Validate amount
 |
Read description
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

# 7. Display Algorithm

```text
START
 |
Open expenses.txt
 |
Read one record
 |
Display record
 |
Read next record
 |
Repeat until EOF
 |
Close file
 |
END
```

---

# 8. Search by Category

```text
START
 |
Read category
 |
Open file
 |
Read expense
 |
Compare category
 |
If matched -> display
 |
Continue
 |
Close file
 |
END
```

The reference implementation performs a case-insensitive category comparison by converting both values to lowercase.

---

# 9. Total Expense Algorithm

```text
total = 0

Read each expense
    |
    v
total = total + amount

After EOF:
display total
```

---

# 10. Highest Expense

Maintain:

```text
highest
```

For each record:

```text
if amount > highest
    highest = amount
```

Also retain the complete record so the highest-expense details can be displayed.

---

# 11. Delete Expense

Deletion uses a temporary file.

```text
expenses.txt
     |
     v
Read record
     |
     +---- matching ID?
     |          |
     |         YES
     |          |
     |       Skip it
     |
     NO
     |
Write to temp file
     |
     v
Replace original file
```

---

# 12. Validation

### ID

Must be positive and unique.

### Category

Cannot be empty.

### Amount

Must be greater than zero.

### Description

Cannot be empty.

---

# 13. Trainer Teaching Sequence

### Stage 1

Create the structure.

### Stage 2

Write one expense to the file.

### Stage 3

Display all expenses.

### Stage 4

Add category searching.

### Stage 5

Calculate totals.

### Stage 6

Find maximum expense.

### Stage 7

Implement deletion using a temporary file.

---

# 14. Common Mistakes

Students may:

- Forget duplicate-ID checking
- Use `"w"` instead of `"a"` when adding
- Forget to close files
- Use incorrect `fscanf()` format strings
- Forget to initialize totals
- Divide incorrectly when calculating averages
- Delete the wrong record
- Forget to remove the temporary file after an error
- Perform case-sensitive category matching unexpectedly

---

# 15. Extension Ideas

Advanced students can add:

- Date
- Payment method
- Monthly summaries
- Category totals
- Budget limits
- Remaining budget
- Date-range search
- CSV export
- Sorting
- Expense charts
- Recurring expenses
- Multiple user accounts

---

# 16. Assessment

| Area | Marks |
|---|---:|
| Structure | 10 |
| Add Expense | 15 |
| Display | 10 |
| Search | 10 |
| Total calculation | 10 |
| Highest expense | 10 |
| Delete | 15 |
| Validation | 10 |
| File handling | 5 |
| Code quality | 5 |
| **Total** | **100** |