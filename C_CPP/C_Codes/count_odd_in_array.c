// count no of odd numbers in array;
#include<stdio.h>
int countOdd(int arr[],int);
int main() {
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    printf("No of odd numbers : %d",countOdd(arr,n));
    return 0;
}
int countOdd(int arr[],int n) {
    int count = 0;
    for (int i = 0;i < n;i++){
        if (arr[i] % 2 != 0) count++;
    }
    return count;
}