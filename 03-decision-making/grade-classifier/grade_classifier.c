#include <stdio.h>

int main(void)
{
    int marks;

    printf("Enter marks from 0 to 100: ");

    if (scanf("%d", &marks) != 1)
    {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    if (marks < 0 || marks > 100)
    {
        fprintf(stderr, "Marks must be between 0 and 100.\n");
        return 1;
    }

    if (marks >= 80)
    {
        printf("Grade: A\n");
    }
    else if (marks >= 60)
    {
        printf("Grade: B\n");
    }
    else if (marks >= 40)
    {
        printf("Grade: C\n");
    }
    else
    {
        printf("Grade: F\n");
    }

    return 0;
}
