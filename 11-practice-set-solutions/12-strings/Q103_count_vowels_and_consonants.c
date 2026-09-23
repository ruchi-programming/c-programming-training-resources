/*
Q103: Count Vowels and Consonants

EXPLANATION:
Traverse a string and classify alphabetic characters.

ALGORITHM:
For each alphabetic character, test vowel set; otherwise count consonant.
*/

#include <stdio.h>
#include <ctype.h>
int main(void){char s[500];fgets(s,sizeof s,stdin);int v=0,c=0;for(int i=0;s[i];i++){char x=(char)tolower((unsigned char)s[i]);if(x>='a'&&x<='z'){if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')v++;else c++;}}printf("Vowels: %d\nConsonants: %d\n",v,c);return 0;}
