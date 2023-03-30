#include<stdio.h>
#include<string.h>

void getString(FILE * in ,char[]);      // IMPORTANT*

int main() {
    char str[100];
    getString(stdin,str);
    printf("\n%s",str);
    return 0;
}

void getString(FILE * in,char str[]) {
    char ch,del;
    int i = 0; 
    while (isspace(ch = getc(in)));
    if (ch == EOF) return;

    del = ch;
    while (((ch = getc(in)) != del) && (ch != EOF)) {
        str[i++] = ch;
    }
    str[i] = '\0';      //IMPORTANT*
}