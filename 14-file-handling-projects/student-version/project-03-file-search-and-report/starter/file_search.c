#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME_SIZE 100
#define WORD_SIZE 50

/* Function declarations */

void setFileName();
void fileStatistics();
void searchWord();
void completeReport();

int main()
{
    int choice;

    do
    {
        printf("\n");
        printf("========================================\n");
        printf("       FILE SEARCH & REPORT UTILITY\n");
        printf("========================================\n");
        printf("1. Enter File Name\n");
        printf("2. File Statistics\n");
        printf("3. Search Word\n");
        printf("4. Complete Report\n");
        printf("5. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

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

/*
 * Set the filename to be analyzed.
 *
 * TODO:
 * 1. Ask the user for a filename.
 * 2. Store the filename.
 * 3. Check whether the file can be opened.
 * 4. Display an appropriate message.
 *
 * Hint:
 * You may need a global variable or another
 * suitable way to share the filename between functions.
 */
void setFileName()
{
    /* TODO: Implement filename input */
}

/*
 * Calculate and display file statistics.
 *
 * Required statistics:
 * - Characters
 * - Words
 * - Lines
 *
 * TODO:
 * 1. Open the selected file.
 * 2. Check whether it opened successfully.
 * 3. Read the file.
 * 4. Count characters.
 * 5. Count words.
 * 6. Count lines.
 * 7. Display the results.
 * 8. Close the file.
 */
void fileStatistics()
{
    /* TODO: Implement file statistics */
}

/*
 * Search for a word in the selected file.
 *
 * TODO:
 * 1. Ask the user for a search word.
 * 2. Open the file.
 * 3. Read the file.
 * 4. Compare complete words.
 * 5. Count occurrences.
 * 6. Display the result.
 * 7. Close the file.
 *
 * Think carefully about:
 * - Case sensitivity
 * - Punctuation
 * - Word boundaries
 */
void searchWord()
{
    /* TODO: Implement word search */
}

/*
 * Display the complete report.
 *
 * The report should include:
 * - File name
 * - Character count
 * - Word count
 * - Line count
 * - Search word
 * - Search result
 *
 * TODO:
 * 1. Make sure a valid filename has been selected.
 * 2. Calculate file statistics.
 * 3. Ask for a search word.
 * 4. Search for the word.
 * 5. Display everything together.
 */
void completeReport()
{
    /* TODO: Implement complete report */
}