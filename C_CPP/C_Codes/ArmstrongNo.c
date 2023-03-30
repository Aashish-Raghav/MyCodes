// armstrong no 370 : 3^3 + 7^3 + 0^3    4234 : 4^4 + 2^4 + 3^4 + 4^4   
/*
#include<stdio.h>
#include<math.h>

int main() {
    int num,i=1,n,sum=0,m;                      // i counts no of digits;
    printf("Enter a number : ");
    scanf("%d",&num);
    
    n=num/10;
    //printf("%d",n);
    while (n != 0 ) {
       // printf("%d",n);
        n=n/10;
        i++;
    }
    n=10*i;
    while (n) {
        m = num / n;
        printf("%d\n",m);
        sum = sum + ( (int) pow(m,i)) ;
        printf("%d \n",sum);
        n=n/10;
    }
    printf("%d \n",sum);
    num == sum ? printf("%d is Armstrong Number.",num) : printf("%d is not a Armstrong Number.",num);
    return 0;

}*/