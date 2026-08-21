#include <stdio.h>

int is_even(int number);
unsigned long long factorial(int number);

int main(void)
{
    int number;

    printf("Enter an integer from 0 to 20: ");

    if (scanf("%d", &number) != 1)
    {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    if (number < 0 || number > 20)
    {
        fprintf(stderr, "Number must be between 0 and 20.\n");
        return 1;
    }

    if (is_even(number))
    {
        printf("%d is even.\n", number);
    }
    else
    {
        printf("%d is odd.\n", number);
    }

    printf(
        "%d! = %llu\n",
        number,
        factorial(number)
    );

    return 0;
}

int is_even(int number)
{
    return number % 2 == 0;
}

unsigned long long factorial(int number)
{
    unsigned long long result = 1;

    for (int value = 2; value <= number; value++)
    {
        result *= (unsigned long long)value;
    }

    return result;
}
