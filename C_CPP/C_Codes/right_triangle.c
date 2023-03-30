#include<stdio.h>
int triangle(int,int,int);
int main() {
    int arr[3];
    for (int i=0;i<3;i++) {
        printf("Enter side%d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n\n%d",triangle(arr[0],arr[1],arr[2]));
    return 0;
}
int triangle(int a,int b,int c){
    return (a*a == b*b + c*c) || (b*b == a*a + c*c) || (c*c == a*a + b*b);
}