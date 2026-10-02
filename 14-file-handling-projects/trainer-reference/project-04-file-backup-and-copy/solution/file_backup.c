#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_SIZE 100

char sourceFile[FILE_NAME_SIZE] = "";
char backupFile[FILE_NAME_SIZE] = "";

void setSourceFile();
void displaySourceFile();
void copyFile();
void verifyBackup();

void clearInputBuffer();

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       FILE BACKUP & COPY UTILITY\n");
        printf("====================================\n");
        printf("1. Enter Source File\n");
        printf("2. Display Source File\n");
        printf("3. Copy / Backup File\n");
        printf("4. Verify Backup\n");
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
                setSourceFile();
                break;

            case 2:
                displaySourceFile();
                break;

            case 3:
                copyFile();
                break;

            case 4:
                verifyBackup();
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

void setSourceFile()
{
    FILE *fp;

    printf("\nEnter source file: ");

    if (fgets(sourceFile, FILE_NAME_SIZE, stdin) == NULL)
    {
        printf("Unable to read source filename.\n");
        sourceFile[0] = '\0';
        return;
    }

    sourceFile[strcspn(sourceFile, "\n")] = '\0';

    if (strlen(sourceFile) == 0)
    {
        printf("Source filename cannot be empty.\n");
        sourceFile[0] = '\0';
        return;
    }

    fp = fopen(sourceFile, "rb");

    if (fp == NULL)
    {
        printf("Error: Unable to open source file.\n");
        sourceFile[0] = '\0';
        return;
    }

    fclose(fp);

    /*
       A new source selection invalidates the previous
       backup because it belongs to the old source.
    */
    backupFile[0] = '\0';

    printf("Source file selected successfully.\n");
}

void displaySourceFile()
{
    FILE *fp;
    int ch;

    if (strlen(sourceFile) == 0)
    {
        printf("\nPlease select a source file first.\n");
        return;
    }

    fp = fopen(sourceFile, "rb");

    if (fp == NULL)
    {
        printf("\nError: Unable to open source file.\n");
        return;
    }

    printf("\n----- SOURCE FILE -----\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    printf("\n-----------------------\n");

    fclose(fp);
}

void copyFile()
{
    FILE *source;
    FILE *destination;

    int ch;
    long bytesCopied = 0;

    char destinationFile[FILE_NAME_SIZE];

    if (strlen(sourceFile) == 0)
    {
        printf("\nPlease select a source file first.\n");
        return;
    }

    printf("\nEnter backup file name: ");

    if (fgets(destinationFile,
              FILE_NAME_SIZE,
              stdin) == NULL)
    {
        printf("Unable to read backup filename.\n");
        return;
    }

    destinationFile[
        strcspn(destinationFile, "\n")
    ] = '\0';

    if (strlen(destinationFile) == 0)
    {
        printf("Backup filename cannot be empty.\n");
        return;
    }

    if (strcmp(sourceFile, destinationFile) == 0)
    {
        printf("Error: Source and destination cannot be the same file.\n");
        return;
    }

    source = fopen(sourceFile, "rb");

    if (source == NULL)
    {
        printf("Error: Unable to open source file.\n");
        return;
    }

    destination = fopen(destinationFile, "wb");

    if (destination == NULL)
    {
        printf("Error: Unable to create backup file.\n");
        fclose(source);
        return;
    }

    while ((ch = fgetc(source)) != EOF)
    {
        if (fputc(ch, destination) == EOF)
        {
            printf("Error: Failed while writing backup file.\n");

            fclose(source);
            fclose(destination);

            return;
        }

        bytesCopied++;
    }

    fclose(source);
    fclose(destination);

    strcpy(backupFile, destinationFile);

    printf("\nBackup completed successfully.\n");
    printf("Source      : %s\n", sourceFile);
    printf("Destination : %s\n", backupFile);
    printf("Bytes copied: %ld\n", bytesCopied);
}

void verifyBackup()
{
    FILE *source;
    FILE *backup;

    int sourceChar;
    int backupChar;

    long position = 0;
    int identical = 1;

    if (strlen(sourceFile) == 0)
    {
        printf("\nPlease select a source file first.\n");
        return;
    }

    if (strlen(backupFile) == 0)
    {
        printf("\nNo backup file is available for verification.\n");
        printf("Please create a backup first.\n");
        return;
    }

    source = fopen(sourceFile, "rb");

    if (source == NULL)
    {
        printf("\nError: Unable to open source file.\n");
        return;
    }

    backup = fopen(backupFile, "rb");

    if (backup == NULL)
    {
        printf("\nError: Unable to open backup file.\n");
        fclose(source);
        return;
    }

    while (1)
    {
        sourceChar = fgetc(source);
        backupChar = fgetc(backup);

        if (sourceChar != backupChar)
        {
            identical = 0;
            break;
        }

        if (sourceChar == EOF && backupChar == EOF)
        {
            break;
        }

        position++;
    }

    fclose(source);
    fclose(backup);

    printf("\n----- BACKUP VERIFICATION -----\n");

    if (identical)
    {
        printf("Verification successful.\n");
        printf("Source and backup files are identical.\n");
    }
    else
    {
        printf("Verification failed.\n");
        printf("Source and backup files are different.\n");
        printf("Difference detected around byte position: %ld\n",
               position);
    }

    printf("--------------------------------\n");
}

void clearInputBuffer()
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        /* discard remaining input */
    }
}