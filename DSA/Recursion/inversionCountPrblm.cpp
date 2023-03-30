#include <iostream>
using namespace std;

int merge(int* arr,int start,int mid,int end)
{
    int len1 = mid - start + 1;
    int len2 = end - mid;

    //creating temporary array;
    int* first = new int[len1];
    int* second = new int[len2];

    //copying the values;
    int arrayIndex = start;
    for (int i = 0;i < len1;i++)
        first[i] = arr[arrayIndex++];
    
    arrayIndex = mid + 1;
    for (int i = 0;i < len2;i++)
        second[i] = arr[arrayIndex++];

    int i = 0,j = 0;
    arrayIndex = start;
    int temp = start;
    int ans = 0;
    while (i < len1 && j < len2)
    {
        if (second[j] < first[i])
        {
            arr[arrayIndex++] = second[j++];
            ans += mid - temp;
        }
        else{
            arr[arrayIndex++] = first[i++]; temp++;
        }
    }

    while (i < len1)
    {
        arr[arrayIndex++] = first[i++];
    }
    
    while (j < len2)
        arr[arrayIndex++] = second[j++];
    cout << "ans " << ans << endl;
    return ans;
}

int mergeSort(int* arr,int start,int end)
{
    int ans = 0,mid;
    //base case;
    if (start < end)
    {
        mid = start + (end - start)/2;


        ans += mergeSort(arr,start,mid);
        // cout << "ans 2 " << ans << endl;        
        ans += mergeSort(arr,mid+1,end);
        // cout << "ans 3 " << ans << endl;        
        ans += merge(arr,start,mid,end);
        cout << "ans 4 " << ans << endl;
    }
    return ans;
}

int main()
{
    int arr[] = {8,4,2,1};
    cout << mergeSort(arr,0,3) << endl;
}