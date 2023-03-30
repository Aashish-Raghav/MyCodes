#include<stdio.h>

int main () {
    double start,finish,incr;         // c : celsius temp    f : fahrenheit temp
    
    printf("Enter range of temprature : ");
    scanf("%lf %lf",&start,&finish);

    printf("Enter increment Factor : ");
    scanf("%lf",&incr);

    printf("Fahrenheit  Celsius\n");
    if (start <= finish) {
        for (double i=start;i<=finish;i+=incr){
            printf("%9.0f %9.0f \n",i,5*(i-32)/9);
        }
    } else {
        for (double i=finish;i<=start;i+=incr){
            printf("%9.0f %9.0f \n",i,5*(i-32)/9);
        }

    }  
    return 0;
}