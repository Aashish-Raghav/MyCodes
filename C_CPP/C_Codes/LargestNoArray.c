#include<stdio.h>

int main() {
    int arr[100];
    int i = 0,max;
    printf("Enter numbers (0 to end) : \n");
    scanf("%d",&arr[i++]);
    max = arr[i-1];
    while (arr[i-1] != 0) {
        scanf("%d",&arr[i++]);
        if (arr[i-1] >= max ) max = arr[i-1];
        //printf("%d %d\n",i,arr[i]);

    }
    //printf("%d",i);
    if (i == 0) return 0;
    else {
        for (int j = 0;j <= i-1;j++) {
            printf("%d ",arr[j]);
        }
        printf("\nMaximum is %d",max);
        return 0;
    }
}