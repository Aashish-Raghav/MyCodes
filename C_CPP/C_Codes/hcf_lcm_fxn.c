// fxn to find hcf and lcm;
#include<stdio.h>
int hcf(int a,int b);
int lcm(int a,int b);
int main() {
    int a,b;
    printf("Enter Two No. : ");
    scanf("%d %d",&a,&b);
    printf("HCF of %d and %d : %d\n",a,b,hcf(a,b));
    printf("LCM of %d and %d : %d\n",a,b,lcm(a,b));
    return 0;
}

int hcf(int a,int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    } return a;
}

int lcm(int a, int b){
    int hcf_a_b = hcf(a,b);
    return (a*b)/hcf_a_b;
}