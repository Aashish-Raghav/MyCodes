#include<iostream>
int sum(int (*arr)[4],int);      //using pointer accessing 2D arrray;
int main() 
{
    using namespace std;
    int arr[2][4] ={{1,2,3,4},{5,6,7,8}};
    int total = sum(arr,2);
    cout << "Total of 2D array is : " << total;
    return 0;
}

int sum(int (*arr)[4],int n) {
    int total = 0;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < 4;j++){      //i rows and j columns;
            total += *(*(arr + i) + j);    // == arr[i][j];   
        }
    }
    return total;
}