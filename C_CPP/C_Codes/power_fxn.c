#include<stdio.h>
double power(double,int);
int main() {
    int n;
    double x;
    printf("Enter a number and power raise to (x,n) : ");
    scanf("%lf %d",&x,&n);
    printf("%1.2f raise to %d = %1.2f",x,n,power(x,n));
    return 0;
}
double power(double x,int n) {
    double pnum = 1;
    for (int i=1;i <=n;i++){
        pnum *= x;
    }
    return pnum;
}