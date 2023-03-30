#include <iostream>
using namespace std;

int partition(int* arr,int s,int e)
{
    cout << "p" << endl;
    int pivotIndex = s;
    
    //counting element smaller than pivot;
    int count = 0;
    for (int i = s+1;i <= e;i++)
    {
        if (arr[i] < arr[pivotIndex])
            count++;
    }

    //finding right place of pivot
    pivotIndex += count;

    //swapping the pivot with right place
    swap(arr[pivotIndex],arr[s]);

    //creating doubele pointer to modify array to correct <a a >a format
    int i = s,j = e;

    //modifying;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < arr[pivotIndex])
            i++;
        
        while (arr[j] > arr[pivotIndex])
            j--;
        
        if (i < pivotIndex && j > pivotIndex)
        swap(arr[i],arr[j]);
    }
    return pivotIndex;
}

void quickSort(int* arr,int s,int e)
{
    cout << "in" << endl;
    //base case
    if(s >= e)
        return;
    
    //partition;
    int p = partition(arr,s,e);

    //recursive call to both halves;
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main()
{
    int arr[] = {2,4,65,3,5};
    int n = 5;
    quickSort(arr,0,n-1);
    cout << "sorted" << endl;
    for (int i = 0;i < n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}