//check whether triangle is right angled or not using pointer,first find hypotenuse from three sides ;
#include<stdio.h>
void sides(int,int,int,int *h,int *b,int *a);
int triangle(int,int,int);
int main() {
    int x=16,y=5,z=13,h,b,a;
    sides(x,y,z,&h,&b,&a);
    printf("%d",triangle(h,b,a));
    return 0;
}
void sides(int x,int y,int z,int *h,int *b,int *a) {
    if (x > y && x > z) {
        *h = x;
        *b = y;
        *a = z;
    }
    else if (y > z && y > x) {
        *h = y;
        *b = x;
        *a = z;
    }
    else {
        *h = z;
        *b = x;
        *a = y;
    }
}

int triangle(int h,int a,int b){
    return h*h == a*a + b*b;
}