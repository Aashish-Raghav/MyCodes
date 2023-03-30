//copy data from copy.txt and paste it to text file paste.txt;
#include<stdio.h>
#include<string.h>

int main() {
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\copy.txt","r");
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\paste.txt","w");
    char ch[50];
    fscanf(in,"%s",ch);         //NOTE : here we didn't use &

    while (strcmp(ch,"END") != 0) {
        strcat(ch," ");
        fprintf(out,"%s",ch);
        fscanf(in,"%s",ch);
    }
    printf("Your Data Processed Successfully");
    return 0;
}