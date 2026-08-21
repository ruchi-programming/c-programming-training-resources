# Binary Search in C

Binary search locates a value by repeatedly reducing the active search interval.

## Essential prerequisite

The array must be sorted according to the same ordering used by the search.

This example uses ascending order.

Applying binary search to unsorted data does not produce reliable results.

## Learning objectives

After completing this example, a learner should be able to:

- State the sorted-data prerequisite
- Maintain `low`, `high` and `middle` indices
- Reduce the search interval correctly
- Identify successful and unsuccessful termination
- Return an index or a not-found result
- Trace binary-search iterations
- Explain logarithmic time complexity
- Compare binary search with linear search

## Source file

The complete program is available in [`binary_search.c`](binary_search.c).

## Search interval

The initial interval covers the complete array:

```c
int low = 0;
int high = size - 1;
```

The interval remains valid while:

```c
low <= high
```

When `low` becomes greater than `high`, no candidate positions remain.

## Calculating the middle index

```c
int middle = low + (high - low) / 2;
```

This form avoids the potential overflow associated with:

```c
(low + high) / 2
```

for very large positive indices.

## Reducing the interval

When the middle value is smaller than the required value:

```c
low = middle + 1;
```

Only the right portion can contain the target.

When the middle value is larger:

```c
high = middle - 1;
```

Only the left portion can contain the target.

The middle position is excluded because it has already been compared.

## Return values

The function returns:

- A valid zero-based index when the value is found
- `-1` when the value is absent

Because valid indices begin at zero, `-1` can represent the not-found condition.

## Compile and run

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -pedantic binary_search.c -o binary_search
./binary_search
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic binary_search.c -o binary_search.exe
.\binary_search.exe
```

## Example search

Array:

```text
3 8 12 17 25 31 42 56 68 79
```

Search value:

```text
42
```

Result:

```text
42 was found at index 6.
```

## Trace

| Iteration | `low` | `high` | `middle` | Middle value | Decision |
|---:|---:|---:|---:|---:|---|
| 1 | 0 | 9 | 4 | 25 | Search right |
| 2 | 5 | 9 | 7 | 56 | Search left |
| 3 | 5 | 6 | 5 | 31 | Search right |
| 4 | 6 | 6 | 6 | 42 | Found |

## Boundary tests

| Search value | Expected result |
|---:|---|
| `3` | Index 0 |
| `79` | Index 9 |
| `42` | Index 6 |
| `2` | Not found |
| `80` | Not found |
| `30` | Not found |
| Invalid text | Input error |

## Complexity

| Measurement | Complexity |
|---|---|
| Best-case time | O(1) |
| Worst-case time | O(log n) |
| Iterative auxiliary space | O(1) |

Binary search eliminates approximately half of the remaining candidates after every comparison.

Linear search may inspect every element and has worst-case time complexity O(n), but it does not require sorted data.

## Duplicate values

When duplicate values are present, this implementation returns one matching index. It does not guarantee the first or last occurrence.

Finding the first or last duplicate requires a modified search.

## Knowledge check

1. Why must the array be sorted?
2. Why is the loop condition `low <= high`?
3. Why are `middle + 1` and `middle - 1` used?
4. What does `-1` represent?
5. What happens if the search value is smaller than every element?
6. Does this version guarantee the first duplicate?
7. How does the worst-case complexity compare with linear search?

## Practice extensions

1. Count the comparisons.
2. Find the insertion position for an absent value.
3. Find the first occurrence of a duplicate.
4. Find the last occurrence of a duplicate.
5. Implement recursive binary search.
6. Compare linear and binary search on the same sorted array.
7. Allow the user to enter and validate a sorted array.

## Common mistakes

- Searching unsorted data
- Initializing `high` to `size`
- Using `low < high` and missing the final candidate
- Updating `low` to `middle`
- Updating `high` to `middle`
- Reversing the left and right decisions
- Accessing the array after the interval becomes empty
- Claiming that an arbitrary matching duplicate is the first match

## Standard used

This example uses standard C syntax and standard library facilities compatible with C17.
