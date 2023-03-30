// Average of any no  of numbers entered by users;

#include<stdio.h>

int main () {
    double sum=0,num,i=0;
    printf("Enter a number (0 to end) : ");
    scanf("%lf",&num);

    while (num!=0) {
        sum=sum+num;
        i++;
        printf("Enter a number (0 to end) : ");
        scanf("%lf",&num);
    }

    i==0 ? printf("Average : 0") : printf("Average : %1.2lf",sum/i);
}