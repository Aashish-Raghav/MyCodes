// replace all { } with {* *} respectively from text file char12.txt to char12_results.txt;

#include<stdio.h>
int main() {
    char ch;
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\char12_result.txt","w");
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\char12.txt","r");
    while ((ch = getc(in)) != EOF){
        if (ch == '{') {
            putc(ch,out);
            fprintf(out,"%c",'*');
            ch = getc(in); 
        }
        if (ch == '}') {
            fprintf(out,"%c",'*');
            putc(ch,out);
            ch = getc(in);
        }
        putc(ch,out);
    }
    return 0;
}