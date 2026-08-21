#include <stdio.h>

int main(void)
{
    int number;
    int limit;

    printf("Enter the number and table limit: ");

    if (scanf("%d %d", &number, &limit) != 2)
    {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    if (limit < 1 || limit > 100)
    {
        fprintf(stderr, "Limit must be between 1 and 100.\n");
        return 1;
    }

    for (int multiplier = 1; multiplier <= limit; multiplier++)
    {
        printf(
            "%d x %d = %d\n",
            number,
            multiplier,
            number * multiplier
        );
    }

    return 0;
}
