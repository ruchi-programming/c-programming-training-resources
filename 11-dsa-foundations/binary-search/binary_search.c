#include <stdio.h>

int binary_search(
    const int values[],
    int size,
    int search_value
);

int main(void)
{
    const int values[] =
    {
        3, 8, 12, 17, 25, 31, 42, 56, 68, 79
    };

    const int size =
        (int)(sizeof values / sizeof values[0]);

    int search_value;

    printf("Sorted values:");

    for (int index = 0; index < size; index++)
    {
        printf(" %d", values[index]);
    }

    printf("\nEnter a value to search for: ");

    if (scanf("%d", &search_value) != 1)
    {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    int result =
        binary_search(values, size, search_value);

    if (result == -1)
    {
        printf("%d was not found.\n", search_value);
    }
    else
    {
        printf(
            "%d was found at index %d.\n",
            search_value,
            result
        );
    }

    return 0;
}

int binary_search(
    const int values[],
    int size,
    int search_value
)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int middle = low + (high - low) / 2;

        if (values[middle] == search_value)
        {
            return middle;
        }

        if (values[middle] < search_value)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }

    return -1;
}
