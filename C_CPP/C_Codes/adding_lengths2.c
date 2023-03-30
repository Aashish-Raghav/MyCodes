// arbitary choice of adding data like:
// 3metres 34 cm,  3 34,  3 m 35 cm, 3 m 35 centimetres, 3.35 m ;

// getInt() fxn;

#include<stdio.h>
#include<ctype.h>
int getInt();
int main() {
    int m1,cm1,m2,cm2;
    printf("Enter length1 : ");
    m1 = getInt();
    cm1 = getInt();
    printf("Enter length2 : ");
    m2 = getInt();
    cm2 = getInt();
    printf("\nSum of both lengths : %dm %dcm",m1+m2 + (cm1+ cm2)/100,(cm1 + cm2)%100);
    return 0;
}
int getInt() {
    int num = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        num = num * 10 + ch - '0' ; 
        ch = getchar();
    }
    return num;
}