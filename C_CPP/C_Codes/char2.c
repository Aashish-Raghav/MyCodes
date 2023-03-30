// read and print the first 3 characters in the data

#include<stdio.h>

int main() {
    printf("Enter data : ");
    for (int i = 1;i<=3;i++) {
        char ch = getchar();
        printf("character %d is %c \n",i,ch);
    }

    return 0;
}