#include<stdio.h>

int main() {
    int start,end,a=0;
    printf("Enter starting & ending of Range : ");
    scanf("%d %d",&start,&end);

    printf("Prime No. in range %d - %d are : \n",start,end);

    for (int i = start; i <= end ; i++){
        a=0;
        
        for (int j = 2; j <= i/2 ;j++){
            if ( i % j == 0) a=1;                 
        }
        
        if (a==0) printf("%d \n",i);                //NOTE : a==0  & a=0  has a lot differnece use carefully. 
    }

    return 0;
}