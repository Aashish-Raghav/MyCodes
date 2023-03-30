//concept : exchange first with last then 2nd last with 2nd first and so onn
#include<stdio.h>
void reverse(int arr[],int);
void reverse2(int arr[],int n);
int main() {
    int arr[100];
    int h = 0;
    printf("Enter elements ( 0 to end) :\n");
    scanf("%d",&arr[h++]);
    while (arr[h-1] != 0) {
        scanf("%d",&arr[h++]);
    }
    reverse(arr,h-1);                         //Array being pointers are call by refrences in fxn;
    for (int i = 0;i < (h-1);i++){
        printf("%d\t",arr[i]);
    }
    printf("\n\n");
    reverse(arr,(h-1));                         //Array being pointers are call by refrences in fxn;
    for (int i = 0;i < (h-1);i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}
//My thought method;
void reverse(int arr[],int n){
    for (int i = 0,j = n-1;i < n/2,j > n/2;i++,j--) {   // in book condition is i < j;
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
//didi told;
void reverse2(int arr[],int n) {
    for (int i = 0; i < n/2; i ++) {
        int firstval = arr[i];
        int lastval = arr[n-i-1];       // n-i-1 *
        arr[i] = lastval;
        arr[n-i-1] = firstval;
    }
}
