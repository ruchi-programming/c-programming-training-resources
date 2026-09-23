/*
Q17: Vowel or Consonant

EXPLANATION:
Classify an alphabetic character as vowel or consonant.

ALGORITHM:
Read a character; compare against vowels; otherwise consonant.

SOURCE NOTE / ASSUMPTIONS:
The PPT does not define handling of non-alphabetic input; this version treats any non-vowel as consonant.
*/

#include <stdio.h>
#include <ctype.h>
int main(void){ char c; scanf(" %c",&c); c=(char)tolower((unsigned char)c); if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') puts("Vowel"); else puts("Consonant"); return 0; }
