#include<stdio.h>

int main() {
    int h1,m1,h2,m2,mgap,hgap;   //hour,minute
    printf("Enter First time (24 hours) : ");
    scanf("%d %d",&h1,&m1);

    printf("\nEnter second time : ");
    scanf("%d %d",&h2,&m2);

    

    if (h2 > h1) {
        if (m2>m1){
            mgap=m2-m1;         //minute gap
            hgap=h2-h1;         //hour gap
            printf("Time Gap : %d hours %d minutes",hgap,mgap);
        } else {
            mgap=m2-m1+60;         //minute gap
            hgap=h2-h1-1;         //hour gap
            printf("Time Gap : %d hours %d minutes",hgap,mgap);
        }
    }else {
       if (m2>m1){
            mgap=m2-m1;         //minute gap
            hgap=h2-h1+24;         //hour gap
            printf("Time Gap : %d hours %d minutes",hgap,mgap);
        } else {
            mgap=m2-m1+60;         //minute gap
            hgap=h2-h1-1+24;         //hour gap
            printf("Time Gap : %d hours %d minutes",hgap,mgap);
        }
    }




}