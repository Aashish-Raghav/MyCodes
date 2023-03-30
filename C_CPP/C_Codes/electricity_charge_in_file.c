#include<stdio.h>
#include<string.h>

int main() {
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\electricity_data.txt","r");
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\electricity_data_results.txt","w");
    double fcharge,rate,punit,cunit,pay,sum,num,mostbill=0;        //fcharge : fixed charge  punit:previous unit   c : current
    char firstname[10],lastname[10],name[20],mostbill_name[20];

    fscanf(in,"%lf %lf",&fcharge,&rate);
    fscanf(in,"%s",firstname);
    fprintf(out,"Name               Previous_unit     Current_unit      Net_unit       Charge\n\n");

    while (strcmp(firstname,"xxxx") != 0) {
        fscanf(in,"%s",lastname);
        fscanf(in,"%lf %lf",&punit,&cunit);
        pay = (cunit-punit)*rate + fcharge;
        sum += pay;

        //making name;
        strcpy(name,firstname); strcat(name," "); strcat(name,lastname);

         if (mostbill <= pay){
            mostbill=pay;
            strcpy(mostbill_name,name);
        }

        fprintf(out,"%-20s %11.2f %14.2f %14.2f %13.2f \n",name,punit,cunit,cunit-punit,pay);
        fscanf(in,"%s",firstname);
        num++;
    }
    fprintf(out,"\n Numbers of Customers : %1.0f\nTotal due to electricity company : %1.2f\n",num,sum);
    fprintf(out,"%s has highest electricity bill : %1.2f",mostbill_name,mostbill);

    fclose(in);
    fclose(out);

    return 0;
}