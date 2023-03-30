#include<stdio.h>

int main() {
    int a,b,c,d,e,f,g,year;
    printf("Enter Year [1900,2099] : ");
    scanf("%d",&year);                          // Segmentation fault

    //the following algorithm id given in question;

    a = year-1900;
    b = a % 19;
    c = (7*b+1) / 19;
    d = (11*b+4-c) % 29;
    e = a / 4;
    f = (a+ e + 31 -d) % 7;
    g = 25 - (d +  f);

    if (year <= 1900 || year >= 2099 ) {
        printf("Please Input Year from range 1900-2099");
    } else {
        if (g <= 0) {
            printf("\n Month : March \n Day : %d",31 + g);
        } else {
            printf("\n Month : April \n Day : %d",g);
        }
    }
    return 0;

}