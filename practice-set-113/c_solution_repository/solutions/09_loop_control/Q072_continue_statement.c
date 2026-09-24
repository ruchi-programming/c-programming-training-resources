/*
Q72: Continue Statement

EXPLANATION:
Skip faulty readings using continue.

ALGORITHM:
Read n readings; if a reading is marked faulty, skip processing it.

SOURCE NOTE / ASSUMPTIONS:
The PPT does not define what makes a reading faulty; this version treats negative readings as faulty.
*/

#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x<0)
            continue;
        printf("%d ",x);
    }
    putchar('\n');
    return 0;
}
