// read the entered data and print the first digit that comes;
#include<stdio.h>

int main() {
    char ch;
    printf("Enter Data : ");
    do{
        ch = getchar();
    } while ( (ch = getchar()) < '0' || ch > '9');
    printf("First digit is : %c",ch);
    //  Or   putchar(ch);


    return 0;
}