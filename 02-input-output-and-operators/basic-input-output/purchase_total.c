#include <stdio.h>

int main(void)
{
    int quantity;
    double unit_price;
    double total;

    printf("Enter quantity and unit price: ");

    if (scanf("%d %lf", &quantity, &unit_price) != 2)
    {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    if (quantity < 0 || unit_price < 0.0)
    {
        fprintf(stderr, "Values cannot be negative.\n");
        return 1;
    }

    total = quantity * unit_price;

    printf("Quantity: %d\n", quantity);
    printf("Unit price: %.2f\n", unit_price);
    printf("Total: %.2f\n", total);

    return 0;
}
