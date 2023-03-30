#include <stdio.h>
int main() {
   double c1,c2,c3,sum;
   printf("Enter cost of three items : ");
   scanf("%lf %lf %lf",&c1,&c2,&c3);
   sum=c1+c2+c3;
   //printf("%lf",sum);
   //printf("%lf %lf %lf",c1,c2,c3);
   if (sum>=300) {
       printf("Payable Amount : %lf",sum-sum*0.15);
   }
   
   else printf("Payable Amount : %lf",sum);
   return 0;
}