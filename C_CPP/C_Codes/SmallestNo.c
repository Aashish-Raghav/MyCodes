// Smallest of any no  of numbers entered by users;

#include<stdio.h>

int main () {
    double num,lnum;
    printf("Enter a number (0 to end) : ");
    scanf("%lf",&num);
    lnum=num;

    while (num!=0) {
        if (num < lnum ) lnum = num;                  // NOTE :  for largest no can uses it anywhere 
        printf("Enter a number (0 to end) : ");       //       in loop but for smallest have to use it in starting.
        scanf("%lf",&num); 
    }
    printf("Smallest No. : %1.2lf",lnum);

    return 0;
}