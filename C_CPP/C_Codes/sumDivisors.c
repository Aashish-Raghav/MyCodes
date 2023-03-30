// sum of divisors including 1 but not the no.  .....

#include<stdio.h>
int sumDivisors(int);
int main() {
    int num;
    printf("Enter no. : ");
    scanf("%d",&num);
    printf("Sum of exact divisors of %d is %d",num,sumDivisors(num));
    return 0;
}

int sumDivisors(int num){
    int sumd = 0;                   //sumd : sum of divisors including 1 but not the no.
    for (int i=1;i <= num/2;i++) {
        if ( num % i == 0) sumd += i;
    }
    return sumd;
}