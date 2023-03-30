//print all character before the first blank in the data;

#include<stdio.h>

int main() {
    printf("Enter Data : ");
    char ch;

    while ((ch = getchar()) != ' ' && ch != '\t' && ch != '\n'){
        printf("%c",ch);
    }

    return 0;
}