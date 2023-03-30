#include <stdio.h>
int main() {
    int kg1,g1,kg2,g2,nkg,ng;
    printf("Enter weight1 in kg and gram : ");
    scanf("%d %d",&kg1,&g1);
    
    printf("\nEnter weight2 in kg and gram ; ");
    scanf("%d %d",&kg2,&g2);
    
    ng=(g1+g2)%1000;
    nkg=kg1+kg2+(g1+g2)/1000;
    
    printf("\nSum of given weights is %d Kg %d gram",nkg,ng);
    
    return 0;
}