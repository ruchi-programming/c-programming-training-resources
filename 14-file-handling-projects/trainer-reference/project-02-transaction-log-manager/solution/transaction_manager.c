#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void addTransaction();
void displayTransactions();
void searchTransaction();
void transactionSummary();

int transactionIdExists(const char id[]);
void convertToUpper(char text[]);
void clearInputBuffer();

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       TRANSACTION LOG MANAGER\n");
        printf("====================================\n");
        printf("1. Add Transaction\n");
        printf("2. Display All Transactions\n");
        printf("3. Search Transaction\n");
        printf("4. Transaction Summary\n");
        printf("5. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

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

void addTransaction()
{
    struct Transaction transaction;
    FILE *fp;

    printf("\nEnter transaction ID: ");

    if (fgets(transaction.transactionId,
              ID_SIZE,
              stdin) == NULL)
    {
        printf("Unable to read transaction ID.\n");
        return;
    }

    transaction.transactionId[
        strcspn(transaction.transactionId, "\n")
    ] = '\0';

    if (strlen(transaction.transactionId) == 0)
    {
        printf("Transaction ID cannot be empty.\n");
        return;
    }

    if (transactionIdExists(transaction.transactionId))
    {
        printf("Transaction ID already exists.\n");
        return;
    }

    printf("Enter account number: ");

    if (scanf("%d", &transaction.accountNumber) != 1)
    {
        printf("Invalid account number.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (transaction.accountNumber <= 0)
    {
        printf("Account number must be positive.\n");
        return;
    }

    printf("Enter type (CREDIT/DEBIT): ");

    if (fgets(transaction.type, TYPE_SIZE, stdin) == NULL)
    {
        printf("Unable to read transaction type.\n");
        return;
    }

    transaction.type[
        strcspn(transaction.type, "\n")
    ] = '\0';

    convertToUpper(transaction.type);

    if (strcmp(transaction.type, "CREDIT") != 0 &&
        strcmp(transaction.type, "DEBIT") != 0)
    {
        printf("Transaction type must be CREDIT or DEBIT.\n");
        return;
    }

    printf("Enter amount: ");

    if (scanf("%f", &transaction.amount) != 1)
    {
        printf("Invalid amount.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (transaction.amount <= 0)
    {
        printf("Amount must be greater than zero.\n");
        return;
    }

    fp = fopen(FILE_NAME, "a");

    if (fp == NULL)
    {
        printf("Error: Unable to open transaction file.\n");
        return;
    }

    fprintf(fp, "%s %d %s %.2f\n",
            transaction.transactionId,
            transaction.accountNumber,
            transaction.type,
            transaction.amount);

    fclose(fp);

    printf("\nTransaction added successfully.\n");
}

void displayTransactions()
{
    struct Transaction transaction;
    FILE *fp;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo transaction records found.\n");
        return;
    }

    printf("\n====================================================\n");
    printf("                  TRANSACTIONS\n");
    printf("====================================================\n");

    printf("%-12s %-12s %-10s %-12s\n",
           "ID",
           "Account",
           "Type",
           "Amount");

    printf("----------------------------------------------------\n");

    while (fscanf(fp,
                  "%19s %d %9s %f",
                  transaction.transactionId,
                  &transaction.accountNumber,
                  transaction.type,
                  &transaction.amount) == 4)
    {
        printf("%-12s %-12d %-10s %-12.2f\n",
               transaction.transactionId,
               transaction.accountNumber,
               transaction.type,
               transaction.amount);
    }

    fclose(fp);
}

void searchTransaction()
{
    struct Transaction transaction;
    FILE *fp;

    char searchId[ID_SIZE];
    int found = 0;

    printf("\nEnter transaction ID to search: ");

    if (fgets(searchId, ID_SIZE, stdin) == NULL)
    {
        printf("Unable to read transaction ID.\n");
        return;
    }

    searchId[strcspn(searchId, "\n")] = '\0';

    if (strlen(searchId) == 0)
    {
        printf("Transaction ID cannot be empty.\n");
        return;
    }

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo transaction records found.\n");
        return;
    }

    while (fscanf(fp,
                  "%19s %d %9s %f",
                  transaction.transactionId,
                  &transaction.accountNumber,
                  transaction.type,
                  &transaction.amount) == 4)
    {
        if (strcmp(transaction.transactionId, searchId) == 0)
        {
            printf("\nTransaction Found\n");
            printf("-----------------------------\n");
            printf("Transaction ID : %s\n",
                   transaction.transactionId);
            printf("Account Number : %d\n",
                   transaction.accountNumber);
            printf("Type           : %s\n",
                   transaction.type);
            printf("Amount         : %.2f\n",
                   transaction.amount);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
    {
        printf("\nTransaction not found.\n");
    }
}

void transactionSummary()
{
    struct Transaction transaction;
    FILE *fp;

    int count = 0;
    float totalCredit = 0.0f;
    float totalDebit = 0.0f;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo transaction records found.\n");
        return;
    }

    while (fscanf(fp,
                  "%19s %d %9s %f",
                  transaction.transactionId,
                  &transaction.accountNumber,
                  transaction.type,
                  &transaction.amount) == 4)
    {
        count++;

        if (strcmp(transaction.type, "CREDIT") == 0)
        {
            totalCredit += transaction.amount;
        }
        else if (strcmp(transaction.type, "DEBIT") == 0)
        {
            totalDebit += transaction.amount;
        }
    }

    fclose(fp);

    printf("\n====================================\n");
    printf("        TRANSACTION SUMMARY\n");
    printf("====================================\n");
    printf("Total Transactions : %d\n", count);
    printf("Total Credit       : %.2f\n", totalCredit);
    printf("Total Debit        : %.2f\n", totalDebit);
    printf("====================================\n");
}

int transactionIdExists(const char id[])
{
    struct Transaction transaction;
    FILE *fp;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        return 0;
    }

    while (fscanf(fp,
                  "%19s %d %9s %f",
                  transaction.transactionId,
                  &transaction.accountNumber,
                  transaction.type,
                  &transaction.amount) == 4)
    {
        if (strcmp(transaction.transactionId, id) == 0)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}

void convertToUpper(char text[])
{
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        text[i] = (char)toupper((unsigned char)text[i]);
    }
}

void clearInputBuffer()
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        /* discard remaining input */
    }
}