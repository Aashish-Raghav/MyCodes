// if s < n deficient no.    s: sum of divisors  n: number itself
#include<stdio.h>
int sumDivisors(int);
int main() {
    int num,sumd;
    printf("Enter No.(0 to end) : ");
    scanf("%d",&num);
    while ( num != 0 ){
        sumd = sumDivisors(num);
        if (sumd < num) printf("%d is deficient\n\n",num);
        else if (sumd == num) printf("%d is perfect\n\n",num);
        else printf("%d is abundant\n\n ",num);
        printf("Enter No.(0 to end) : ");
        scanf("%d",&num);
    }
    return 0;
}

int sumDivisors(int num){
    int sumd = 0;                   //sumd : sum of divisors including 1 but not the no.
    for (int i=1;i <= num/2;i++) {
        if ( num % i == 0) sumd += i;
    }
    return sumd;
}