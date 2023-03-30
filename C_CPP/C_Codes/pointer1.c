//basic pointers;
#include<stdio.h>
int main() {
    int age = 10;
    int *ptr = &age;
    int _age = *ptr;
    // values   * : value at address
    printf("age = %d\n",age);
    printf("*ptr = %d\n",*ptr);
    printf("_age(*&age) = %d\n\n",_age);

    // address     & : address of 
    printf("&age = %u\n",&age);
    printf("ptr = %u\n",ptr);
    printf("&ptr = %u\n",&ptr);
    return 0;
}