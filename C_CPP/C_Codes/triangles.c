#include <stdio.h>
int main() {
    double a,b,c;
    printf("Enter three sides of triangle : ");
    scanf("%lf %lf %lf",&a,&b,&c);
    
    if ((a>=0 && b>=0 && c>=0) && (a+b>c && b+c>a && c+a>b)) {
        if (a==b && b==c) {
            printf("\n Triangle is Equilateral. ");
        } 
        else if (a==b || b==c || c==a) {
            printf("\n Triangle is Isosceles. ");
        }  
        else {
            printf("\n Triangle is Scalene. ");
        }
        if ((a*a + b*b == c*c) || (b*b + c*c == a*a) || (a*a + c*c == b*b)) {
            printf("\n Triangle is Right Angled. ");
        }
    }
    
    else {
        printf("Invalid sides Input. ");
    }
    
    return 0;
}