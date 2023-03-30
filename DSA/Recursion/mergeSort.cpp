#include <iostream>
using namespace std;
void merge1(int* arr,int start,int mid,int end)
{
    int n = mid - start + 1;
    int m = end - mid;
    int* first = new int[n];
    int* second = new int[m];

    //copying the values of array in two halfs;
    int arrayIndex = start;
    for (int i = 0;i < n;i++)
        first[i] = arr[arrayIndex++];
    
    arrayIndex = mid + 1;
    for (int i = 0;i < m;i++)
        second[i] = arr[arrayIndex++];
    
    
    //merging two sorted array;
    arrayIndex = start;
    int i = 0,j = 0;
    while (i < n && j < m)
    {
        if (first[i] < second[j])
            arr[arrayIndex++] = first[i++];
        else
            arr[arrayIndex++] = second[j++];
    }

    while (i < n)
        arr[arrayIndex++] = first[i++];
    while (j < m)
        arr[arrayIndex++] = second[j++];

    delete [] first;
    delete [] second;
}

void merge2(int* arr,int start,int mid,int end)
{
    int i = 0,j = mid+1;
    while(i <= mid && j <= end)
    {
        if (arr[i] > arr[mid])
        {
            
        }
    }

}

void mergeSort(int* arr,int start,int end)
{
    //base case
    if (start >= end)
        return;
    
    int mid = start + (end - start)/2;

    //sorting left part
    mergeSort(arr,start,mid);

    //sorting right part
    mergeSort(arr,mid+1,end);

    merge1(arr,start,mid,end);
}

int main()
{
    int arr[] = {5,3,2,6,23,7,6,25};
    mergeSort(arr,0,7);
    for (int i = 0;i < 8;i++)
        cout << arr[i] << " ";
    cout << endl;
}