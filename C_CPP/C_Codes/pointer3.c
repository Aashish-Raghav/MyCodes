//_square fxn call by refrence;
//square fxn call by value;

#include<stdio.h>
void square(int);
void _square(int *n);
int main() {
    int num= 12;
    square(num);
    printf("Number is %d\n\n",num);
    _square(&num);
    printf("Number is %d\n\n",num);
    return 0;
}

void square(int n) {
    n = n*n;                            //call by value
    printf("Square is %d\n",n);
}

void _square(int *n){
    *n = (*n) * (*n);                  //call by refrernces
    printf("Square is %d\n",*n);
    
}