// this program prints the data from a file numbering the lines;
#include<stdio.h>

int main () {
    char ch;
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\char7.txt","r");
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\char7_result.txt","w");
    int lineNo = 0 ,writeLineNo = 1;
    while ((ch = getc(in)) != EOF){
        //1 to print on screen;
        if (writeLineNo) {
            printf("%2d. ",++lineNo);
            writeLineNo = 0;
        }
        putchar(ch);
        if (ch == '\n') writeLineNo = 1;
        
/*       //2 to print in file;
        if (writeLineNo) {
            fprintf(out,"%2d. ",++lineNo);
            writeLineNo = 0;
        }
        fputc(ch,out);
        if (ch == '\n') writeLineNo = 1;
     */   
    }
    fclose(in);
    return 0;
}

