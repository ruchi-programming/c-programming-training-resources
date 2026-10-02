# Project 3 – File Search & Report Utility

## Overview

In Q115, you learned how to count characters, words, and lines in a file.

In Q118, you learned how to search for a word in a file and count its occurrences.

Now you will combine these concepts to build a **File Search & Report Utility**.

The program will read a text file, calculate useful statistics, and search for a word specified by the user.

> **Prerequisite:** Complete Q114–Q118 and Projects 1–2 before starting this project.

---

# Learning Objectives

By completing this project, you will practice:

- Opening text files
- Reading files character by character
- Reading files line by line
- Counting characters
- Counting words
- Counting lines
- Searching for words
- Counting word occurrences
- Using functions
- Building a menu-driven program
- Handling file errors
- Generating a simple report

---

# Problem Statement

Create a C program that analyzes a text file.

The program should allow the user to:

1. Enter a filename
2. Display file statistics
3. Search for a word
4. Display a complete report
5. Exit

The report should contain:

```text
File Name
Characters
Words
Lines
Search Word
Occurrences
```

---

# Menu Requirements

Your program should display a menu similar to:

```text
========================================
       FILE SEARCH & REPORT UTILITY
========================================

1. Enter File Name
2. File Statistics
3. Search Word
4. Complete Report
5. Exit

========================================
Enter your choice:
```

You may customize the menu.

---

# Functional Requirements

## 1. Enter File Name

Ask the user for the name of the file to analyze.

Example:

```text
Enter filename: sample.txt
```

Store the filename so that the other operations can use it.

The program should check whether the file exists before performing analysis.

---

# 2. File Statistics

Calculate and display:

- Number of characters
- Number of words
- Number of lines

Example:

```text
========================================
             FILE STATISTICS
========================================

File Name  : sample.txt
Characters : 245
Words      : 42
Lines      : 8
```

---

# Character Counting

Count the characters contained in the file.

Decide how your program will treat:

- Letters
- Numbers
- Spaces
- Tabs
- Newline characters
- Punctuation

Document your decision in your algorithm.

---

# Word Counting

Count words in the file.

For this project, you may define a word as a sequence of characters separated by whitespace.

For example:

```text
C programming is interesting.
```

contains:

```text
4 words
```

You may use functions such as:

```c
isspace()
```

from:

```c
#include <ctype.h>
```

---

# Line Counting

Count the number of lines in the file.

Test your program with:

- Empty files
- One-line files
- Multiple-line files
- Files where the final line does not end with a newline

Document how your program handles these cases.

---

# 3. Search Word

Ask the user for a word to search.

Example:

```text
Enter word to search: programming
```

Display:

```text
Word: programming
Occurrences: 4
```

If the word does not occur:

```text
Word not found.
```

---

# Search Rules

For the basic version:

- Search should be case-sensitive.
- Compare complete words.
- Do not count a word when it is only part of another word.

For example, searching for:

```text
C
```

should not automatically count:

```text
coding
```

unless your chosen implementation intentionally defines it differently.

Explain your approach in your algorithm.

---

# 4. Complete Report

The program should combine the statistics and search functionality.

Example:

```text
========================================
             COMPLETE REPORT
========================================

File Name      : sample.txt
Characters     : 245
Words          : 42
Lines          : 8

Search Word    : programming
Occurrences    : 4

========================================
```

---

# File Requirements

The program should work with a normal text file.

Example:

```text
sample.txt
```

The user should be able to specify a different filename.

Do not hard-code the file contents.

---

# Programming Requirements

Your program should use:

- `FILE`
- `fopen()`
- `fclose()`
- File reading
- Functions
- Loops
- Conditional statements
- Character processing
- String processing
- Error handling

You should use functions to separate the different operations.

---

# Suggested Functions

You may use functions such as:

```c
void setFileName();

void fileStatistics();

void searchWord();

void completeReport();
```

You may create additional helper functions.

For example:

```c
int countCharacters();
int countWords();
int countLines();
int countWordOccurrences();
```

You are free to design your own function structure.

---

# Suggested Libraries

You may need:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
```

Only include libraries that you actually need.

---

# Milestones

Complete the project step by step.

---

## Milestone 1 — Open and Read a File

Create a program that:

1. Accepts a filename.
2. Opens the file.
3. Checks whether it opened successfully.
4. Reads the contents.
5. Closes the file.

### Checkpoint

Test with:

```text
sample.txt
```

Also test with a filename that does not exist.

Expected behavior:

```text
Unable to open file.
```

---

# Milestone 2 — Count Characters

Implement character counting.

Test using a small file where you can manually count the characters.

### Questions

Decide:

- Are spaces counted?
- Are newline characters counted?
- Are tabs counted?

Write your decision in the project algorithm.

---

# Milestone 3 — Count Words

Implement word counting.

Use whitespace to determine word boundaries.

Test:

```text
Hello world
C programming
```

Expected word count:

```text
4
```

Also test:

```text
Hello     world
```

and confirm that multiple spaces do not incorrectly create multiple words.

---

# Milestone 4 — Count Lines

Implement line counting.

Test files containing:

```text
One line
```

Then:

```text
First line
Second line
Third line
```

Also test an empty file.

---

# Milestone 5 — Search for a Word

Ask the user for a word and search the file.

Test:

```text
programming
```

and:

```text
PROGRAMMING
```

Observe the difference if your search is case-sensitive.

---

# Milestone 6 — Count Occurrences

Modify the search functionality so that it counts every occurrence of the complete word.

Example:

```text
C is powerful.
C is portable.
C is widely used.
```

Searching for:

```text
C
```

should produce:

```text
Occurrences: 3
```

---

# Milestone 7 — Complete Report

Combine:

- File name
- Character count
- Word count
- Line count
- Search word
- Search result

into one report.

---

# Milestone 8 — Improve Error Handling

Handle situations such as:

- File does not exist
- File cannot be opened
- Empty filename
- Empty file
- Search word not found

Your program should display useful messages instead of crashing.

---

# Testing Requirements

Test at least the following cases:

| Test | Input/Action | Expected Result |
|---|---|---|
| 1 | Existing file | File opens |
| 2 | Invalid filename | Error message |
| 3 | Empty file | Appropriate statistics |
| 4 | One-line file | Correct line count |
| 5 | Multiple-line file | Correct line count |
| 6 | Multiple spaces | Correct word count |
| 7 | Search existing word | Correct occurrence count |
| 8 | Search missing word | Not-found message |
| 9 | Upper/lower case variation | Behavior matches specification |
| 10 | Punctuation around words | Behavior documented |

---

# Sample Data

Create a file called:

```text
sample.txt
```

Use:

```text
C programming is useful.
Programming teaches problem solving.
C is used to build efficient programs.
File handling is an important part of C programming.
Practice makes programming skills stronger.
```

Use this file to test your program.

---

# Manual Analysis Exercise

Before running your program, manually estimate:

- Number of lines
- Number of words
- Number of occurrences of `programming`
- Number of occurrences of `C`

Then compare your results with your program.

This helps you verify whether your implementation is correct.

---

# Challenge Tasks

Once the basic requirements are complete, try these extensions.

---

## Challenge 1 — Case-Insensitive Search

Allow:

```text
programming
Programming
PROGRAMMING
```

to be treated as the same word.

Add a menu option or configuration such as:

```text
1. Case-sensitive search
2. Case-insensitive search
```

---

# Challenge 2 — Search Multiple Words

Allow the user to search for several words.

Example:

```text
Enter word 1: C
Enter word 2: programming
Enter word 3: file
```

Display the occurrence count for each word.

---

# Challenge 3 — Most Frequent Word

Find the word that occurs most frequently in the file.

Example:

```text
Most Frequent Word : programming
Occurrences         : 4
```

You will need to think carefully about how to store and compare words.

---

# Challenge 4 — Longest Line

Find and display the longest line in the file.

Example:

```text
Longest Line Length : 62
```

---

# Challenge 5 — Save Report

Save the complete report to:

```text
file_report.txt
```

Example:

```text
File Name      : sample.txt
Characters     : 245
Words          : 42
Lines          : 5
Search Word    : programming
Occurrences    : 4
```

---

# Challenge 6 — Multiple Files

Allow the user to analyze multiple files without restarting the program.

Example:

```text
File 1: sample.txt
File 2: notes.txt
File 3: program.txt
```

---

# Coding Guidelines

Follow these practices:

1. Use meaningful variable names.
2. Divide the program into functions.
3. Check the result of `fopen()`.
4. Close every file after use.
5. Avoid unnecessary global variables.
6. Keep file-processing logic separate from menu logic.
7. Add comments where necessary.
8. Test each function independently.
9. Document assumptions about characters, words, and lines.
10. Keep the output easy to read.

---

# Important Questions

Before completing the project, make sure you can answer:

1. What does `fopen()` return?
2. Why should you check the result of `fopen()`?
3. What is the difference between reading a file character by character and line by line?
4. How do you identify the beginning and end of a word?
5. How do whitespace characters affect word counting?
6. How should an empty file be handled?
7. What is the difference between searching for a substring and searching for a complete word?
8. How would you make the search case-insensitive?

---

# Submission Requirements

Submit:

## 1. Source Code

```text
file_search.c
```

## 2. Sample Input File

```text
sample.txt
```

## 3. Test Evidence

Provide screenshots showing:

- Successful file opening
- Invalid filename handling
- File statistics
- Successful word search
- Word-not-found case
- Complete report

## 4. Algorithm

Submit a short algorithm explaining:

- Character counting
- Word counting
- Line counting
- Word searching
- Occurrence counting

## 5. Reflection

Answer:

1. How did you count characters?
2. How did you identify words?
3. How did you count lines?
4. How did you make sure a complete word was being searched?
5. What happens when the file does not exist?
6. What was the most difficult part of the project?
7. Which improvement would you implement next?

---

# Completion Checklist

Before submitting, confirm:

- [ ] Filename input implemented
- [ ] File opening implemented
- [ ] File error handling implemented
- [ ] Character counting completed
- [ ] Word counting completed
- [ ] Line counting completed
- [ ] Word search completed
- [ ] Occurrence counting completed
- [ ] Complete report completed
- [ ] Empty file tested
- [ ] Invalid filename tested
- [ ] Missing word tested
- [ ] Case behavior tested
- [ ] Punctuation behavior tested
- [ ] Functions used appropriately
- [ ] Code commented
- [ ] Sample file included
- [ ] Screenshots included
- [ ] Algorithm submitted
- [ ] Reflection completed

---

# Expected Learning Outcome

After completing this project, you should be able to create a C program that analyzes the contents of a text file.

You should understand how to:

- Read text files
- Process characters
- Identify words
- Count lines
- Search for complete words
- Generate a file-analysis report
- Handle common file errors
- Organize file-processing logic into reusable functions