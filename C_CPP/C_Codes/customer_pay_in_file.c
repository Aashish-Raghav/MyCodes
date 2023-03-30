#include<stdio.h>
#include<string.h>

int main() {
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\customer_pay.txt","r");
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\customer_pay_results.txt","w");
    
    char item[10];
    double price,discount,pay_amt,num_item=0,sum;

    fscanf(in,"%s",item);
    fprintf(out,"item        Price   Discount   Pay_Amount\n\n");
    while (strcmp(item,"END") != 0) {
        fscanf(in,"%lf %lf",&price,&discount);
        pay_amt=price - discount*price/100;

        fprintf(out,"%-10s %5.2f %10.2f %10.2f \n",item,price,discount,pay_amt);
        num_item++;
        sum=sum + pay_amt;
        fscanf(in,"%s",item);           //PROBLEM: Last item in output file is not in proper orientation
    }
    fprintf(out,"\n Numbers of Items : %1.0f",num_item);
    fprintf(out,"\n Net Amount to be Paid : %1.2f",sum);
    return 0;

    fclose(in);
    fclose(out);
}