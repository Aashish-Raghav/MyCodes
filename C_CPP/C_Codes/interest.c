//4% <5000  5% 5-10k  6% 10-20k  7% >20k

#include<stdio.h>

int main() {
    double amt;             //amount
    printf("Enter amount : ");
    scanf("%lf",&amt);                      // Segmentation Fault;
    printf("%f",amt);

    if (amt >= 0 && amt < 5000){
        printf("\nInterest : %1.2f",amt*0.04);
    } else if (amt >= 5000 && amt < 10000) {
        printf("\nInterest : %1.2f",amt*0.05);
    } else if (amt >= 10000 && amt < 20000) {
        printf("\nInterest : %1.2f",amt*0.06);
    } else if (amt >= 20000) {
        printf("\nInterest : %1.2f",amt*0.07);
    } else {
        printf("\nInvalid Amount Input!");
    }
    
    return 0;
}