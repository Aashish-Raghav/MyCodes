#include <iostream>
using namespace std;
#define ll long long int

void printArr(int* arr,int start,int end)
{
    for (int i = start;i <= end;i++)
        cout << arr[i] << " ";
    cout << endl;
}


int leftOcc(int* arr,int start,int end,int key,int ans = -1)
{
    //base case;
    if (start > end)
        return ans;
    
    int mid = start + (end - start)/2;
    if (arr[mid] == key)
    {
        return leftOcc(arr,start,mid-1,key,mid);
    }
    else if (arr[mid] > key)
        return leftOcc(arr,start,mid-1,key,ans);
    else
        return leftOcc(arr,mid+1,end,key,ans);
    
}

int rightOcc(int* arr,int start,int end,int key,int ans = -1)
{
    //base case;
    if (start > end)
        return ans;
    
    int mid = start + (end - start)/2;
    if (arr[mid] == key)
        return rightOcc(arr,mid+1,end,key,mid);
    else if ( key > arr[mid])
        return rightOcc(arr,mid+1,end,key,ans);
    else
        return rightOcc(arr,start,mid-1,key,ans);
}

inline int noOfOcc(int* arr,int start,int end,int key)
{
    return rightOcc(arr,start,end,key) - leftOcc(arr,start,end,key);
}

int findPeak(int* arr,int start,int end)
{
    if (start == end)
        return end;

    int mid = start + (end - start)/2;
    if (arr[mid] < arr[mid + 1])
        findPeak(arr,mid+1,end);
    else
        findPeak(arr,start,mid);
}

int findPivot(int* arr,int start,int end)
{
    if (start == end)
        return start;
    
    int mid = start + (end - start)/2;
    if (arr[mid] >= arr[start])
        findPivot(arr,mid+1,end);
    else
        findPivot(arr,start,mid);
}

int main()
{
    int arr1[10] = {0};
    cout << "left occurence of " << 9 << " is : " << leftOcc(arr1,0,9,0) << endl;
    cout << "right occurence of " << 9 << " is : " << rightOcc(arr1,0,9,0) << endl;
    cout << "No of occurence of " << 0 << " is : " << noOfOcc(arr1,0,9,0) << endl;

    int arr2[10] = {4,5,6,7,8,9,10,8,6,0};
    int ans = findPeak(arr2,0,9);
    cout << "peak of arr2 : " << arr2[ans] << " at index : " << ans << endl;

    int arr3[10] = {5,6,7,8,9,10,1,2,3,4};
    int pivot = findPivot(arr3,0,9);
    cout << "pivot of arr3 : " << arr3[pivot] << " at index : " << pivot << endl;

    return 0;
}
