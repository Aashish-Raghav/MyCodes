#include<stdio.h>
int factorail(int);
int combination(int,int);

int main() {
    int n,r,nCr;
    printf("Enter values for n and r (nCr) : ");
    scanf("%d %d",&n,&r);
    while ( n != 0 ) {
        printf("There is %d combinations of %d objects taken %d at a time \n\n",combination(n,r),n,r);
        printf("Enter values for n and r (nCr) : ");
        scanf("%d %d",&n,&r);
    }
    return 0;
}

int factorial(int num){
    int fact = 1 ;
    for (int i = 1; i <= num ; i++){
        fact *= i;
    } return fact;
}

int combination(int n,int r){
    return factorial(n) / ( factorial(n-r) * factorial(r) );

}