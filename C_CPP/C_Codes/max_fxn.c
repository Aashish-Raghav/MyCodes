//create a fxn to find max of two double values till the user inputs 0 0 ;
#include<stdio.h>
double max(double a , double b);
int main() {
    printf("Enter two Numbers : ");
    double a ,b;
    scanf("%lf %lf",&a,&b);
    while ((a != 0) || (b != 0)){
        printf("Bigger No. is %1.2f \n\n",max(a,b));
        printf("Enter two Numbers :");
        scanf("%lf %lf",&a,&b);
    }
}
double max(double a,double b) {
    if (a > b) return a;
    else return b;
}