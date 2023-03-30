#include<stdio.h>

int main() {
    int start,end,factor;
    printf("Type of table : ");         // 7 ki    8 ki      12 ki
    scanf("%d",&factor);

    printf("\nTable from - To : ");
    scanf("%d %d",&start,&end);

    if (start <= end){
        for (int i = start;i<= end;i++){
            printf("%2d X %2d = %4d\n",factor,i,i*factor);
        }
    } else {
        for (int i = end;i<= start;i++){
            printf("%2d X %2d = %4d\n",factor,i,i*factor);
        }
    }

    return 0;
}