//On 80 % of income and 15k 10%   next 20k 20%  over 35k 25 %
/* Problem 2
On inputting 0 as salary unexpected output*/
#include<stdio.h>
int main() {
    double salary,tsalary,tax;
    printf("Enter Salary : ");
    scanf("%lf",&salary);

    tsalary=salary*0.8;

    if (tsalary <= 15000) {
        tax=tsalary*0.1;
        printf("Amount Of Tax To be Paid : %1.2f\n",tax);
        printf("%1.2f percent of salary",tax/salary*100);
    } else if (tsalary > 15000 && tsalary <= 35000) {
        tax=(tsalary-15000)*0.2 + 15000*0.1;
        printf("Amount Of Tax To be Paid : %1.2f\n",tax);
        printf("%1.2f percent of salary",tax/salary*100);
    } else {
        tax=(tsalary-35000)*0.25 + 20000*0.2 + 15000*0.1;
        printf("Amount Of Tax To be Paid : %1.2f\n",tax);
        printf("%1.2f percent of salary",tax/salary*100);
    }
    return 0;
}

