// read a line of data and find the largest character as per ascii values;

#include<stdio.h>
int main() {
    char ch,bigchar;
    printf("Enter Data : ");
    while ((ch = getchar()) != '\n') {
        if (ch>bigchar) bigchar=ch;
    }
    printf("%c is the largest character with the ascii value %d",bigchar,bigchar);
    return 0;
}