#include <stdio.h>

#define MAX_SIZE 20

int calculate_sum(const int values[], int size);
int find_minimum(const int values[], int size);
int find_maximum(const int values[], int size);

int main(void)
{
    int values[MAX_SIZE];
    int size;

    printf("Enter the number of elements from 1 to %d: ", MAX_SIZE);

    if (scanf("%d", &size) != 1)
    {
        fprintf(stderr, "Invalid size.\n");
        return 1;
    }

    if (size < 1 || size > MAX_SIZE)
    {
        fprintf(
            stderr,
            "Size must be between 1 and %d.\n",
            MAX_SIZE
        );
        return 1;
    }

    printf("Enter %d integers: ", size);

    for (int index = 0; index < size; index++)
    {
        if (scanf("%d", &values[index]) != 1)
        {
            fprintf(stderr, "Invalid array element.\n");
            return 1;
        }
    }

    int sum = calculate_sum(values, size);
    int minimum = find_minimum(values, size);
    int maximum = find_maximum(values, size);
    double average = (double)sum / size;

    printf("Sum: %d\n", sum);
    printf("Minimum: %d\n", minimum);
    printf("Maximum: %d\n", maximum);
    printf("Average: %.2f\n", average);

    return 0;
}

int calculate_sum(const int values[], int size)
{
    int sum = 0;

    for (int index = 0; index < size; index++)
    {
        sum += values[index];
    }

    return sum;
}

int find_minimum(const int values[], int size)
{
    int minimum = values[0];

    for (int index = 1; index < size; index++)
    {
        if (values[index] < minimum)
        {
            minimum = values[index];
        }
    }

    return minimum;
}

int find_maximum(const int values[], int size)
{
    int maximum = values[0];

    for (int index = 1; index < size; index++)
    {
        if (values[index] > maximum)
        {
            maximum = values[index];
        }
    }

    return maximum;
}
