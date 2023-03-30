//  2 2022--> 29 days
//  2 2021--> 28 days
#include<stdio.h>

int main() {
    int m,y;
    printf("Enter Month and Year : ");
    scanf("%d %d",&m,&y);
    
    if (m<1 || m>12){
         printf("Invalid Month");
    } else if (m==4 || m==6 || m==9 || m==11) {
         printf("30 Days");
    } else if ( m==2) {
        if (y%4==0 && y%100!=0){
            printf("leap year , 29 Days");
        } else if (y%400==0){
            printf("leap year, 29 Days");
        } else {
            printf("not leap year,28 Days");
        } 
    } else {
            printf("31 Days");
    }
    return 0;

}