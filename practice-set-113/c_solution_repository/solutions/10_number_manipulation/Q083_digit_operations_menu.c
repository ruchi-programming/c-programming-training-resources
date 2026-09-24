/*
Q83: Digit Operations Menu

EXPLANATION:
Repeatedly count, sum, or reverse digits until exit.

ALGORITHM:
Read a choice; perform the corresponding digit operation; loop until exit.

SOURCE NOTE / ASSUMPTIONS:
The PPT does not specify menu numbers; this version uses 1=count, 2=sum, 3=reverse, 4=exit.
*/

#include <stdio.h>
long long rev(long long n){long long r=0;while(n){r=r*10+n%10;n/=10;}return r;}
int main(void){int ch;long long n;do{scanf("%d",&ch);if(ch==4)break;if(ch<1||ch>4){puts("Invalid choice");continue;}scanf("%lld",&n);long long t=n<0?-n:n;if(ch==1){int c=0;do{c++;t/=10;}while(t);printf("%d\n",c);}else if(ch==2){long long s=0;while(t){s+=t%10;t/=10;}printf("%lld\n",s);}else if(ch==3)printf("%lld\n",rev(t));}while(1);return 0;}
