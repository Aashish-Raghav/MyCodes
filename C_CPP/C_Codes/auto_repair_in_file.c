//inspecting vehicle costs $75
//charge : $75 per hour + cost of parts,minimum charge = $120

#include<stdio.h>

#define InspectionCosts 75
#define ChargePerHour 75
#define MinCharge 120

int main() {
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\auto_repair.txt","r");
    FILE * out = fopen("E:\\c programming\\C_Codes\\TextFiles\\auto_repair_results.txt","w");
    
    double hours,part_cost,charge,sum = 0;
    fscanf(in,"%lf",&hours);
    fprintf(out,"Hours_Worked   Part_Cost   Charge\n\n");

    while (hours != -1) {
        fscanf(in,"%lf",&part_cost);
        charge = hours * ChargePerHour + part_cost;
        sum += charge;
        if (charge <= 120) {
            charge = 120;
        } 
        fprintf(out,"%11.2f %11.2f %9.1f\n",hours,part_cost,charge + InspectionCosts);
        fscanf(in,"%lf",&hours);
    }

    fprintf(out,"\nTotal Charge for all jobs : %1.2f",sum);

    return 0;
}