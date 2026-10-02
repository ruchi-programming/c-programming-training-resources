# File Handling Solutions — Q114–Q118

Each standalone C program includes a short explanation/algorithm in its source comments.

| Question | File | Task |
|---|---|---|
| Q114 | q114-student-records.c | Save and read student details |
| Q115 | q115-file-statistics.c | Count characters/bytes, words, and lines |
| Q116 | q116-append-transactions.c | Append transaction records |
| Q117 | q117-copy-file.c | Copy file contents |
| Q118 | q118-search-word.c | Count exact word matches |

Compile from this directory with GCC:
```sh
gcc -std=c11 -Wall -Wextra q114-student-records.c -o q114
```
Repeat with the other source filenames. Run the executable from this directory.

Assumptions: Q114 writes one delimited record to students.txt in write mode;
Q115 counts bytes and whitespace-delimited words, and counts a final line
without a newline; Q116 appends to transactions.txt; Q117 overwrites its
destination and copies in binary mode; Q118 uses case-sensitive exact
whitespace-token matching, with punctuation included in tokens.
