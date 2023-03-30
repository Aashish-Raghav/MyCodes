// numbers like 25 36 49, return 1 for true and false for 0;
#include<stdio.h>
int isPerfectSquare(int) ;

int main() {
    int num;
    printf("Enter a number( 0 to end ) : ");
    scanf("%d",&num);
    while ( num != 0 ) {
        printf("%d\n\n",isPerfectSquare(num));
        printf("Enter a number( 0 to end ) : ");
        scanf("%d",&num);
    }
    return 0;
}

int isPerfectSquare(int num) {
    int a = 0;
    for (int i = 1;i <= (num/2);i++){
        if ( num == (i * i) ) {
            a = 1;
        }
    }
    return a==1;
}