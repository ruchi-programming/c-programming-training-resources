# Transaction Log Manager — Test Cases

## Initial Test Data

Use:

```text
T001 1001 CREDIT 5000.00
T002 1002 DEBIT 1200.00
T003 1001 DEBIT 750.00
T004 1003 CREDIT 2500.00
T005 1002 CREDIT 1000.00
```

Expected totals:

```text
Transactions: 5
Credit: 8500.00
Debit: 1950.00
```

---

## Test 1 — Display Existing Transactions

### Input

```text
2
```

### Expected

Five transactions should be displayed.

---

## Test 2 — Add Transaction

### Input

```text
1
T006
1004
CREDIT
3000
```

### Expected

```text
Transaction added successfully.
```

The new record should be:

```text
T006 1004 CREDIT 3000.00
```

---

## Test 3 — Confirm Append Behavior

After adding `T006`, display all transactions.

### Expected

The original five records must remain.

There should now be six records.

---

## Test 4 — Search Existing Transaction

### Input

```text
3
T003
```

### Expected

```text
Transaction Found
```

and:

```text
Transaction ID : T003
Account Number : 1001
Type           : DEBIT
Amount         : 750.00
```

---

## Test 5 — Search Missing Transaction

### Input

```text
3
T999
```

### Expected

```text
Transaction not found.
```

---

## Test 6 — Transaction Summary

With the original five records:

### Input

```text
4
```

### Expected

```text
Total Transactions : 5
Total Credit       : 8500.00
Total Debit        : 1950.00
```

---

## Test 7 — Duplicate Transaction ID

Try:

```text
1
T001
1005
DEBIT
200
```

### Expected

```text
Transaction ID already exists.
```

The new transaction must not be added.

---

## Test 8 — Invalid Account Number

Try:

```text
1
T007
-100
CREDIT
500
```

### Expected

```text
Account number must be positive.
```

---

## Test 9 — Invalid Transaction Type

Try:

```text
1
T007
1005
TRANSFER
500
```

### Expected

```text
Transaction type must be CREDIT or DEBIT.
```

---

## Test 10 — Lowercase Transaction Type

Try:

```text
1
T007
1005
credit
500
```

### Expected

The program should normalize the type and accept it as:

```text
CREDIT
```

---

## Test 11 — Invalid Amount

Try:

```text
1
T008
1005
DEBIT
-500
```

### Expected

```text
Amount must be greater than zero.
```

---

## Test 12 — Zero Amount

Try:

```text
1
T008
1005
DEBIT
0
```

### Expected

```text
Amount must be greater than zero.
```

---

## Test 13 — Empty Transaction ID

Press Enter without entering an ID.

### Expected

```text
Transaction ID cannot be empty.
```

---

## Test 14 — Missing Data File

Remove:

```text
transactions.txt
```

Then select:

```text
2
```

### Expected

```text
No transaction records found.
```

---

## Test 15 — Summary With No Data

Remove:

```text
transactions.txt
```

Then select:

```text
4
```

### Expected

```text
No transaction records found.
```

---

## Test 16 — Invalid Menu Choice

Input:

```text
99
```

### Expected

```text
Invalid choice. Please try again.
```

---

# Trainer Verification

Before marking the project complete:

- [ ] Add works.
- [ ] Append behavior is correct.
- [ ] Existing records are preserved.
- [ ] Display works.
- [ ] Search works.
- [ ] Missing transaction is handled.
- [ ] Summary works.
- [ ] Credit totals are correct.
- [ ] Debit totals are correct.
- [ ] Duplicate IDs are rejected.
- [ ] Invalid account numbers are rejected.
- [ ] Invalid types are rejected.
- [ ] Invalid amounts are rejected.
- [ ] File errors are handled.
- [ ] Files are closed correctly.
- [ ] Invalid menu choices are handled.