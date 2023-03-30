// count no of characters,blanks,digits in the input line ;
#include<stdio.h>

int main() {
    int numchars=0,numblanks=0;
    printf("Enter Data : ");
    char ch;
    int numDigits = 0,numAlpha = 0;
    while ((ch = getchar()) != '\n'){
        ch == '\t' ? numchars+=4 : numchars++;
        if (ch == ' ') numblanks++;
        else if (ch == '\t') numblanks+=4;
        else if (ch >= '0' && ch <= '9') numDigits++;
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) numAlpha++;

    }
    printf("No. of characters : %d\n",numchars);
    printf("No. of blanks : %d\n",numblanks);
    printf("No of digits : %d\n",numDigits);
    printf("No of alphabets : %d\n",numAlpha);

    return 0;
}