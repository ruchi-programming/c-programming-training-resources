# Student Records Using Structures

This example groups related student information into a structure and stores multiple records in an array.

It also demonstrates passing structures to functions through read-only pointers.

## Learning objectives

After completing this example, a learner should be able to:

- Declare a structure type
- Define structure members
- Initialize structure variables
- Create an array of structures
- Access members using `.` and `->`
- Pass a structure address to a function
- Use read-only structure parameters
- Find a record based on a member value
- Calculate an array element count with `sizeof`

## Source file

The complete program is available in [`student_records.c`](student_records.c).

## Declaring the structure

```c
struct Student
{
    int id;
    char name[40];
    double marks;
};
```

The structure combines three related values into one record:

- Student ID
- Student name
- Marks

Declaring the structure type does not create a student variable. It defines the layout used when student objects are declared.

## Initializing an array of structures

```c
const struct Student students[] =
{
    {101, "Aditi", 86.50},
    {102, "Rohan", 91.00}
};
```

Each initializer corresponds to the structure-member order:

```text
id, name, marks
```

The array is declared with `const` because the program displays and analyses the records without modifying them.

## Calculating the element count

```c
sizeof students / sizeof students[0]
```

This calculation works inside the scope where `students` is an actual array.

It divides:

- The total number of bytes occupied by the array
- By the number of bytes occupied by one element

The result is the number of array elements.

This technique does not work on an array parameter because an array parameter is adjusted to a pointer.

## Accessing members

For a structure object:

```c
students[index].marks
```

Use the dot operator.

For a pointer to a structure:

```c
student->marks
```

Use the arrow operator.

The expression:

```c
student->marks
```

is equivalent to:

```c
(*student).marks
```

## Finding the highest marks

The algorithm stores the index of the current best record:

```c
size_t highest_index = 0;
```

Every remaining record is compared with the record at `highest_index`.

When a larger value is found, the index is updated.

Returning the index preserves access to the complete student record.

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic student_records.c -o student_records
./student_records
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic student_records.c -o student_records.exe
.\student_records.exe
```

## Expected output

```text
Student records
------------------------------
ID: 101 | Name: Aditi      | Marks: 86.50
ID: 102 | Name: Rohan      | Marks: 91.00
ID: 103 | Name: Meera      | Marks: 78.25
ID: 104 | Name: Arjun      | Marks: 88.75

Highest marks
------------------------------
ID: 102 | Name: Rohan      | Marks: 91.00
```

## Knowledge check

1. Does declaring `struct Student` create a variable?
2. When is the dot operator used?
3. When is the arrow operator used?
4. Why is the structure pointer declared with `const`?
5. Why does the highest-marks function return an index?
6. Where is the `sizeof` array-count calculation valid?
7. What precondition does `find_highest_marks` require?

## Preconditions

The function:

```c
find_highest_marks
```

requires `count` to be greater than zero.

The example satisfies this requirement because the initialized array contains four records.

A reusable library function should explicitly validate or document this precondition.

## Practice extensions

1. Find the student with the lowest marks.
2. Calculate the class average.
3. Search for a student by ID.
4. Sort records by marks.
5. Add grade classification.
6. Read validated student records from standard input.
7. Use designated initializers for greater clarity.

## Common mistakes

- Confusing a structure declaration with a variable declaration
- Supplying initializer values in the wrong order
- Using `.` with a pointer
- Using `->` with a structure object
- Forgetting to pass the record count
- Calling the highest-record function with an empty array
- Assuming `sizeof` can determine the element count from an array parameter

## Standard used

This example uses standard C syntax and standard library facilities compatible with C17.
