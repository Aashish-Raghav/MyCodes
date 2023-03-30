//  Selection Sorting;
#include<stdio.h>
void sort(int[],int,int);
int getSmallest(int[],int,int);
void swap(int[],int,int);
int main() {
    int arr[5];
    printf("Enter 5 elements(seperated by space) : ");
    for (int i = 0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,0,5);
    printf("Sorted Array : ");
    for (int i = 0;i<5;i++) {
        printf("%d\t",arr[i]);
    }
    
    return 0;
}
void sort(int arr[],int lo,int hi){
    int small;
    for (int i =lo;i<hi;i++) {
        small = getSmallest(arr,i,hi); 
        swap(arr,i,small);
    }
}
int getSmallest(int arr[],int lo,int hi) {
    int small = lo;
    for (int i = lo;i <hi;i++) {
        if (arr[small] > arr[i]) small = i;
    }
    return small;
}
void swap(int arr[],int large,int small) {
    int t = arr[large];
    arr[large] = arr[small];
    arr[small] = t;
}