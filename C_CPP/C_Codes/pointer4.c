//  Swapping Function;
#include<stdio.h>
void swap(int *a,int *b);
int main() {
    int x=5,y=7;
    printf("Before Swapping\nx = %d \t y = %d\n\n",x,y);
    swap(&x,&y);
    printf("After Swapping\nx = %d \t y = %d",x,y);
    return 0;
}
void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}