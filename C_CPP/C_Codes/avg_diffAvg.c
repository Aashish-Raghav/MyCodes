//find average and difference from average;
// here using array;
#include<stdio.h>
#define MaxNum 100
int main() {
    int a,i=0,num[MaxNum];
    double sum = 0;
    printf("Enter up to %d numbers(0 to end) : \n",MaxNum);
    scanf("%d",&a);

    while (a != 0) {
        num[i++] = a;       // impt using i++ directly within braces;**
        sum = sum + a;
        scanf("%d",&a);
    }
    if ( i == 0 ) printf("No numbers entered. ");
    else {
        printf("\nNumbers entered : %d",i);
        printf("\nSum of numbers : %1.0f\n\n",sum);

        printf("The average is %1.2f\n\n",sum/i);

        printf("Numbers and differences from average\n");
        for (int j=0; j< i;j++) {
            printf("%4d %6.2f\n",num[j],num[j]-(sum/i));
        }

    }
    num[101] = 12;
    printf("%d ",num[101]);
    

    return 0;
}