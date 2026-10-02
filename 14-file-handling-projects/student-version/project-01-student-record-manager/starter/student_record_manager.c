#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.txt"
#define NAME_SIZE 50

struct Student
{
    int rollNumber;
    char name[NAME_SIZE];
    float marks;
};

/* Function declarations */
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();

int main()
{
    int choice;

    do
    {
        printf("\n");
        printf("====================================\n");
        printf("       STUDENT RECORD MANAGER\n");
        printf("====================================\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

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

/*
 * Add a new student record.
 *
 * TODO:
 * 1. Create a Student variable.
 * 2. Accept roll number, name and marks.
 * 3. Open FILE_NAME using an appropriate file mode.
 * 4. Check whether the file opened successfully.
 * 5. Write the student record to the file.
 * 6. Close the file.
 */
void addStudent()
{
    /* TODO: Implement Add Student */
}

/*
 * Display all student records.
 *
 * TODO:
 * 1. Open FILE_NAME for reading.
 * 2. Check whether the file opened successfully.
 * 3. Read records one by one.
 * 4. Display them in a readable format.
 * 5. Handle an empty/non-existing file.
 * 6. Close the file.
 */
void displayStudents()
{
    /* TODO: Implement Display Students */
}

/*
 * Search for a student using roll number.
 *
 * TODO:
 * 1. Ask the user for a roll number.
 * 2. Open FILE_NAME for reading.
 * 3. Read records one by one.
 * 4. Compare each roll number.
 * 5. Display the matching student.
 * 6. Display "Student not found" if there is no match.
 * 7. Close the file.
 */
void searchStudent()
{
    /* TODO: Implement Search Student */
}

/*
 * Update the marks of an existing student.
 *
 * TODO:
 * 1. Ask the user for the roll number.
 * 2. Open the original file for reading.
 * 3. Create a temporary file.
 * 4. Read records one by one.
 * 5. When the matching student is found,
 *    accept the new marks.
 * 6. Write records to the temporary file.
 * 7. Replace the original file with the temporary file.
 * 8. Handle the case where the student is not found.
 * 9. Close all files.
 */
void updateStudent()
{
    /* TODO: Implement Update Student */
}