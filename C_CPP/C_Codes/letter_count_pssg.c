// Letter Frequency Count;
//calculate letter and its frequency in passage letter_count.txt, and write in letter_count_results.txt
#include<stdio.h>
#include<ctype.h>
int position(char);

int main() {
    int pos,letterCount[27];
    char c;
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\letter_count.txt","r");
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\letter_count_result.txt","w");

    for (pos = 1; pos< 27;pos++) letterCount[pos] = 0;      //sets letterCount = 0

    while ((c = getc(in)) != EOF) {
        pos = position(c);
        if (pos > 0) letterCount[pos]++;
    }

    //print the results;
    fprintf(out,"Letter\tFrequrncy\n\n");
    for (pos = 1;pos < 27;pos++) {
        fprintf(out,"%4c\t%8d\n",'a' + pos -1,letterCount[pos]);
    }
    fclose(in);
    fclose(out);
    return 0;
}

int position(char ch) {
    if (isupper(ch)) return ch - 'A' + 1;
    if (islower(ch)) return ch - 'a' + 1;
    return 0;

}