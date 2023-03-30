#include<stdio.h>

int main() {
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\lengths.txt","r");
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\lengths_results.txt","w");
    int inches1,inches2,inches_total,feets1,feets2,feets_total;
    fscanf(in,"%d %d",&inches1,&inches2);

    fprintf(out,"Length 1                         Length 2                             Sum\n\n");

    while (inches1 != 0 || inches2 != 0) {          // condition dhyan se*  or ki jgh and likh dia toh logic error
        feets1=inches1 / 12;
        feets2=inches2 / 12;
        inches_total = inches1 + inches2;
        feets_total= inches_total /12 ;
        //yards1;
        fprintf(out,"%d yards %d feets %d inches \t\t",feets1 / 3,feets1 % 3,inches1 % 12);
        fprintf(out,"%d yards %d feets %d inches \t\t\t",feets2 / 3,feets2 % 3,inches2 % 12);
        fprintf(out,"%d yards %d feets %d inches \n",feets_total / 3,feets_total % 3,inches_total% 12);

        fscanf(in,"%d %d",&inches1,&inches2);
    }
    fclose(in);
    fclose(out);

    return 0;
}