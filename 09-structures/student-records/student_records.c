#include <stdio.h>
#include <stddef.h>

struct Student
{
    int id;
    char name[40];
    double marks;
};

void print_student(const struct Student *student);
size_t find_highest_marks(
    const struct Student students[],
    size_t count
);

int main(void)
{
    const struct Student students[] =
    {
        {101, "Aditi", 86.50},
        {102, "Rohan", 91.00},
        {103, "Meera", 78.25},
        {104, "Arjun", 88.75}
    };

    const size_t count =
        sizeof students / sizeof students[0];

    printf("Student records\n");
    printf("------------------------------\n");

    for (size_t index = 0; index < count; index++)
    {
        print_student(&students[index]);
    }

    size_t highest_index =
        find_highest_marks(students, count);

    printf("\nHighest marks\n");
    printf("------------------------------\n");
    print_student(&students[highest_index]);

    return 0;
}

void print_student(const struct Student *student)
{
    printf(
        "ID: %d | Name: %-10s | Marks: %.2f\n",
        student->id,
        student->name,
        student->marks
    );
}

size_t find_highest_marks(
    const struct Student students[],
    size_t count
)
{
    size_t highest_index = 0;

    for (size_t index = 1; index < count; index++)
    {
        if (students[index].marks >
            students[highest_index].marks)
        {
            highest_index = index;
        }
    }

    return highest_index;
}
