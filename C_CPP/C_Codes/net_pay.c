#include <stdio.h>

int main() {
    char name[50];
    printf("Enter your name : ");
    gets(name);
    
    double hwork,hrate,trate,gpay;
    printf("\nEnter hours worked,hour rate, Tax rate : ");
    scanf("%lf %lf %lf",&hwork,&hrate,&trate);
    
    gpay=hwork*hrate;
    printf("\nName : %s",name);
    printf("\nGross Pay : %1.2f",gpay);
    printf("\nTax Deducted : %1.2f",0.8*trate*gpay/100);
    printf("\nNet Pay : %1.2f",gpay-0.8*trate*gpay/100);
    return 0;
}