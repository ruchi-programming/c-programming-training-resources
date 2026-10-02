#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME_SIZE 100
#define WORD_SIZE 50

char fileName[FILE_NAME_SIZE] = "";

void setFileName();
void fileStatistics();
void searchWord();
void completeReport();

long countCharacters();
long countWords();
long countLines();
long countWordOccurrences(const char searchWord[]);

void clearInputBuffer();

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       FILE SEARCH & REPORT UTILITY\n");
        printf("====================================\n");
        printf("1. Enter File Name\n");
        printf("2. File Statistics\n");
        printf("3. Search Word\n");
        printf("4. Complete Report\n");
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
                setFileName();
                break;

            case 2:
                fileStatistics();
                break;

            case 3:
                searchWord();
                break;

            case 4:
                completeReport();
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

void setFileName()
{
    FILE *fp;

    printf("\nEnter file name: ");

    if (fgets(fileName, FILE_NAME_SIZE, stdin) == NULL)
    {
        printf("Unable to read filename.\n");
        return;
    }

    fileName[strcspn(fileName, "\n")] = '\0';

    if (strlen(fileName) == 0)
    {
        printf("Filename cannot be empty.\n");
        return;
    }

    fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        fileName[0] = '\0';
        return;
    }

    fclose(fp);

    printf("File selected successfully.\n");
}

void fileStatistics()
{
    long characters;
    long words;
    long lines;

    if (strlen(fileName) == 0)
    {
        printf("\nPlease enter a file name first.\n");
        return;
    }

    characters = countCharacters();

    if (characters == -1)
    {
        return;
    }

    words = countWords();

    if (words == -1)
    {
        return;
    }

    lines = countLines();

    if (lines == -1)
    {
        return;
    }

    printf("\n====================================\n");
    printf("           FILE STATISTICS\n");
    printf("====================================\n");
    printf("File Name  : %s\n", fileName);
    printf("Characters : %ld\n", characters);
    printf("Words      : %ld\n", words);
    printf("Lines      : %ld\n", lines);
    printf("====================================\n");
}

void searchWord()
{
    char search[WORD_SIZE];
    long occurrences;

    if (strlen(fileName) == 0)
    {
        printf("\nPlease enter a file name first.\n");
        return;
    }

    printf("\nEnter word to search: ");

    if (fgets(search, WORD_SIZE, stdin) == NULL)
    {
        printf("Unable to read search word.\n");
        return;
    }

    search[strcspn(search, "\n")] = '\0';

    if (strlen(search) == 0)
    {
        printf("Search word cannot be empty.\n");
        return;
    }

    occurrences = countWordOccurrences(search);

    if (occurrences == -1)
    {
        return;
    }

    printf("\nSearch Result\n");
    printf("-----------------------------\n");
    printf("File        : %s\n", fileName);
    printf("Search Word : %s\n", search);
    printf("Occurrences : %ld\n", occurrences);
}

void completeReport()
{
    char search[WORD_SIZE];

    long characters;
    long words;
    long lines;
    long occurrences;

    if (strlen(fileName) == 0)
    {
        printf("\nPlease enter a file name first.\n");
        return;
    }

    characters = countCharacters();

    if (characters == -1)
    {
        return;
    }

    words = countWords();

    if (words == -1)
    {
        return;
    }

    lines = countLines();

    if (lines == -1)
    {
        return;
    }

    printf("\n====================================\n");
    printf("            COMPLETE REPORT\n");
    printf("====================================\n");
    printf("File Name  : %s\n", fileName);
    printf("Characters : %ld\n", characters);
    printf("Words      : %ld\n", words);
    printf("Lines      : %ld\n", lines);
    printf("====================================\n");

    printf("\nEnter a word to search: ");

    if (fgets(search, WORD_SIZE, stdin) == NULL)
    {
        printf("Unable to read search word.\n");
        return;
    }

    search[strcspn(search, "\n")] = '\0';

    if (strlen(search) == 0)
    {
        printf("Search word cannot be empty.\n");
        return;
    }

    occurrences = countWordOccurrences(search);

    if (occurrences == -1)
    {
        return;
    }

    printf("Search Word: %s\n", search);
    printf("Occurrences: %ld\n", occurrences);
}

long countCharacters()
{
    FILE *fp;
    int ch;
    long count = 0;

    fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        count++;
    }

    fclose(fp);

    return count;
}

long countWords()
{
    FILE *fp;
    int ch;
    int insideWord = 0;
    long count = 0;

    fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isspace((unsigned char)ch))
        {
            insideWord = 0;
        }
        else if (!insideWord)
        {
            count++;
            insideWord = 1;
        }
    }

    fclose(fp);

    return count;
}

long countLines()
{
    FILE *fp;
    int ch;
    int hasCharacters = 0;
    int lastCharacter = '\0';

    long count = 0;

    fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        hasCharacters = 1;
        lastCharacter = ch;

        if (ch == '\n')
        {
            count++;
        }
    }

    if (hasCharacters && lastCharacter != '\n')
    {
        count++;
    }

    fclose(fp);

    return count;
}

long countWordOccurrences(const char searchWord[])
{
    FILE *fp;

    int ch;
    int index = 0;

    long count = 0;

    char currentWord[WORD_SIZE];

    fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalnum((unsigned char)ch) || ch == '_')
        {
            if (index < WORD_SIZE - 1)
            {
                currentWord[index++] = (char)ch;
            }
        }
        else
        {
            if (index > 0)
            {
                currentWord[index] = '\0';

                if (strcmp(currentWord, searchWord) == 0)
                {
                    count++;
                }

                index = 0;
            }
        }
    }

    /*
       Process the final word if the file does not end
       with punctuation or whitespace.
    */
    if (index > 0)
    {
        currentWord[index] = '\0';

        if (strcmp(currentWord, searchWord) == 0)
        {
            count++;
        }
    }

    fclose(fp);

    return count;
}

void clearInputBuffer()
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        /* discard remaining input */
    }
}