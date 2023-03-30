// input an even no >4 and print all possible prime pairs sum = no.
//eg  22:  11 11     19 3     5 17
#include<stdio.h>
int isPrime(int);

int main() {
    int num,a=0;
    printf("Enter a even no.(>4) : ");
    scanf("%d",&num);
    if (num % 2 != 0) printf("Invalid Input. \n");
    else {
        for (int i=1,j=num-1;i <= num/2,j>=num/2;i++,j--) {
            if (isPrime(i) && isPrime(j)) {
            printf("%d %d\n",i,j);
            a=1;
            }
        }
    }
    if (a=0) printf("No possible pair exist! \n");
    return 0;
}
int isPrime(int num) {
    int a = 0;
    if (num == 1) a=1;
    else {
        for (int i = 2;i <= num/2;i++) {
        if ( num%i == 0) a=1;
        }
    }
    return a==0;
}