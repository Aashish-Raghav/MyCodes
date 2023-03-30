// copy the text of the file char11.txt and paste it with correct format to file char11_results.txt
#include<stdio.h>

int main() {
    char ch;
    FILE *  in = fopen("E:\\c programming\\C_Codes\\TextFiles\\char11.txt","r");
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\char11_result.txt","w");
    ch = getc(in);
    if (ch >= 'a' &&  ch <= 'z') {
                ch = ch - 32;
    }
    while (ch != EOF){
        putc(ch,out);
        if (ch == '.') {
            while ((ch = getc(in)) == ' ' || ch == '\t');
            if (ch >= 'a' &&  ch <= 'z') {
                ch = ch - 32;
            }
            fprintf(out,"%c",' ');
            putc(ch,out);
        }
    ch = getc(in);    
    }
    return 0;
}