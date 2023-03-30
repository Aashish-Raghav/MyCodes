//pointer to pointer;
#include<stdio.h>
int main() {
    int age=20;
    int *ptr = &age;
    int **pptr = &ptr;

    printf("value of age : %d",**pptr); //value of age using pointer to pointer concept;
    return 0;
}