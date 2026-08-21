#include <stdio.h>

int main(void)
{
    const int length = 8;
    const int width = 5;
    int area;

    area = length * width;

    printf("Length: %d\n", length);
    printf("Width: %d\n", width);
    printf("Area: %d\n", area);

    return 0;
}
