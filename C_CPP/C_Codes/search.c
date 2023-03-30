// here we search an element in array;
#include<stdio.h>

int search(char[],int,int,int);
int main() {
    int num; printf("Enter a number to search : "); scanf("%d",&num);
    char arr[] = {1,2,3,4,5,6,7,8};
    if (search(arr,num,0,8) == -1) printf("Element NOt Found!");
    else printf("Element %d is at %d position.",num,search(arr,num,0,8));
    return 0;
}

int search(char arr[],int num,int lo,int hi){
    for (int i = lo;i <hi;i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}