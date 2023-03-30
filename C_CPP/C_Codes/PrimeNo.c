#include<stdio.h>

int main() {
    int num,a=0;
    printf("Enter a number : ");
    scanf("%d",&num);

    for (int i = 2; i <= num/2;i++){
        if ( num % i == 0) a=1;                 //NOTE : MOFULUD OPERATOR works only on integral values
    }
   
    a==1 ? printf("%d is not a Prime No.",num) : printf("%d is Prime No.",num);

    return 0;
}