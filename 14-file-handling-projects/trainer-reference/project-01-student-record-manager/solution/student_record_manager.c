#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.txt"
#define TEMP_FILE "students_temp.txt"
#define NAME_SIZE 50

struct Student
{
    int rollNumber;
    char name[NAME_SIZE];
    float marks;
};

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();

int rollNumberExists(int rollNumber);
void clearInputBuffer();

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("      STUDENT RECORD MANAGER\n");
        printf("====================================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
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
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
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

void addStudent()
{
    struct Student student;
    FILE *fp;

    printf("\nEnter roll number: ");

    if (scanf("%d", &student.rollNumber) != 1)
    {
        printf("Invalid roll number.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (student.rollNumber <= 0)
    {
        printf("Roll number must be positive.\n");
        return;
    }

    if (rollNumberExists(student.rollNumber))
    {
        printf("A student with this roll number already exists.\n");
        return;
    }

    printf("Enter name: ");

    if (fgets(student.name, NAME_SIZE, stdin) == NULL)
    {
        printf("Unable to read name.\n");
        return;
    }

    student.name[strcspn(student.name, "\n")] = '\0';

    if (strlen(student.name) == 0)
    {
        printf("Name cannot be empty.\n");
        return;
    }

    printf("Enter marks: ");

    if (scanf("%f", &student.marks) != 1)
    {
        printf("Invalid marks.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (student.marks < 0 || student.marks > 100)
    {
        printf("Marks must be between 0 and 100.\n");
        return;
    }

    fp = fopen(FILE_NAME, "a");

    if (fp == NULL)
    {
        printf("Error: Unable to open student file.\n");
        return;
    }

    fprintf(fp, "%d %s %.2f\n",
            student.rollNumber,
            student.name,
            student.marks);

    fclose(fp);

    printf("\nStudent added successfully.\n");
}

void displayStudents()
{
    struct Student student;
    FILE *fp;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n====================================\n");
    printf("          STUDENT RECORDS\n");
    printf("====================================\n");

    printf("%-10s %-20s %-10s\n",
           "Roll No", "Name", "Marks");

    printf("------------------------------------\n");

    while (fscanf(fp, "%d %49s %f",
                  &student.rollNumber,
                  student.name,
                  &student.marks) == 3)
    {
        printf("%-10d %-20s %-10.2f\n",
               student.rollNumber,
               student.name,
               student.marks);
    }

    fclose(fp);
}

void searchStudent()
{
    struct Student student;
    FILE *fp;
    int rollNumber;
    int found = 0;

    printf("\nEnter roll number to search: ");

    if (scanf("%d", &rollNumber) != 1)
    {
        printf("Invalid roll number.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo student records found.\n");
        return;
    }

    while (fscanf(fp, "%d %49s %f",
                  &student.rollNumber,
                  student.name,
                  &student.marks) == 3)
    {
        if (student.rollNumber == rollNumber)
        {
            printf("\nStudent Found\n");
            printf("-----------------------------\n");
            printf("Roll Number : %d\n", student.rollNumber);
            printf("Name        : %s\n", student.name);
            printf("Marks       : %.2f\n", student.marks);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
    {
        printf("\nStudent not found.\n");
    }
}

void updateStudent()
{
    struct Student student;
    FILE *fp;
    FILE *tempFp;

    int rollNumber;
    int found = 0;

    char newName[NAME_SIZE];
    float newMarks;

    printf("\nEnter roll number to update: ");

    if (scanf("%d", &rollNumber) != 1)
    {
        printf("Invalid roll number.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo student records found.\n");
        return;
    }

    tempFp = fopen(TEMP_FILE, "w");

    if (tempFp == NULL)
    {
        printf("\nError: Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "%d %49s %f",
                  &student.rollNumber,
                  student.name,
                  &student.marks) == 3)
    {
        if (student.rollNumber == rollNumber)
        {
            found = 1;

            printf("Enter new name: ");

            if (fgets(newName, NAME_SIZE, stdin) == NULL)
            {
                printf("Unable to read name.\n");
                fclose(fp);
                fclose(tempFp);
                remove(TEMP_FILE);
                return;
            }

            newName[strcspn(newName, "\n")] = '\0';

            if (strlen(newName) == 0)
            {
                printf("Name cannot be empty.\n");
                fclose(fp);
                fclose(tempFp);
                remove(TEMP_FILE);
                return;
            }

            printf("Enter new marks: ");

            if (scanf("%f", &newMarks) != 1)
            {
                printf("Invalid marks.\n");
                clearInputBuffer();
                fclose(fp);
                fclose(tempFp);
                remove(TEMP_FILE);
                return;
            }

            clearInputBuffer();

            if (newMarks < 0 || newMarks > 100)
            {
                printf("Marks must be between 0 and 100.\n");
                fclose(fp);
                fclose(tempFp);
                remove(TEMP_FILE);
                return;
            }

            fprintf(tempFp, "%d %s %.2f\n",
                    student.rollNumber,
                    newName,
                    newMarks);
        }
        else
        {
            fprintf(tempFp, "%d %s %.2f\n",
                    student.rollNumber,
                    student.name,
                    student.marks);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found)
    {
        if (remove(FILE_NAME) != 0)
        {
            printf("\nError: Unable to replace original file.\n");
            remove(TEMP_FILE);
            return;
        }

        if (rename(TEMP_FILE, FILE_NAME) != 0)
        {
            printf("\nError: Unable to rename temporary file.\n");
            return;
        }

        printf("\nStudent updated successfully.\n");
    }
    else
    {
        remove(TEMP_FILE);
        printf("\nStudent not found.\n");
    }
}

int rollNumberExists(int rollNumber)
{
    struct Student student;
    FILE *fp;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        return 0;
    }

    while (fscanf(fp, "%d %49s %f",
                  &student.rollNumber,
                  student.name,
                  &student.marks) == 3)
    {
        if (student.rollNumber == rollNumber)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}

void clearInputBuffer()
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        /* discard remaining input */
    }
}