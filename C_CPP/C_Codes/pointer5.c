// take multiple values from the fxn;
//Note : fxn returns only single value;
// take two values and return sum,product,average;
#include<stdio.h>
void doWork(int,int,int *sum,int *product,int *average);
int main() {
    int a=12,b=24,sum,product,average;
    doWork(a,b,&sum,&product,&average);
    printf("sum = %d\n",sum);
    printf("Product = %d\n",product);
    printf("average = %d\n",average);
    return 0;
}
void doWork(int a,int b,int *sum,int *product,int *average){
    *sum = a+b;
    *product = a*b;
    *average = (a+b)/2; 
}