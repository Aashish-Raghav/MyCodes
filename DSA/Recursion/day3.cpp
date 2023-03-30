#include<iostream>
using namespace std;
//sum of array;
int sumArray(int* arr,int size)     //O(n)
{
    if (size == 0)
        return 0;
    // if (size == 1)
        // return arr[0];

    return arr[0] + sumArray(arr+1,size -1);
}

//array is sorted or not;
bool isSorted(int* arr,int size)    //O(n)
{
    //base case;
    if (size == 0 || size == 1)
        return true;


    if (arr[0] > arr[1])
        return false;
    else
        return isSorted(arr+1,size-1);
}

//key in array;
bool linearSearch(int* arr,int size,int key)    //O(n);
{
    //base case;
    if (arr[0] == key)
        return true;
    if (size == 0)
        return false;

    return linearSearch(arr+1,size -1,key);
}

bool binarySearch(int* arr,int start,int end,int key)   //o(logn);
{
    //base case
    if (start > end)
        return false;
    int mid = start + (end - start)/2;
    if (arr[mid] == key)
        return true;
    else if (arr[mid] > key)
        return binarySearch(arr,start,mid -1,key);
    else
        return binarySearch(arr,mid+1,end,key);
}
int main()
{
    int arr[5] = {1,2,5,5,5};
    cout << sumArray(arr,5) << endl;

    cout.setf(ios_base::boolalpha);
    cout << "is sorted : " << isSorted(arr,5) << endl;

    cout << "1 in array : " << binarySearch(arr,0,4,5) << endl;
}