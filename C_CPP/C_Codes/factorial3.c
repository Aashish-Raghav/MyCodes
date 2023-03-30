// through recursion;
#include<stdio.h>
int factorial(int);
int main() {
    int num;
    printf("Enter num : ");
    scanf("%d",&num);
    while (num != 0) {
        printf("Factorial of %d is %d\n\n",num,factorial(num));
        printf("Enter num : ");
        scanf("%d",&num);    
    }
    return 0;
}
int factorial(int num){
    if (num == 1) {
        return 1;
    }    
    int factorialNm1 = factorial(num -1);   //factorialNm1 ; factorial n - 1 ( n minus one)
    int factorialN = factorialNm1 * num;  
    return factorialN;
}