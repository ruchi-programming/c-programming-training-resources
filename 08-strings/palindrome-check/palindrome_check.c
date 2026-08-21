#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int is_palindrome(const char text[]);

int main(void)
{
    char text[MAX_LENGTH];

    printf("Enter text: ");

    if (fgets(text, sizeof text, stdin) == NULL)
    {
        fprintf(stderr, "Unable to read input.\n");
        return 1;
    }

    text[strcspn(text, "\n")] = '\0';

    if (is_palindrome(text))
    {
        printf("The text is a palindrome.\n");
    }
    else
    {
        printf("The text is not a palindrome.\n");
    }

    return 0;
}

int is_palindrome(const char text[])
{
    size_t length = strlen(text);

    if (length < 2)
    {
        return 1;
    }

    size_t left = 0;
    size_t right = length - 1;

    while (left < right)
    {
        if (text[left] != text[right])
        {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}
