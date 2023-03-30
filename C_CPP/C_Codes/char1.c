// read the first character in the data, print it its code and the value of EOF
#include<stdio.h>
int main(){
    printf("Enter data : ");
    char ch = getchar();                // returns int value
    printf("%c is the first character \n its code is %d \n",ch,ch);
    printf("The value of EOF is : %d",EOF);     // here d is specification
    return 0;
}