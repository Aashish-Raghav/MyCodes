#include<stdio.h>

int main() {
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\numbers.txt","r");
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\numbers_avg.txt","w");
    double num,sum=0,i=0,avg;
    fscanf(in,"%lf",&num);
    
    while (num) {
        sum = sum + num;
        fscanf(in,"%lf",&num);
        i++;     
    }
    avg=sum/i;
    fprintf(out,"Average is : %1.2f",avg);

    printf("Commands Processed successfully");
    
    fclose(in);
    fclose(out);
    return 0;
}

