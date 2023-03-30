// through fxn;
#include<stdio.h>
int factorial(int);

int main() {
    int num;
    printf("Enter a no.(0 to end) : ");
    scanf("%d",&num);
    while ( num != 0 ) {
        printf("Factorial of %d is %d\n\n",num,factorial(num));
        printf("Enter a no.(0 to end) : ");
        scanf("%d",&num);
    } 
    return 0;
}

int factorial(int num){
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact = fact * i;
    }
    return fact;
}