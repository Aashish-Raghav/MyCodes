// using data in employee_data.txt create a text file having name,ovtpay,regpay,net and in end no of employees, total wage,max wage
// employee 

#include<stdio.h>
#include<string.h>
#define MaxRegularHours 40         //SYMBOLIC CONSTANTS *
#define OvertimeFactor 1.5

int main() {
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\employee_data.txt","r");
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\employee_data_results.txt","w");
    char firstname[9],lastname[9],name[19],bestpaid[19];
    double hours,rate,regpay,ovtpay,net,sum,i,mostpay=0;      //i = number of employee

    fprintf(out,"Name                Hours  Rate  Regular  Overtime   Net\n\n");
    fscanf(in,"%s",firstname);

    while (strcmp(firstname,"END") != 0) {
        fscanf(in,"%s %lf %lf",lastname,&hours,&rate);
    
        if ( hours <= MaxRegularHours) {
            regpay= hours * rate;
            ovtpay = 0;
        } else {
            regpay = MaxRegularHours * rate;
            ovtpay = (hours - MaxRegularHours) * rate * OvertimeFactor;
        }
        net= regpay + ovtpay ;
        sum += net;
        i++;

        //make one name out of firstname and lastname;
        strcpy(name,firstname); strcat(name," "); strcat(name,lastname);
        fprintf(out,"%-19s %-6.1f %-6.2f %-8.2f %6.2f %8.2f \n",name,hours,rate,regpay,ovtpay,net);
        fscanf(in,"%s",firstname);
        

        if (mostpay < net) {
            mostpay= net;
            strcpy(bestpaid,name);
        }
    }  
    fprintf(out,"\nNumber Of Employees : %1.0f \n Total wage bill : $%1.2f\n",i,sum);
    fprintf(out,"%s earned the most pay of $%1.2f",bestpaid,mostpay);
    
    fclose(in);
    fclose(out);
    return 0;
}