# Project 2 – Transaction Log Manager

## Overview

In Q116, you learned how to append transaction records to a file without overwriting existing data.

Now you will extend that concept into a small **Transaction Log Manager**.

The application will allow users to add, view, search, and summarize transaction records stored in a file.

> **Prerequisite:** Complete Q114–Q118 and Project 1 – Student Record Manager before starting this project.

---

# Learning Objectives

By completing this project, you will practice:

- File handling in C
- Append mode
- Read mode
- Structures
- Functions
- Menu-driven programming
- Searching records
- Processing numeric data
- Calculating totals
- Error handling
- Persistent data storage

---

# Problem Statement

Create a menu-driven C program that manages transaction records using a file.

Each transaction should contain:

- Transaction ID
- Account Number
- Transaction Type
- Amount

The transaction data must be stored permanently in a file.

Suggested filename:

```text
transactions.txt
```

---

# Transaction Format

A transaction can contain information such as:

```text
Transaction ID
Account Number
Transaction Type
Amount
```

Example:

```text
T001 1001 CREDIT 5000.00
T002 1002 DEBIT 1200.00
T003 1001 DEBIT 750.00
T004 1003 CREDIT 2500.00
```

You may design another suitable format.

---

# Menu Requirements

Your program should provide a menu similar to:

```text
========================================
        TRANSACTION LOG MANAGER
========================================

1. Add Transaction
2. Display All Transactions
3. Search Transaction
4. Transaction Summary
5. Exit

========================================
Enter your choice:
```

You may customize the appearance.

---

# Functional Requirements

## 1. Add Transaction

Allow the user to enter:

```text
Transaction ID
Account Number
Transaction Type
Amount
```

Example:

```text
Enter Transaction ID: T005
Enter Account Number: 1002
Enter Transaction Type: CREDIT
Enter Amount: 3500.00
```

The transaction must be added to the existing transaction file.

### Important

Adding a new transaction must **not delete existing transactions**.

You should use an appropriate file mode for this operation.

---

# 2. Display All Transactions

Read all transactions from the file and display them in a readable table.

Example:

```text
====================================================
              TRANSACTION RECORDS
====================================================

ID       Account      Type          Amount
----------------------------------------------------
T001     1001         CREDIT        5000.00
T002     1002         DEBIT         1200.00
T003     1001         DEBIT          750.00
T004     1003         CREDIT        2500.00
```

If there are no transactions, display an appropriate message.

---

# 3. Search Transaction

Allow the user to search using the **Transaction ID**.

Example:

```text
Enter Transaction ID: T003

Transaction Found

Transaction ID : T003
Account Number : 1001
Type           : DEBIT
Amount         : 750.00
```

If the transaction does not exist:

```text
Transaction not found.
```

---

# 4. Transaction Summary

Create a summary of all transactions.

The summary should display:

```text
========================================
         TRANSACTION SUMMARY
========================================

Total Transactions : 5
Total Credit       : 8500.00
Total Debit        : 1950.00
```

You should calculate these values by reading the transaction file.

Do not simply store the totals as fixed values.

---

# 5. Exit

The program should terminate when the user selects Exit.

---

# File Requirements

Use a file to permanently store transaction records.

Suggested filename:

```text
transactions.txt
```

Each transaction should occupy one record.

Example:

```text
T001 1001 CREDIT 5000.00
T002 1002 DEBIT 1200.00
T003 1001 DEBIT 750.00
```

---

# Programming Requirements

Your program should use:

- `FILE`
- `fopen()`
- `fclose()`
- Appropriate file modes
- Structures
- Functions
- Loops
- Conditional statements
- A menu-driven interface
- Error checking

Suggested structure:

```c
struct Transaction
{
    char transactionId[20];
    int accountNumber;
    char type[10];
    float amount;
};
```

You may modify the structure if you have a better design.

---

# Suggested Functions

You may divide your program into functions such as:

```c
void addTransaction();
void displayTransactions();
void searchTransaction();
void transactionSummary();
```

You are free to use different function names.

You may also create helper functions.

---

# Milestones

Complete the project one milestone at a time.

---

## Milestone 1 — Create the Transaction Structure

Create a structure containing:

- Transaction ID
- Account Number
- Transaction Type
- Amount

### Checkpoint

Create a sample `Transaction` variable and verify that you can store data in it.

---

# Milestone 2 — Create/Open the Transaction File

Implement the logic required to open the transaction file.

You should:

- Select the appropriate file mode.
- Check whether `fopen()` was successful.
- Close the file correctly.

### Checkpoint

Your program should handle a file-opening failure without crashing.

---

# Milestone 3 — Add Transaction

Implement:

```text
Add Transaction
```

The new transaction should be appended to the existing records.

### Test

Add:

```text
T001 1001 CREDIT 5000
```

Then add:

```text
T002 1002 DEBIT 1200
```

Verify that both records remain in the file.

### Important Question

What happens if you use `"w"` instead of `"a"`?

Find out by testing it.

---

# Milestone 4 — Display Transactions

Implement:

```text
Display All Transactions
```

Read every transaction from the file and display it.

### Checkpoint

Add at least five transactions and confirm that all five are displayed.

---

# Milestone 5 — Search Transaction

Implement transaction search using the Transaction ID.

Test:

### Existing ID

```text
T003
```

Expected:

```text
Transaction Found
```

### Invalid ID

```text
T999
```

Expected:

```text
Transaction not found.
```

---

# Milestone 6 — Transaction Summary

Read all transaction records and calculate:

```text
Total Transactions
Total Credit
Total Debit
```

For example:

```text
Total Transactions : 5
Total Credit       : 8500.00
Total Debit        : 1950.00
```

### Checkpoint

Manually calculate the expected totals and compare them with your program output.

---

# Milestone 7 — Complete the Menu

Combine all functionality into one menu-driven program.

The application should continue running until the user selects:

```text
5. Exit
```

---

# Data Validation

Your program should try to handle invalid data appropriately.

Consider:

- Negative transaction amounts
- Invalid transaction type
- Empty Transaction ID
- Duplicate Transaction ID
- Invalid menu choice

At minimum, prevent negative transaction amounts.

Example:

```text
Enter Amount: -500

Invalid amount.
Amount must be greater than zero.
```

---

# Testing Requirements

Test at least the following:

| Test | Action | Expected Result |
|---|---|---|
| 1 | Add one transaction | Record saved |
| 2 | Add multiple transactions | All records preserved |
| 3 | Restart program | Previous records remain |
| 4 | Display transactions | All records displayed |
| 5 | Search existing ID | Correct transaction displayed |
| 6 | Search invalid ID | Not-found message |
| 7 | Calculate summary | Correct totals |
| 8 | Enter negative amount | Invalid amount handled |
| 9 | Invalid menu choice | Error message |
| 10 | Empty/new file | Appropriate message |

---

# Sample Test Data

You can use the following transactions:

```text
T001 1001 CREDIT 5000.00
T002 1002 DEBIT 1200.00
T003 1001 DEBIT 750.00
T004 1003 CREDIT 2500.00
T005 1002 CREDIT 1000.00
```

Expected totals:

```text
Total Transactions : 5
Total Credit       : 8500.00
Total Debit        : 1950.00
```

Verify these values independently.

---

# Challenge Tasks

Once the basic project is complete, try the following improvements.

---

## Challenge 1 — Search by Account Number

Add an option:

```text
Search by Account Number
```

Example:

```text
Enter Account Number: 1001
```

Display all transactions belonging to that account.

---

# Challenge 2 — Account Balance

Calculate the balance for a selected account.

For example:

```text
Credits = 5000 + 1000
Debits  = 1200

Balance = 4800
```

The calculation should be based on the records stored in the file.

---

# Challenge 3 — Highest Transaction

Find and display the transaction with the highest amount.

Example:

```text
Highest Transaction

ID     : T001
Amount : 5000.00
```

---

# Challenge 4 — Transaction Count by Type

Display:

```text
Credit Transactions : 3
Debit Transactions  : 2
```

---

# Challenge 5 — Date

Add a transaction date:

```text
Transaction ID
Account Number
Transaction Type
Amount
Date
```

Example:

```text
T006 1004 CREDIT 2500.00 2026-10-02
```

---

# Challenge 6 — Delete Transaction

Add:

```text
6. Delete Transaction
```

Allow the user to remove a transaction based on its Transaction ID.

Think about how a temporary file can help you perform this operation safely.

---

# Challenge 7 — Export Summary

Create a separate file:

```text
transaction_summary.txt
```

and save the calculated summary into it.

---

# Coding Guidelines

Follow these practices:

1. Use meaningful variable names.
2. Use a structure for transaction records.
3. Use functions to separate responsibilities.
4. Check whether files open successfully.
5. Close every file after use.
6. Do not overwrite existing transaction records when adding.
7. Avoid unnecessary global variables.
8. Add comments for important logic.
9. Test every milestone independently.
10. Keep the code readable.

---

# Important Concepts to Understand

Before submitting, make sure you understand the difference between:

```text
"r"
```

```text
"w"
```

```text
"a"
```

Think about:

- Which mode reads existing records?
- Which mode overwrites a file?
- Which mode adds data to the end?
- What happens if the file does not already exist?

You should be able to explain these choices during a review.

---

# Submission Requirements

Submit the following:

## 1. Source Code

```text
transaction_manager.c
```

## 2. Transaction Data

```text
transactions.txt
```

with sample records.

## 3. Test Evidence

Provide screenshots showing:

- Adding transactions
- Displaying transactions
- Searching
- Transaction summary
- Invalid transaction amount
- Invalid Transaction ID

## 4. Algorithm

Submit a short description of your approach.

Explain:

- How transactions are stored
- How transactions are appended
- How records are read
- How searching works
- How totals are calculated

## 5. Reflection

Answer:

1. Why should `"a"` mode be used when adding transactions?
2. What is the difference between `"w"` and `"a"`?
3. How did you search for a Transaction ID?
4. How did you calculate credit and debit totals?
5. How would you prevent duplicate Transaction IDs?
6. Why might a temporary file be needed for deletion?

---

# Completion Checklist

Before submitting, confirm:

- [ ] Transaction structure created
- [ ] File opening implemented
- [ ] File error handling implemented
- [ ] Add Transaction completed
- [ ] Append behavior tested
- [ ] Display Transactions completed
- [ ] Search completed
- [ ] Transaction Summary completed
- [ ] Menu completed
- [ ] Negative amount handled
- [ ] Multiple transactions tested
- [ ] Program tested after restart
- [ ] Invalid Transaction ID tested
- [ ] Code commented
- [ ] Source code submitted
- [ ] Sample data submitted
- [ ] Screenshots submitted
- [ ] Algorithm submitted
- [ ] Reflection completed

---

# Expected Learning Outcome

After completing this project, you should be able to build a small C application that uses a file as persistent storage for transaction records.

You should understand how to:

- Append records without overwriting existing data
- Read and process stored records
- Search file-based records
- Calculate reports from file data
- Organize a larger C program using functions
- Handle common file-related errors