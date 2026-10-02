#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "expenses.txt"
#define TEMP_FILE "expenses_temp.txt"

#define CATEGORY_SIZE 30
#define DESCRIPTION_SIZE 100

struct Expense
{
    int id;
    char category[CATEGORY_SIZE];
    float amount;
    char description[DESCRIPTION_SIZE];
};

void addExpense();
void displayExpenses();
void searchByCategory();
void totalExpenses();
void highestExpense();
void deleteExpense();

int expenseIdExists(int id);
int categoryEqualsIgnoreCase(const char first[],
                             const char second[]);
void convertToLower(char text[]);
void clearInputBuffer();

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("          EXPENSE TRACKER\n");
        printf("====================================\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Search by Category\n");
        printf("4. Total Expenses\n");
        printf("5. Highest Expense\n");
        printf("6. Delete Expense\n");
        printf("7. Exit\n");
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
                addExpense();
                break;

            case 2:
                displayExpenses();
                break;

            case 3:
                searchByCategory();
                break;

            case 4:
                totalExpenses();
                break;

            case 5:
                highestExpense();
                break;

            case 6:
                deleteExpense();
                break;

            case 7:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 7);

    return 0;
}

void addExpense()
{
    struct Expense expense;
    FILE *fp;

    printf("\nEnter expense ID: ");

    if (scanf("%d", &expense.id) != 1)
    {
        printf("Invalid ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (expense.id <= 0)
    {
        printf("ID must be positive.\n");
        return;
    }

    if (expenseIdExists(expense.id))
    {
        printf("Expense ID already exists.\n");
        return;
    }

    printf("Enter category: ");

    if (fgets(expense.category,
              CATEGORY_SIZE,
              stdin) == NULL)
    {
        printf("Unable to read category.\n");
        return;
    }

    expense.category[
        strcspn(expense.category, "\n")
    ] = '\0';

    if (strlen(expense.category) == 0)
    {
        printf("Category cannot be empty.\n");
        return;
    }

    printf("Enter amount: ");

    if (scanf("%f", &expense.amount) != 1)
    {
        printf("Invalid amount.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (expense.amount <= 0)
    {
        printf("Amount must be greater than zero.\n");
        return;
    }

    printf("Enter description: ");

    if (fgets(expense.description,
              DESCRIPTION_SIZE,
              stdin) == NULL)
    {
        printf("Unable to read description.\n");
        return;
    }

    expense.description[
        strcspn(expense.description, "\n")
    ] = '\0';

    if (strlen(expense.description) == 0)
    {
        printf("Description cannot be empty.\n");
        return;
    }

    fp = fopen(FILE_NAME, "a");

    if (fp == NULL)
    {
        printf("Error: Unable to open expense file.\n");
        return;
    }

    fprintf(fp,
            "%d %s %.2f %s\n",
            expense.id,
            expense.category,
            expense.amount,
            expense.description);

    fclose(fp);

    printf("\nExpense added successfully.\n");
}

void displayExpenses()
{
    struct Expense expense;
    FILE *fp;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo expense records found.\n");
        return;
    }

    printf("\n============================================================\n");
    printf("                      EXPENSE RECORDS\n");
    printf("============================================================\n");

    printf("%-6s %-15s %-12s %-25s\n",
           "ID",
           "Category",
           "Amount",
           "Description");

    printf("------------------------------------------------------------\n");

    while (fscanf(fp,
                  "%d %29s %f %99s",
                  &expense.id,
                  expense.category,
                  &expense.amount,
                  expense.description) == 4)
    {
        printf("%-6d %-15s %-12.2f %-25s\n",
               expense.id,
               expense.category,
               expense.amount,
               expense.description);
    }

    fclose(fp);
}

void searchByCategory()
{
    struct Expense expense;
    FILE *fp;

    char searchCategory[CATEGORY_SIZE];

    int found = 0;

    printf("\nEnter category to search: ");

    if (fgets(searchCategory,
              CATEGORY_SIZE,
              stdin) == NULL)
    {
        printf("Unable to read category.\n");
        return;
    }

    searchCategory[
        strcspn(searchCategory, "\n")
    ] = '\0';

    if (strlen(searchCategory) == 0)
    {
        printf("Category cannot be empty.\n");
        return;
    }

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo expense records found.\n");
        return;
    }

    printf("\nMatching Expenses\n");
    printf("---------------------------------------------\n");

    while (fscanf(fp,
                  "%d %29s %f %99s",
                  &expense.id,
                  expense.category,
                  &expense.amount,
                  expense.description) == 4)
    {
        if (categoryEqualsIgnoreCase(
                expense.category,
                searchCategory))
        {
            printf("ID          : %d\n", expense.id);
            printf("Category    : %s\n", expense.category);
            printf("Amount      : %.2f\n", expense.amount);
            printf("Description : %s\n", expense.description);
            printf("---------------------------------------------\n");

            found = 1;
        }
    }

    fclose(fp);

    if (!found)
    {
        printf("No expenses found in this category.\n");
    }
}

void totalExpenses()
{
    struct Expense expense;
    FILE *fp;

    float total = 0.0f;
    int count = 0;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo expense records found.\n");
        return;
    }

    while (fscanf(fp,
                  "%d %29s %f %99s",
                  &expense.id,
                  expense.category,
                  &expense.amount,
                  expense.description) == 4)
    {
        total += expense.amount;
        count++;
    }

    fclose(fp);

    printf("\n====================================\n");
    printf("          EXPENSE SUMMARY\n");
    printf("====================================\n");
    printf("Number of Expenses : %d\n", count);
    printf("Total Expenses     : %.2f\n", total);
    printf("====================================\n");
}

void highestExpense()
{
    struct Expense expense;
    struct Expense highest;

    FILE *fp;

    int found = 0;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo expense records found.\n");
        return;
    }

    while (fscanf(fp,
                  "%d %29s %f %99s",
                  &expense.id,
                  expense.category,
                  &expense.amount,
                  expense.description) == 4)
    {
        if (!found || expense.amount > highest.amount)
        {
            highest = expense;
            found = 1;
        }
    }

    fclose(fp);

    if (!found)
    {
        printf("\nNo expense records available.\n");
        return;
    }

    printf("\n====================================\n");
    printf("          HIGHEST EXPENSE\n");
    printf("====================================\n");
    printf("ID          : %d\n", highest.id);
    printf("Category    : %s\n", highest.category);
    printf("Amount      : %.2f\n", highest.amount);
    printf("Description : %s\n", highest.description);
    printf("====================================\n");
}

void deleteExpense()
{
    struct Expense expense;

    FILE *fp;
    FILE *temp;

    int id;
    int found = 0;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo expense records found.\n");
        return;
    }

    temp = fopen(TEMP_FILE, "w");

    if (temp == NULL)
    {
        printf("Error: Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    printf("\nEnter expense ID to delete: ");

    if (scanf("%d", &id) != 1)
    {
        printf("Invalid ID.\n");
        clearInputBuffer();

        fclose(fp);
        fclose(temp);

        remove(TEMP_FILE);

        return;
    }

    clearInputBuffer();

    while (fscanf(fp,
                  "%d %29s %f %99s",
                  &expense.id,
                  expense.category,
                  &expense.amount,
                  expense.description) == 4)
    {
        if (expense.id == id)
        {
            found = 1;
            continue;
        }

        fprintf(temp,
                "%d %s %.2f %s\n",
                expense.id,
                expense.category,
                expense.amount,
                expense.description);
    }

    fclose(fp);
    fclose(temp);

    if (!found)
    {
        remove(TEMP_FILE);
        printf("\nExpense not found.\n");
        return;
    }

    if (remove(FILE_NAME) != 0)
    {
        printf("Error: Unable to remove original file.\n");
        remove(TEMP_FILE);
        return;
    }

    if (rename(TEMP_FILE, FILE_NAME) != 0)
    {
        printf("Error: Unable to replace expense file.\n");
        return;
    }

    printf("\nExpense deleted successfully.\n");
}

int expenseIdExists(int id)
{
    struct Expense expense;
    FILE *fp;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        return 0;
    }

    while (fscanf(fp,
                  "%d %29s %f %99s",
                  &expense.id,
                  expense.category,
                  &expense.amount,
                  expense.description) == 4)
    {
        if (expense.id == id)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}

int categoryEqualsIgnoreCase(const char first[],
                             const char second[])
{
    int i = 0;

    while (first[i] != '\0' &&
           second[i] != '\0')
    {
        if (tolower((unsigned char)first[i]) !=
            tolower((unsigned char)second[i]))
        {
            return 0;
        }

        i++;
    }

    return first[i] == '\0' &&
           second[i] == '\0';
}

void convertToLower(char text[])
{
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        text[i] =
            (char)tolower((unsigned char)text[i]);
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