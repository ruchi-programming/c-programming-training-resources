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
void deleteStudent();
void studentStatistics();

int rollNumberExists(int rollNumber);
void clearInputBuffer();

int main()
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("      STUDENT RECORD MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Student Statistics\n");
        printf("7. Exit\n");
        printf("========================================\n");

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
                deleteStudent();
                break;

            case 6:
                studentStatistics();
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
        printf("Roll number already exists.\n");
        return;
    }

    printf("Enter student name: ");

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

    printf("\n================================================\n");
    printf("                 STUDENT RECORDS\n");
    printf("================================================\n");

    printf("%-12s %-25s %-10s\n",
           "Roll No",
           "Name",
           "Marks");

    printf("------------------------------------------------\n");

    while (fscanf(fp,
                  "%d %49s %f",
                  &student.rollNumber,
                  student.name,
                  &student.marks) == 3)
    {
        printf("%-12d %-25s %-10.2f\n",
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
        printf("No student records found.\n");
        return;
    }

    while (fscanf(fp,
                  "%d %49s %f",
                  &student.rollNumber,
                  student.name,
                  &student.marks) == 3)
    {
        if (student.rollNumber == rollNumber)
        {
            printf("\nStudent Found\n");
            printf("--------------------------\n");
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
    FILE *temp;

    int rollNumber;
    int found = 0;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo student records found.\n");
        return;
    }

    temp = fopen(TEMP_FILE, "w");

    if (temp == NULL)
    {
        printf("Error: Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    printf("\nEnter roll number to update: ");

    if (scanf("%d", &rollNumber) != 1)
    {
        printf("Invalid roll number.\n");
        clearInputBuffer();
        fclose(fp);
        fclose(temp);
        remove(TEMP_FILE);
        return;
    }

    clearInputBuffer();

    while (fscanf(fp,
                  "%d %49s %f",
                  &student.rollNumber,
                  student.name,
                  &student.marks) == 3)
    {
        if (student.rollNumber == rollNumber)
        {
            found = 1;

            printf("Enter new name: ");

            if (fgets(student.name,
                      NAME_SIZE,
                      stdin) == NULL)
            {
                printf("Unable to read name.\n");
                fclose(fp);
                fclose(temp);
                remove(TEMP_FILE);
                return;
            }

            student.name[
                strcspn(student.name, "\n")
            ] = '\0';

            printf("Enter new marks: ");

            if (scanf("%f", &student.marks) != 1)
            {
                printf("Invalid marks.\n");
                clearInputBuffer();
                fclose(fp);
                fclose(temp);
                remove(TEMP_FILE);
                return;
            }

            clearInputBuffer();

            if (student.marks < 0 ||
                student.marks > 100)
            {
                printf("Marks must be between 0 and 100.\n");
                fclose(fp);
                fclose(temp);
                remove(TEMP_FILE);
                return;
            }
        }

        fprintf(temp,
                "%d %s %.2f\n",
                student.rollNumber,
                student.name,
                student.marks);
    }

    fclose(fp);
    fclose(temp);

    if (!found)
    {
        remove(TEMP_FILE);
        printf("\nStudent not found.\n");
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
        printf("Error: Unable to replace student file.\n");
        return;
    }

    printf("\nStudent updated successfully.\n");
}

void deleteStudent()
{
    struct Student student;
    FILE *fp;
    FILE *temp;

    int rollNumber;
    int found = 0;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo student records found.\n");
        return;
    }

    temp = fopen(TEMP_FILE, "w");

    if (temp == NULL)
    {
        printf("Error: Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    printf("\nEnter roll number to delete: ");

    if (scanf("%d", &rollNumber) != 1)
    {
        printf("Invalid roll number.\n");
        clearInputBuffer();
        fclose(fp);
        fclose(temp);
        remove(TEMP_FILE);
        return;
    }

    clearInputBuffer();

    while (fscanf(fp,
                  "%d %49s %f",
                  &student.rollNumber,
                  student.name,
                  &student.marks) == 3)
    {
        if (student.rollNumber == rollNumber)
        {
            found = 1;
            continue;
        }

        fprintf(temp,
                "%d %s %.2f\n",
                student.rollNumber,
                student.name,
                student.marks);
    }

    fclose(fp);
    fclose(temp);

    if (!found)
    {
        remove(TEMP_FILE);
        printf("\nStudent not found.\n");
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
        printf("Error: Unable to replace student file.\n");
        return;
    }

    printf("\nStudent deleted successfully.\n");
}

void studentStatistics()
{
    struct Student student;
    FILE *fp;

    int count = 0;
    int passCount = 0;

    float total = 0.0f;
    float highest = 0.0f;
    float lowest = 0.0f;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("\nNo student records found.\n");
        return;
    }

    while (fscanf(fp,
                  "%d %49s %f",
                  &student.rollNumber,
                  student.name,
                  &student.marks) == 3)
    {
        if (count == 0)
        {
            highest = student.marks;
            lowest = student.marks;
        }

        count++;
        total += student.marks;

        if (student.marks >= 40.0f)
        {
            passCount++;
        }

        if (student.marks > highest)
        {
            highest = student.marks;
        }

        if (student.marks < lowest)
        {
            lowest = student.marks;
        }
    }

    fclose(fp);

    if (count == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n====================================\n");
    printf("        STUDENT STATISTICS\n");
    printf("====================================\n");
    printf("Total Students : %d\n", count);
    printf("Average Marks  : %.2f\n", total / count);
    printf("Highest Marks  : %.2f\n", highest);
    printf("Lowest Marks   : %.2f\n", lowest);
    printf("Passed         : %d\n", passCount);
    printf("Failed         : %d\n", count - passCount);
    printf("====================================\n");
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

    while (fscanf(fp,
                  "%d %49s %f",
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