# Project 2 — Transaction Log Manager

## Trainer Reference

> **Trainer-only material**
>
> This folder contains the complete reference solution, algorithms, test cases, expected results, common mistakes, and teaching notes.
>
> Do not distribute this folder with the student-version materials.

---

# 1. Project Overview

This project extends **Q116 — Append Transaction Records**.

Students build a menu-driven transaction management application using C structures and text-file handling.

Each transaction contains:

- Transaction ID
- Account Number
- Transaction Type
- Amount

The application supports:

1. Add Transaction
2. Display All Transactions
3. Search Transaction
4. Transaction Summary
5. Exit

---

# 2. Learning Objectives

Students should learn to:

- Store structured records in a text file.
- Append records without overwriting existing data.
- Read structured data from a file.
- Search records sequentially.
- Calculate totals while reading records.
- Validate transaction data.
- Use functions to organize a program.
- Handle file-opening errors.
- Understand the difference between `"a"` and `"w"`.

---

# 3. Data Structure

The reference solution uses:

```c
struct Transaction
{
    char transactionId[20];
    int accountNumber;
    char type[10];
    float amount;
};
```

The file format is:

```text
TransactionID AccountNumber Type Amount
```

Example:

```text
T001 1001 CREDIT 5000.00
T002 1002 DEBIT 1200.00
T003 1001 DEBIT 750.00
```

---

# 4. File Used

The application stores records in:

```text
transactions.txt
```

Each transaction occupies one line.

Example:

```text
T001 1001 CREDIT 5000.00
T002 1002 DEBIT 1200.00
T003 1001 DEBIT 750.00
T004 1003 CREDIT 2500.00
T005 1002 CREDIT 1000.00
```

---

# 5. File Modes

| Operation | Mode | Purpose |
|---|---|---|
| Add transaction | `"a"` | Add without deleting existing data |
| Display | `"r"` | Read records |
| Search | `"r"` | Read records |
| Summary | `"r"` | Read and calculate totals |

## Important Teaching Point

Adding records must use append mode:

```c
fopen(FILE_NAME, "a");
```

Using:

```c
fopen(FILE_NAME, "w");
```

would overwrite the existing transaction log.

---

# 6. Algorithm — Add Transaction

```text
START

Ask for transaction ID.
Validate transaction ID.

Check whether transaction ID already exists.

Ask for account number.
Validate account number.

Ask for transaction type.
Validate CREDIT or DEBIT.

Ask for amount.
Validate amount.

Open transactions.txt using append mode.

If file cannot be opened:
    Display error.
    Return.

Write transaction to file.

Close file.

Display success message.

END
```

---

# 7. Algorithm — Display Transactions

```text
START

Open transactions.txt using read mode.

If file cannot be opened:
    Display "No transactions found."
    Return.

Display table heading.

Read first transaction.

WHILE a complete transaction is read:

    Display transaction.

    Read next transaction.

Close file.

END
```

---

# 8. Algorithm — Search Transaction

```text
START

Ask for transaction ID.

Open transactions.txt for reading.

If file cannot be opened:
    Display error.
    Return.

Set found = 0.

Read each transaction.

IF transaction ID matches:

    Display transaction.
    Set found = 1.
    Stop searching.

Close file.

IF found == 0:

    Display "Transaction not found."

END
```

---

# 9. Algorithm — Transaction Summary

The summary calculates:

- Total number of transactions
- Total credit amount
- Total debit amount

Algorithm:

```text
START

Open transactions.txt for reading.

Set:
    count = 0
    totalCredit = 0
    totalDebit = 0

Read each transaction.

For every transaction:

    count++

    IF type is CREDIT:
        totalCredit += amount

    ELSE IF type is DEBIT:
        totalDebit += amount

Close file.

Display:
    Total transactions
    Total credit
    Total debit

END
```

---

# 10. Duplicate Transaction IDs

The reference solution prevents duplicate transaction IDs.

Before adding a transaction, the program searches the existing file.

Example:

```text
T001 1001 CREDIT 5000.00
```

If the user attempts to add another:

```text
T001 1005 DEBIT 200.00
```

the program rejects it.

This provides an opportunity to explain the idea of a unique identifier.

---

# 11. Transaction Validation

The reference implementation validates:

### Transaction ID

- Cannot be empty.
- Must not already exist.

### Account Number

- Must be positive.

### Transaction Type

Must be:

```text
CREDIT
```

or:

```text
DEBIT
```

### Amount

Must be greater than zero.

---

# 12. Complete Reference Solution

The complete implementation is stored in:

```text
solution/transaction_manager.c
```

The implementation demonstrates:

- Structures
- File append
- File reading
- Searching
- Summary calculations
- Validation
- Functions
- Error handling
- Menu-driven programming

---

# 13. Trainer Teaching Notes

## Stage 1 — Review Q116

Before starting, ask students to explain:

```c
fopen("transactions.txt", "a");
```

Ask:

> Why is `"a"` used instead of `"w"`?

Expected concept:

> Append mode preserves existing records and writes new data at the end.

---

## Stage 2 — Structure

Ask students to design:

```c
struct Transaction
```

before showing the reference implementation.

Discuss why a structure is preferable to maintaining separate arrays for:

- IDs
- Account numbers
- Types
- Amounts

---

## Stage 3 — File Storage

Show how one structure becomes one line in the text file.

For example:

```text
T001 1001 CREDIT 5000.00
```

Explain the relationship between:

```c
fprintf()
```

and:

```c
fscanf()
```

---

## Stage 4 — Searching

The search implementation demonstrates sequential search.

Explain:

```text
File
 ↓
Record 1 → compare
Record 2 → compare
Record 3 → compare
...
```

Stop when the transaction is found.

---

## Stage 5 — Summary

The summary feature is useful for teaching accumulation.

Example:

```c
totalCredit += transaction.amount;
```

Students should understand that the total is maintained while records are being read.

---

# 14. Common Student Mistakes

## Mistake 1 — Using `"w"` for Adding

Incorrect:

```c
fp = fopen(FILE_NAME, "w");
```

This can erase previous transactions.

Correct concept:

```c
fp = fopen(FILE_NAME, "a");
```

---

## Mistake 2 — Not Checking `fopen()`

Always check:

```c
if (fp == NULL)
```

before using the file pointer.

---

## Mistake 3 — Incorrect `fscanf()` Loop

A robust loop checks the number of successfully read fields:

```c
while (fscanf(fp, "%19s %d %9s %f",
              transaction.transactionId,
              &transaction.accountNumber,
              transaction.type,
              &transaction.amount) == 4)
{
    /* process transaction */
}
```

---

## Mistake 4 — Case-Sensitive Transaction Type

Students may enter:

```text
credit
```

instead of:

```text
CREDIT
```

The reference solution normalizes the input to uppercase.

---

## Mistake 5 — Negative Amount

A transaction amount should not be negative in this exercise.

Reject:

```text
-500
```

---

## Mistake 6 — Duplicate Transaction ID

A transaction ID should uniquely identify a transaction.

The reference solution checks for duplicates before appending.

---

# 15. Expected Sample Data

Use:

```text
T001 1001 CREDIT 5000.00
T002 1002 DEBIT 1200.00
T003 1001 DEBIT 750.00
T004 1003 CREDIT 2500.00
T005 1002 CREDIT 1000.00
```

Expected summary:

```text
Total Transactions : 5
Total Credit       : 8500.00
Total Debit        : 1950.00
```

---

# 16. Expected Program Flow

Example menu:

```text
====================================
       TRANSACTION LOG MANAGER
====================================
1. Add Transaction
2. Display All Transactions
3. Search Transaction
4. Transaction Summary
5. Exit
====================================
Enter your choice:
```

Example add operation:

```text
Enter transaction ID: T006
Enter account number: 1004
Enter type (CREDIT/DEBIT): CREDIT
Enter amount: 3000

Transaction added successfully.
```

---

# 17. Extensions

Once the basic project is complete, students can implement:

### Extension 1 — Search by Account

Display all transactions for a particular account.

### Extension 2 — Account Balance

Calculate:

```text
Credit - Debit
```

for an account.

### Extension 3 — Highest Transaction

Find the transaction with the largest amount.

### Extension 4 — Count by Type

Display:

```text
Number of Credits:
Number of Debits:
```

### Extension 5 — Date

Add a transaction date.

Example:

```text
T006 1004 CREDIT 3000.00 2026-10-02
```

### Extension 6 — Delete Transaction

Use a temporary file, similar to the Student Record Manager update operation.

### Extension 7 — Account Statement

Generate a statement for one account.

---

# 18. Discussion Questions

Ask students:

1. Why is transaction ID useful?
2. Why should transaction IDs be unique?
3. What is the difference between append and write mode?
4. How does sequential search work?
5. How are totals calculated?
6. What happens if the file does not exist?
7. What happens when `fscanf()` cannot read a complete record?
8. How could this program support dates?
9. How could transactions be deleted?
10. How could account balances be calculated?

---

# 19. Trainer Assessment

Suggested areas:

| Area | Weight |
|---|---:|
| Structure design | 15% |
| File handling | 25% |
| Add/display/search | 25% |
| Summary calculations | 15% |
| Validation | 10% |
| Program structure | 10% |

These are suggested trainer weights and can be adjusted.

---

# 20. Trainer Checklist

- [ ] Student understands append mode.
- [ ] Student can define a transaction structure.
- [ ] Student can write records to a file.
- [ ] Student can read records.
- [ ] Student can search records.
- [ ] Student can calculate totals.
- [ ] Student validates transaction data.
- [ ] Student checks `fopen()`.
- [ ] Student closes files.
- [ ] Student understands unique IDs.
- [ ] Student can explain the complete program.

---

# 21. Reference Folder

```text
project-02-transaction-log-manager/
├── README.md
├── solution/
│   └── transaction_manager.c
└── test-cases/
    └── test-cases.md
```

Keep this folder separate from:

```text
student-version/project-02-transaction-log-manager/
```

Students should receive the student version only.