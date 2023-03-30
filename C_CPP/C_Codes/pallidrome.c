#include<stdio.h>
#include<string.h>
#include<ctype.h>

int pallidrome(char string[]);
void SimpleString(char string[],char newstr[]);

int main() {
    char string[100];
    char newstr[100];
    printf("Enter a string (press enter to end) : ");
    gets(string);
    while (strcmp(string,"")) {
        SimpleString(string,newstr);
        if (pallidrome(newstr)) printf("Pallidrome.\n");
        else printf("Not Pallidrome\n");
        printf("Enter a string (press enter to end) : ");
        gets(string);
    }
}

int pallidrome(char string[]) {
    for (int i=0,j = strlen(string)-1;i < j ; i++,j--) {
        if (string[i] != string[j]) return 0;
    }
    return 1;
}

void SimpleString(char string[],char newstr[]) {
    int h = 0,i= 0 ;
    char c = string[i];
    while ((c = string[i++]) != '\0') {
        if (isalpha(c)) newstr[h++] = tolower(c);
    }
    newstr[h] = '\0';
    
    //printf("\n%s\n",newstr);
}