# Expense Tracker — Test Cases

## Test Case 1 — Display Expenses

Choose:

```text
2
```

Expected: all seven sample expenses are displayed.

---

## Test Case 2 — Add Expense

Enter:

```text
8
Health
300
Medicine
```

Expected:

```text
Expense added successfully.
```

---

## Test Case 3 — Duplicate ID

Try:

```text
1
Food
500
Snack
```

Expected:

```text
Expense ID already exists.
```

---

## Test Case 4 — Search Food

Search:

```text
Food
```

Expected matching records:

```text
1 Food 250.00 Lunch
3 Food 450.00 Dinner
7 Food 180.00 Breakfast
```

---

## Test Case 5 — Case-Insensitive Search

Search:

```text
food
```

Expected: same Food records are displayed.

---

## Test Case 6 — Missing Category

Search:

```text
Travel
```

Expected:

```text
No expenses found in this category.
```

---

## Test Case 7 — Total Expenses

Using the original sample:

```text
Number of Expenses : 7
Total Expenses     : 3550.00
```

---

## Test Case 8 — Highest Expense

Expected:

```text
ID          : 4
Category    : Bills
Amount      : 1500.00
Description : Electricity
```

---

## Test Case 9 — Delete Expense

Delete:

```text
4
```

Expected:

```text
Expense deleted successfully.
```

The Bills record should no longer appear.

---

## Test Case 10 — Delete Missing Expense

Delete:

```text
999
```

Expected:

```text
Expense not found.
```

---

## Test Case 11 — Invalid Amount

Try:

```text
9
Food
-100
```

Expected:

```text
Amount must be greater than zero.
```

---

## Test Case 12 — Invalid ID

Try:

```text
-5
```

Expected:

```text
ID must be positive.
```

---

## Test Case 13 — Empty Category

Enter an empty category.

Expected:

```text
Category cannot be empty.
```

---

## Test Case 14 — Empty Description

Enter an empty description.

Expected:

```text
Description cannot be empty.
```

---

## Test Case 15 — Empty Database

Use an empty `expenses.txt`.

Choose total expenses.

Expected:

```text
Number of Expenses : 0
Total Expenses     : 0.00
```

---

## Test Case 16 — Invalid Menu Input

Enter:

```text
abc
```

Expected: input error and program continues.

---

# Trainer Verification Checklist

- [ ] Structure is correct
- [ ] Add works
- [ ] Duplicate IDs are rejected
- [ ] Display works
- [ ] Category search works
- [ ] Search is case-insensitive
- [ ] Total is correct
- [ ] Highest expense is correct
- [ ] Delete works
- [ ] Missing records are handled
- [ ] Invalid amounts are rejected
- [ ] Files are closed
- [ ] Temporary file is handled safely
- [ ] Program compiles without warnings