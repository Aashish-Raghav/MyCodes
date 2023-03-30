//percent increse & decrease in price;
/*Problem 1:
Percent sign not coming in line 16 and 18*/

#include<stdio.h>

int main() {
    char item[50];
    printf("Enter Item Name : ");
    gets(item);

    double pprice,cprice;     //Previous Price & Current Price
    printf("\nEnter Previous Price & Current Price : ");
    scanf("%lf %lf",&pprice,&cprice);

    if (cprice > pprice) {
        printf("\nIncrease Of %1.2lf \% in %s price ",(cprice-pprice)/pprice*100,item);
    } else{
        printf("\nDecrease of %1.2lf \% in %s price ",(pprice-cprice)/pprice*100,item);
    }
    
    return 0;
}