# C Programming Training Resources

A structured collection of standards-compliant C examples, explanations, trace tables, tests and practice activities for students and trainers.

## About this repository

This repository supports the gradual development of programming fundamentals through:

- Small, focused C programs
- Concept explanations
- Compilation instructions
- Execution traces
- Normal and boundary tests
- Knowledge-check questions
- Practice extensions
- Data Structures and Algorithms foundations

The examples are written for teaching, classroom demonstration and independent practice.

## Intended audience

- Beginners learning C programming
- Students developing problem-solving skills
- Learners preparing for practical assessments
- Trainers looking for structured demonstration examples
- Learners beginning Data Structures and Algorithms

## Learning sequence

Each example follows a consistent process:

1. Understand the concept.
2. Study the program.
3. Predict the output.
4. Trace important variables.
5. Compile with warnings enabled.
6. Test normal and boundary cases.
7. Diagnose common mistakes.
8. Complete practice extensions.

## Repository contents

### 1. C fundamentals

- [Hello World](01-c-fundamentals/hello-world/)
- [Structure of a C Program](01-c-fundamentals/program-structure/)

### 2. Input, output and operators

- [Standard Input and Formatted Output](02-input-output-and-operators/basic-input-output/)

### 3. Decision-making

- [Grade Classifier](03-decision-making/grade-classifier/)

### 4. Loops and patterns

- [Multiplication Table](04-loops-and-patterns/multiplication-table/)

### 5. Functions

- [Functions, Prototypes and Return Values](05-functions/function-basics/)

### 6. Pointers and memory

- [Swapping Values Using Pointers](06-pointers-and-memory/pointer-swap/)

### 7. Arrays and matrices

- [One-Dimensional Array Statistics](07-arrays-and-matrices/array-statistics/)

### 8. Strings

- [Palindromic String](08-strings/palindrome-check/)

### 9. Structures

- [Student Records Using Structures](09-structures/student-records/)

### 10. Stacks and queues

- [Stack Using an Array](10-stacks-and-queues/array-stack/)

### 11. Data Structures and Algorithms

- [Binary Search](11-dsa-foundations/binary-search/)

### 12. Coding-platform practice

- [FizzBuzz](12-coding-platform-practice/fizzbuzz/)

## Compilation standard

Examples can be compiled with GCC using:

```bash
gcc -std=c17 -Wall -Wextra -pedantic source_file.c -o program
```

On Windows PowerShell:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic source_file.c -o program.exe
.\program.exe
```

## Code-quality principles

The examples aim to demonstrate:

- Standard C syntax
- Meaningful identifiers
- Consistent formatting
- Input validation
- Clear function responsibilities
- Safe array boundaries
- Appropriate use of `const`
- Normal and boundary testing
- Accurate technical explanations

## Educational-use guidance

Students should:

- Attempt exercises before viewing complete examples.
- Trace the program before executing it.
- Test code with multiple inputs.
- Explain corrections in their own words.
- Avoid copying solutions without understanding them.

Trainers may adapt the examples to their lesson plans and learner levels.

## Repository roadmap

Planned additions include:

- Operators and expression examples
- `switch` programs
- Nested-loop patterns
- Recursion
- Dynamic memory management
- Array insertion and deletion
- Searching and sorting algorithms
- Matrix operations
- Manual string operations
- Queue implementation
- Additional DSA examples
- Platform-practice problems

## Maintainer

**Ruchi**  
Technical Trainer – C, C++, DSA, .NET and Databases

## Feedback

Constructive feedback, corrections and educational suggestions are welcome through GitHub issues.

> Understand the logic. Trace the execution. Write the code. Test the boundaries.
