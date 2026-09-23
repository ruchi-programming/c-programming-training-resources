/*
Q8: Discount Calculation

EXPLANATION:
Compute amount = quantity×unit price, then subtract 20% discount.

ALGORITHM:
Read item number, quantity and unit price; compute gross; discount=gross×0.20; print net.
*/

#include <stdio.h>
int main(void){ int item,qty; double price,gross,discount,net; scanf("%d%d%lf",&item,&qty,&price); gross=qty*price; discount=.20*gross; net=gross-discount; printf("Item: %d\nGross: %.2f\nDiscount: %.2f\nNet: %.2f\n",item,gross,discount,net); return 0; }
