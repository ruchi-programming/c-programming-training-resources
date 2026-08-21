#include <stdio.h>

void swap(int *first, int *second);

int main(void)
{
    int first_number;
    int second_number;

    printf("Enter two integers: ");

    if (scanf("%d %d", &first_number, &second_number) != 2)
    {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    printf(
        "Before swap: first = %d, second = %d\n",
        first_number,
        second_number
    );

    swap(&first_number, &second_number);

    printf(
        "After swap:  first = %d, second = %d\n",
        first_number,
        second_number
    );

    return 0;
}

void swap(int *first, int *second)
{
    int temporary = *first;

    *first = *second;
    *second = temporary;
}
