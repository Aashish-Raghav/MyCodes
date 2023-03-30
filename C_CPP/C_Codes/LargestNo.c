// Largest of any no  of numbers entered by users;

#include<stdio.h>

int main () {
    double num,lnum;
    printf("Enter a number (0 to end) : ");
    scanf("%lf",&num);
    lnum=num;

    while (num!=0) {
        printf("Enter a number (0 to end) : ");
        scanf("%lf",&num);

        if (num > lnum ) lnum = num;
    }
    printf("Largest No. : %1.2lf",lnum);

    return 0;
}