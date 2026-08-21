#include <stdio.h>

int main(void)
{
    int limit;

    printf("Enter the upper limit from 1 to 1000: ");

    if (scanf("%d", &limit) != 1)
    {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    if (limit < 1 || limit > 1000)
    {
        fprintf(
            stderr,
            "Limit must be between 1 and 1000.\n"
        );
        return 1;
    }

    for (int number = 1; number <= limit; number++)
    {
        if (number % 15 == 0)
        {
            printf("FizzBuzz\n");
        }
        else if (number % 3 == 0)
        {
            printf("Fizz\n");
        }
        else if (number % 5 == 0)
        {
            printf("Buzz\n");
        }
        else
        {
            printf("%d\n", number);
        }
    }

    return 0;
}
