// directly...
#include<stdio.h>
int main() {
    int num,fnum=1;
    printf("Enter a No. : ");
    scanf("%d",&num);
    if (num == 1 || num == 0) {
        printf("factorial of %d : %d",num,fnum);
    } else if (num >= 2) {
        for (int i = 2; i <= num;i++) {
            fnum = fnum * i;
        }
        printf("factorial of %d : %d",num,fnum);
    } else printf("Invalid Input");
    return 0;
}