//read characters until it finds a digit , the first of the integer 
// having found the first digit,it must construct a integer as long as it gets the integer;

#include<stdio.h>

int main() {
    char ch;
    int num,value=0;
    printf("Enter Data : ");
    while ((ch = getchar()) < '0' || ch > '9');
    
    do {
        num = ch - '0';
        value = value*10 + num;   //NOTE : no need of variable num directly value = value * 10  + ch - '0'
    } while ((ch = getchar()) >= '0' && ch <= '9');

    printf("%d",value + 1);

    return 0;
}