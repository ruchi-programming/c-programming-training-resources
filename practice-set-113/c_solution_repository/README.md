# C Programming — Complete Solution Repository

This repository is based on the uploaded **C Programming — Practice Questions** slide deck. The deck defines a prerequisite-based progression from basic input/arithmetic through conditions, loops, patterns, arrays, strings, matrices, and functions, covering classroom questions **Q1–Q113**. fileciteturn0file0L99-L125

## What is included

- **113 classroom solutions (Q1–Q113)**
- One standalone `.c` program per question
- Explanation and algorithm at the top of every source file
- Category folders matching the source progression
- Category README files listing the questions
- Root index and compile/run guidance
- An `external_practice/` note for named HackerRank/HackerEarth/LeetCode items where the slide deck does not contain enough full problem details to reproduce an exact platform submission

The source explicitly organizes the classroom progression as Q1–Q13 basic programming, Q14–Q45 decision making, Q46–Q52 number problems, Q53–Q69 patterns, Q70–Q85 loop-control/number problems, Q86–Q92 arrays, Q93–Q104 strings, Q105–Q108 2-D arrays/matrices, and Q109–Q113 functions. fileciteturn0file0L1136-L1187

## Folder structure

```text
solutions/
  01_basic_arithmetic/
  02_decision_making/
  03_switch_case/
  04_conditional_operator/
  05_number_theory_loops/
  06_number_patterns/
  07_star_patterns/
  08_character_patterns/
  09_loop_control/
  10_number_manipulation/
  11_arrays/
  12_strings/
  13_matrices/
  14_functions/
external_practice/
```

## How to compile

Use GCC:

```bash
gcc solutions/01_basic_arithmetic/Q001_sum_of_two_numbers.c -o q1
./q1
```

For programs using the math library (`sqrt`, `pow`), use:

```bash
gcc file.c -o program -lm
```

Each source file is intended to be compiled independently.

## How to study

For each question:

1. Read the **EXPLANATION** comment.
2. Read the **ALGORITHM** and explain it in your own words.
3. Try writing the code without looking.
4. Compile and test with your own inputs.
5. Compare your implementation with the repository solution.
6. Move to the next question only after you can explain the approach.

This follows the source deck's prerequisite-based learning rule. fileciteturn0file0L64-L92

## Important source limitations

The slide deck gives complete enough descriptions for the classroom questions, but some questions do not specify exact input formats, thresholds, menu numbers, or business rules. In those cases, the repository **marks the assumption explicitly inside the `.c` file** instead of presenting it as if it came from the source.

Examples include:
- Q11 employee count/input format
- Q19 nationality representation
- Q25 course-mark cut-offs
- Q32–Q34 menu numbering
- Q40 electricity slab rates
- Q41–Q42 grade/salary thresholds
- Q72 definition of a faulty reading
- Q73 demonstration credentials

The external-platform section is deliberately not fabricated: the slide deck names problems such as HackerRank conditionals/loops, HackerEarth string/array practice, and LeetCode Two Sum/Two Sum II, but the repository only gives exact standalone submissions where the source supplies enough detail. The deck itself lists these external-practice items and their intended prerequisites. fileciteturn0file0L1060-L1075

## External practice listed by the source

- HackerRank: Sum and Difference of Two Numbers
- HackerRank: Hello World! in C
- HackerRank: Playing With Characters
- HackerRank: Conditional Statements in C
- HackerRank: For Loop in C
- HackerRank: Sum of Digits of a Five Digit Number
- HackerRank: Printing Pattern Using Loops
- HackerRank: Students' Marks Sum
- HackerRank: Functions in C
- HackerEarth: Array Sum
- HackerEarth: Make Palindrome
- HackerEarth: Vowel Counting
- LeetCode #1: Two Sum
- LeetCode #167: Two Sum II

The deck's external ladder places these after the related classroom concepts. fileciteturn0file0L1060-L1073
