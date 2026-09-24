/*
Q24: Square or Cube

EXPLANATION:
Even numbers are squared; odd numbers are cubed.

ALGORITHM:
Read n; use parity to choose n² or n³.
*/

#include <stdio.h>
int main(void){ 
    long long n; 
    scanf("%lld",&n); 
    if(n%2==0) 
        printf("%lld\n",n*n); 
    else 
        printf("%lld\n",n*n*n); 
        return 0; 
}
