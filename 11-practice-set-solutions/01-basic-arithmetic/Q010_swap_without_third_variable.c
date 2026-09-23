/*
Q10: Swap Without Third Variable

EXPLANATION:
For integer inputs, arithmetic can exchange the values without a third variable.

ALGORITHM:
Read a,b; a=a+b; b=a-b; a=a-b; print.

SOURCE NOTE / ASSUMPTIONS:
The PPT only specifies the technique, not overflow behavior; this version assumes values whose sum fits in long long.
*/

#include <stdio.h>
int main(void){ long long a,b; scanf("%lld%lld",&a,&b); a=a+b; b=a-b; a=a-b; printf("%lld %lld\n",a,b); return 0; }
