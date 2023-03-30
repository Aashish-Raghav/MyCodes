// lowercase to uppercase conversion    -32

#include<stdio.h>

int main() {
    char ch;
    int num = 'a' - 'A';
    printf("Enter a lowercase alphabet  : ");
    scanf("%c",&ch);

    printf("%c corresponding uppercase is %c",ch,ch - num);

    return 0;
}