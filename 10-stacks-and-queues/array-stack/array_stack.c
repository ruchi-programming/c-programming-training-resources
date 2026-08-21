#include <stdio.h>
#include <stddef.h>

#define STACK_CAPACITY 5

struct Stack
{
    int elements[STACK_CAPACITY];
    size_t size;
};

void stack_initialize(struct Stack *stack);
int stack_is_empty(const struct Stack *stack);
int stack_is_full(const struct Stack *stack);
int stack_push(struct Stack *stack, int value);
int stack_pop(struct Stack *stack, int *removed_value);
int stack_peek(const struct Stack *stack, int *top_value);
void stack_display(const struct Stack *stack);

int main(void)
{
    struct Stack stack;
    int value;

    stack_initialize(&stack);

    printf("Pushing 10, 20 and 30\n");

    if (!stack_push(&stack, 10) ||
        !stack_push(&stack, 20) ||
        !stack_push(&stack, 30))
    {
        fprintf(stderr, "Stack overflow.\n");
        return 1;
    }

    stack_display(&stack);

    if (stack_peek(&stack, &value))
    {
        printf("Top element: %d\n", value);
    }

    if (stack_pop(&stack, &value))
    {
        printf("Removed element: %d\n", value);
    }

    stack_display(&stack);

    return 0;
}

void stack_initialize(struct Stack *stack)
{
    stack->size = 0;
}

int stack_is_empty(const struct Stack *stack)
{
    return stack->size == 0;
}

int stack_is_full(const struct Stack *stack)
{
    return stack->size == STACK_CAPACITY;
}

int stack_push(struct Stack *stack, int value)
{
    if (stack_is_full(stack))
    {
        return 0;
    }

    stack->elements[stack->size] = value;
    stack->size++;

    return 1;
}

int stack_pop(struct Stack *stack, int *removed_value)
{
    if (stack_is_empty(stack))
    {
        return 0;
    }

    stack->size--;
    *removed_value = stack->elements[stack->size];

    return 1;
}

int stack_peek(const struct Stack *stack, int *top_value)
{
    if (stack_is_empty(stack))
    {
        return 0;
    }

    *top_value = stack->elements[stack->size - 1];

    return 1;
}

void stack_display(const struct Stack *stack)
{
    printf("Stack from top to bottom:");

    for (size_t index = stack->size; index > 0; index--)
    {
        printf(" %d", stack->elements[index - 1]);
    }

    printf("\n");
}
