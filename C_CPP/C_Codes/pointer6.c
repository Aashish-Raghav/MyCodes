//maximum number between two using pointers
#include<stdio.h>

void maxi(int,int,int *max);

int main() {
    int a= 12,b = 15;
    int max;
    maxi(a,b,&max);
    printf("maximum of %d and %d is %d",a,b,max);
    return 0;
}

void maxi(int a,int b,int *max) {
    if (a > b) *max = a;
    else *max = b;
}