/*
Q19: Voting Eligibility

EXPLANATION:
Check eligibility using age and nationality.

ALGORITHM:
Read age and nationality; require age>=18 and an accepted nationality value.

SOURCE NOTE / ASSUMPTIONS:
The PPT does not specify the nationality input representation; this version uses the word 'Indian' (case variants accepted).
*/

#include <stdio.h>
#include <string.h>
int main(void){ int age; char nat[64]; scanf("%d %63s",&age,nat); if(age>=18 && (strcmp(nat,"Indian")==0 || strcmp(nat,"INDIAN")==0 || strcmp(nat,"indian")==0)) puts("Eligible"); else puts("Not Eligible"); return 0; }
