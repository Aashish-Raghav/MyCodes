// char is alpha(upper,lower),digit,special symbol

#include<stdio.h>
int isUppercase(char);
int isLowercase(char);
int isDigit(char);
int isalpha(char);
int main() {
    printf("Enter a character : ");
    char ch = getchar();
    if (isalpha(ch)) {
        printf("%c is a alphabet\n",ch);
        isUppercase(ch) ? printf("Uppercase\n"): printf("Lowercase");
    } else if (isDigit(ch)) printf("%c is a digit.",ch);
    else printf("%c is a special symbol",ch);
    return 0;
}
int isUppercase( char ch ) {
    return ( ch >= 'A' && ch <= 'Z');
}
int isLowercase( char ch ) {
    return ( ch >= 'a' && ch <= 'z');
}
int isalpha( char ch) {
    return isUppercase(ch) || isLowercase(ch) ;
}
int isDigit(char ch) {
    return ( ch >= '0' && ch <= '9' );
}