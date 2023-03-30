#include<iostream>
int sum_arr(int *,int);
int sum_arr1(int[],int);
int main() 
{
    using namespace std;
    int arr[] = {1,2,3,4,5,6,7,8};
    cout << "Sum is : " << sum_arr(arr + 4,4) << endl;
    cout << "sum is : " << sum_arr1(arr,4);

    return 0;
}
int sum_arr(int * arr,int size)
{
    int sum =0;
    for (int i =0;i < size;i++){
        sum += *(arr + i);
    }
    return sum;
}

int sum_arr1(int arr[],int size)
{
    int sum = 0;
    for (int i = 0;i < size;i++){
        sum += arr[i];
    }
    return sum;
}