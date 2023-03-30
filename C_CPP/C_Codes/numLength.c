//input an integer and numLength returns its length.
#include<stdio.h>
int numLength(int);
int main() {
    int num;
    printf("Enter number(0 to end) : ");
    scanf("%d",&num);
    while (num != 0 ) {
        printf("length(%d) : %d\n\n",num,numLength(num));
        printf("Enter number(0 to end) : ");
        scanf("%d",&num);
    }

    return 0;
}
int numLength(int num){
    int length=0;
    do {
        num = num/10;
        length++;
    } while( num != 0 );
    return length;
}