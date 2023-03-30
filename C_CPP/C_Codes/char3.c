// read and print the first non - blank character in the data
// count the number of blanks before the first non blank character

#include<stdio.h>
int main() {
    int numblank = 0 ;           // numblank : number of blank;
    printf(" Enter Data : ");
    char ch;
    while ((ch = getchar()) == ' ' || (ch == '\t') || (ch == '\n')) {
        ch == '\t' ? numblank+=4 : numblank++;  
    }  

         // IMP : blank char can be tab space or newline.
        
    printf("First non - blank character is %c ",ch);
    printf("No of blanks is : %d",numblank);


}