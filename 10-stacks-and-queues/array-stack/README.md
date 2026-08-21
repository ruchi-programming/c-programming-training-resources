# Stack Using an Array

A stack is a linear data structure that follows:

```text
Last In, First Out
```

The most recently inserted element is the first element removed.

This example implements a fixed-capacity stack using an array and a structure.

## Learning objectives

After completing this example, a learner should be able to:

- Explain Last In, First Out behaviour
- Represent stack state using a structure
- Initialize an empty stack
- Implement push, pop and peek
- Detect stack overflow and underflow
- Maintain a stack-size invariant
- Display elements from top to bottom
- Return operation status separately from output data

## Source file

The complete program is available in [`array_stack.c`](array_stack.c).

## Stack representation

```c
struct Stack
{
    int elements[STACK_CAPACITY];
    size_t size;
};
```

The structure contains:

- `elements`: storage for stack values
- `size`: the number of values currently stored

The stack is empty when:

```c
size == 0
```

The stack is full when:

```c
size == STACK_CAPACITY
```

## Stack invariant

At every valid point:

```text
0 <= size <= STACK_CAPACITY
```

When the stack is not empty, the top element is stored at:

```c
elements[size - 1]
```

## Push operation

```c
stack->elements[stack->size] = value;
stack->size++;
```

The new value is stored at the first unused position. The size is then increased.

A push must not occur when the stack is full.

## Pop operation

```c
stack->size--;
*removed_value = stack->elements[stack->size];
```

The size is decreased first. The new size then identifies the element that was previously at the top.

The array value does not need to be erased. Reducing the logical size removes it from the stack.

## Peek operation

Peek reads the top value without changing the stack size:

```c
*top_value = stack->elements[stack->size - 1];
```

Peek is invalid when the stack is empty.

## Status and output parameters

The pop function returns:

- `1` when an element was removed
- `0` when the stack was empty

The removed value is returned through:

```c
int *removed_value
```

This separates the operation status from the stored integer value. Every possible `int` can remain valid stack data.

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic array_stack.c -o array_stack
./array_stack
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic array_stack.c -o array_stack.exe
.\array_stack.exe
```

## Expected output

```text
Pushing 10, 20 and 30
Stack from top to bottom: 30 20 10
Top element: 30
Removed element: 30
Stack from top to bottom: 20 10
```

## Operation trace

| Operation | Array content in use | Size | Top |
|---|---|---:|---:|
| Initialize | Empty | 0 | None |
| Push 10 | `10` | 1 | 10 |
| Push 20 | `10 20` | 2 | 20 |
| Push 30 | `10 20 30` | 3 | 30 |
| Peek | `10 20 30` | 3 | 30 |
| Pop | `10 20` | 2 | 20 |

## Knowledge check

1. What does Last In, First Out mean?
2. Which member records the logical number of elements?
3. Where is the top element stored?
4. Why must push check whether the stack is full?
5. Why must pop check whether the stack is empty?
6. Why does pop return status separately from the removed value?
7. Does pop need to erase the old array element?

## Practice extensions

1. Test stack overflow.
2. Test pop and peek on an empty stack.
3. Build a menu-driven stack program.
4. Add a function that reports the current size.
5. Use the stack to reverse a sequence.
6. Use a character stack to reverse a string.
7. Implement a dynamically allocated stack as advanced practice.

## Common mistakes

- Treating `size` as the top index
- Accessing `elements[size]` when reading the top
- Incrementing size before checking capacity
- Decrementing size when the stack is empty
- Confusing physical array values with logical stack contents
- Using a special integer as an error value
- Displaying the stack in the wrong direction

## Complexity

| Operation | Time complexity |
|---|---|
| Push | O(1) |
| Pop | O(1) |
| Peek | O(1) |
| Is empty | O(1) |
| Is full | O(1) |
| Display | O(n) |

## Standard used

This example uses standard C syntax and standard library facilities compatible with C17.
