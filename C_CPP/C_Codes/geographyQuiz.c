#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MaxLength 50

void askOneQuestion(char[],char[],char[]);
void getString(FILE * in,char[]);
void lettersOnlyUpper(char[],char[]);

int main() {
    char country[MaxLength + 1],capital[MaxLength + 1],CAPITAL[MaxLength + 1];
    char EndOfData[] = "*";
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\quizData.txt","r");
    if (in == NULL) {
        printf("Cannot Find File\n");
        exit(1);
    }
    getString(in,country);
    while (strcmp(country,EndOfData) != 0) {
        getString(in,capital);
        getString(in,CAPITAL);
        askOneQuestion(country,capital,CAPITAL);
        getString(in,country);
    }

    return 0;
}

void askOneQuestion(char country[],char capital[],char CAPITAL[]){
    char ans[MaxLength + 1],ANS[MaxLength + 1];
    printf("\nWhat is the capital of %s ? ",country);
    gets(ans);
    letterOnlyUpper(ans,ANS);
    if (strcmp(ANS,CAPITAL) == 0) printf("Correct!\n");
    else {
        printf("Wrong. Try Again \n");
        printf("\nWhat is the Capital of %s ?",country);
        gets(ans);
        letterOnlyUpper(ans,ANS);
        if (strcmp(ANS,CAPITAL) == 0 ) printf("Correct\n");
        else printf("Wrong.Answer is %s\n",capital);

    }
}

void getString(FILE * in,char str[]) {
    char ch,del;
    int i = 0;
    while (isspace(ch = getc(in)));
    if (ch == EOF) return;

    del = ch;
    while (((ch = getc(in)) != del) && (ch != EOF)){
        str[i++] = ch;
    }
    str[i] = '\0';
}

void letterOnlyUpper(char ans[],char ANS[]){
    char ch;
    int i = 0,j = 0;
    ch = ans[i++];
    while (ch != '\0') {
        if (isalpha(ch)) ANS[j++] = toupper(ch);   
        ch = ans[i++]; 
    }
    ANS[j] = '\0';
}