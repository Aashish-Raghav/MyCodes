// Celsius to Fahrenheit conversion   32 + 9c/5;
//Output
/*Celsius  Fahrenheit
     20         68
     22         72
     24         75
     26         79
     28         82
     30         86
     32         90
     34         93
     36         97
     38        100
     40        104 */

#include<stdio.h>

int main () {
    double start,finish,incr;         // c : celsius temp    f : fahrenheit temp
    
    printf("Enter range of temprature : ");
    scanf("%lf %lf",&start,&finish);

    printf("Enter increment Factor : ");
    scanf("%lf",&incr);

    printf("Celsius  Fahrenheit\n");
    if (start <= finish) {
        for (double i=start;i<=finish;i+=incr){
            printf("%7.0f %10.0f \n",i,32 + 9*i/5);
        }
    } else {
        for (double i=finish;i<=start;i+=incr){
            printf("%7.0f %10.0f \n",i,32 + 9*i/5);
        }

    }  
    return 0;
}