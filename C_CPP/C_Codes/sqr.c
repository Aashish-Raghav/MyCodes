#include<stdio.h>
int sqr(int);

int main() {
    int num;
    printf("Enter a Num. : ");
    scanf("%d",&num);
    printf("Square of %d is %d ",num,sqr(num));
    return 0;
}

int sqr(int num) {
    return num*num;
}