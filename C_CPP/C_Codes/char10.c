// count no of occurences of each vowels in passage;
#include<stdio.h>
int main() {
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\char10.txt","r");
    char ch;
    int numE = 0,numA = 0,numI = 0,numO = 0,numU = 0 ;
    while ((ch = getc(in)) != EOF){
        if (ch == 'e' || ch == 'E') numE++;
        if (ch == 'a' || ch == 'A') numA++;
        if (ch == 'i' || ch == 'I') numI++;
        if (ch == 'o' || ch == 'O') numO++;
        if (ch == 'u' || ch == 'U') numU++;
    }
    printf("No. of vowel 'a' : %d \n",numA);
    printf("No. of vowel 'e' : %d \n",numE);
    printf("No. of vowel 'i' : %d \n",numI);
    printf("No. of vowel 'o' : %d \n",numO);
    printf("No. of vowel 'u' : %d \n",numU);

    return 0;
}
