// Upper to lower case conversion  +32

#include<stdio.h>

int main() {
    char ch;
    int num = 'a' - 'A';
    printf("Enter uppercase alphabet : ");
    scanf("%c",&ch);
    printf("%c corresponding lowercase is %c",ch,ch + num);

    return 0;
}