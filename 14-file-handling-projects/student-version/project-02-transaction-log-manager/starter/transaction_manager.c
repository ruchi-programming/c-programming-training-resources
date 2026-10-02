#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "transactions.txt"
#define ID_SIZE 20
#define TYPE_SIZE 10

struct Transaction
{
    char transactionId[ID_SIZE];
    int accountNumber;
    char type[TYPE_SIZE];
    float amount;
};

/* Function declarations */
void addTransaction();
void displayTransactions();
void searchTransaction();
void transactionSummary();

int main()
{
    int choice;

    do
    {
        printf("\n");
        printf("========================================\n");
        printf("        TRANSACTION LOG MANAGER\n");
        printf("========================================\n");
        printf("1. Add Transaction\n");
        printf("2. Display All Transactions\n");
        printf("3. Search Transaction\n");
        printf("4. Transaction Summary\n");
        printf("5. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addTransaction();
                break;

            case 2:
                displayTransactions();
                break;

            case 3:
                searchTransaction();
                break;

            case 4:
                transactionSummary();
                break;

            case 5:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

/*
 * Add a new transaction.
 *
 * TODO:
 * 1. Create a Transaction variable.
 * 2. Accept transaction ID.
 * 3. Accept account number.
 * 4. Accept transaction type.
 * 5. Accept amount.
 * 6. Validate the amount.
 * 7. Open FILE_NAME using an appropriate file mode.
 * 8. Check whether the file opened successfully.
 * 9. Write the transaction to the file.
 * 10. Close the file.
 */
void addTransaction()
{
    /* TODO: Implement Add Transaction */
}

/*
 * Display all transaction records.
 *
 * TODO:
 * 1. Open FILE_NAME for reading.
 * 2. Check whether the file opened successfully.
 * 3. Read transactions one by one.
 * 4. Display the records in a table.
 * 5. Handle an empty/non-existing file.
 * 6. Close the file.
 */
void displayTransactions()
{
    /* TODO: Implement Display Transactions */
}

/*
 * Search for a transaction using Transaction ID.
 *
 * TODO:
 * 1. Ask the user for a Transaction ID.
 * 2. Open FILE_NAME for reading.
 * 3. Read transactions one by one.
 * 4. Compare each Transaction ID.
 * 5. Display the matching transaction.
 * 6. Display "Transaction not found" if there is no match.
 * 7. Close the file.
 */
void searchTransaction()
{
    /* TODO: Implement Search Transaction */
}

/*
 * Calculate transaction statistics.
 *
 * TODO:
 * 1. Open FILE_NAME for reading.
 * 2. Read all transactions.
 * 3. Count total transactions.
 * 4. Add CREDIT amounts.
 * 5. Add DEBIT amounts.
 * 6. Display the totals.
 * 7. Handle an empty/non-existing file.
 * 8. Close the file.
 */
void transactionSummary()
{
    /* TODO: Implement Transaction Summary */
}