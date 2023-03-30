#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void swapAlternate(int arr[],int size);
void printArr(int arr[],int size);
void printArr(vector<int> v);
int findUnique(int arr[],int size);
int findDuplicate(int arr[],int size);
vector<int> findIntersection(int arr1[],int size1,int arr2[],int size2);
void sort01_1(int arr[],int size);  //count (worst algo);
void sort01_2(int arr[],int size);  //two pointer approach;

void sort012_1(int arr[],int size);

int binarySearch(int arr[],int size,int key);

void mergeTwoSortedArr(int arr1[],int size1,int arr2[],int size2,vector<int> &v);

void moveZeros1(int arr[],int size);
void moveZeros2(int arr[],int size);
void moveZeros3(int arr[],int size);

void rotateArr(vector<int> arr,int k,vector<int> &v);

bool ifRotatedSorted(vector<int> arr);

void sumTwoArr1(int arr1[],int size1,int arr2[],int size2,vector<int> &v);
void sumTwoArr2(vector<int> v1,vector<int> v2);

int main()
{
    vector<int> v;
    printArr(v);
    int arr1[7] = {0,0,0,1,10,0,1};
    int arr2[3] = {9,9,9};
    moveZeros2(arr1,7);
    sumTwoArr1(arr1,3,arr2,3,v);
    printArr(arr1,7);


}

void printArr(int arr[],int size)
{
    if (size > 0)
    {
        cout << "Your Array :\n";
        for (int i = 0;i < size;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "Empty Array\n";
}

void printArr(vector<int> v)
{
    cout << "Your Vector = ";
    for (int i = 0;i < v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void swapAlternate(int arr[],int size)
{
    int i = 0,temp;
    while (i+1 < size)
    {
        // temp = arr[i];
        // arr[i] = arr[i+1];
        // arr[i+1] = temp;
        //or
        swap(arr[i],arr[i+1]);
        i+=2;
    }
}

int findUnique(int arr[],int size)
{
    int ans = 0;
    for (int i = 0;i < size;i++)
    {
        ans = ans^arr[i];
    }
    return ans;
}

int findDuplicate(int arr[],int size)
{
    int ans = 0;
    for (int i = 0;i < size;i++)
    {
        ans = ans^arr[i];
    }
    for (int i = 1;i < size;i++)
    {
        ans = ans^i;
    }
    return ans;
}

vector<int> findIntersection(int arr1[],int size1,int arr2[],int size2)
{
    int count1  = 0,count2 = 0;
    vector<int> common;
    while (count1 < size1 && count2 < size2)
    {
        if (arr1[count1] == arr2[count2])
        {
            common.push_back(arr1[count1]);
            count1++;
            count2++;
        }
        else if (arr1[count1] < arr2[count2])
        {
            count1++;
        }
        else
            count2++;
    }
    if (common.size() == 0)
        common.push_back(-1);

    return common;

}

void sort01_1(int arr[],int size)
{
    int count0 = 0,count1 =0;
    for (int i = 0;i < size;i++)
    {
        if (arr[i] == 0)
            count0++;
        else    
            count1++;
    }
    for (int i = 0;i < size;i++)
    {
        if (count0)
        {
            arr[i] = 0;
            count0--;
        }
        else
            arr[i] = 1;
    }
}

void sort01_2(int arr[],int size)
{
    int left = 0,right = size-1;
    while (left < right)
    {
        while (arr[left] == 0 && left < right)
            left++;
        while (arr[right] == 1 && left < right)
            right--;
        if (left < right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}

void doSortTwo(int arr[],int size,int n1,int n2,int no)
{
    int left = 0,right = size-1;
    while (left < right)    //sorting 0 & 1 only,leaving 2 unaltered;
    {
        if (arr[left] == no)
        {
            left++;
            continue;
        }

        if (arr[right] == no)
        {
            right--;
            continue;
        }

        while (arr[left] == n1 && left < right)
            left++;

        while (arr[right] == n2 && left < right)
            right--;
        if (arr[left] == n2 && arr[right] == n1)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}

void sort012_1(int arr[],int size)
{
    doSortTwo(arr,size,0,1,2);//sorting 0 & 1 only,leaving 2 unaltered;
    printArr(arr,size);

    doSortTwo(arr,size,1,2,0);//sorting 1 & 2 only,leaving 0 unaltered;
    printArr(arr,size);

    doSortTwo(arr,size,0,1,2);//sorting 0 & 1 only,leaving 2 unaltered;
    printArr(arr,size);
}

int binarySearch(int arr[],int size,int key)
{
    int start = 0,end = size - 1;
    int mid = start + (end - start)/2;

    while (start <= end)
    {
        if (arr[mid] == key)
            return mid;

        if (key < arr[mid])
            end = mid - 1;
        else //key > arr[mid]
            start = mid + 1;
        
        mid = start + (end - start)/2;
    }
    return -1; 
}

void mergeTwoSortedArr(int arr1[],int size1,int arr2[],int size2,vector<int> &v)
{
    int i = 0,j = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            v.push_back(arr1[i++]);
        }
        else
            v.push_back(arr2[j++]);
    }

    if ( i != size1 -1 )
    {
        while (i < size1)
            v.push_back(arr1[i++]);
    }

    if ( j != size2 -1 )
    {
        while (j < size2)
            v.push_back(arr2[j++]);
    }
}

void moveZeros1(int arr[],int size)
{
    int i = 1;
    while (i < size)
    {
        int temp = arr[i];
        int k = i-1;
        while (k >= 0)
        {
            if (arr[k] == 0)
                arr[k+1] = arr[k];
            else
                break;
            k--;
        }
        arr[k+1] = temp;
        i++;
    }
}

void moveZeros2(int arr[],int size)
{
    int i = 0,j = 0;
    while (j != size)
    {
        printArr(arr,size);
        if (arr[j] != 0)
        {
            swap(arr[j],arr[i]);
            i++;
        }
        j++;
    }
}

void moveZeros3(int arr[],int size)
{
    int i = 0;
    for (int j = i;j < size;j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[j],arr[i]);
            i++;
        }
    }
}

void rotateArr(vector<int> arr,int k,vector<int> &v)
{
    for (int i = 0;i < arr.size();i++)
        v.push_back(arr[(i+k)%arr.size()]);

    // printArr(v);
}

bool ifRotatedSorted(vector<int> arr)
{
    int count = 0;
    int i;
    for (i = 0;i < arr.size() - 1;i++)
    {
        if (arr[i] > arr[i+1])
            count++;
    }
    if (arr[i] > arr[0])
        count++;
    // cout << count << endl;
    return count <= 1;

}

void sumTwoArr1(int arr1[],int size1,int arr2[],int size2,vector<int> &v)
{
    // vector<int> v;
    int i = size1 - 1,j = size2 - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry != 0)
    {
        int v1 = 0;
        if (i >= 0)
        {
            v1 = arr1[i];
        }

        int v2 = 0;
        if (j >= 0)
        {
            v2 = arr2[i];
        }

        int sum = v1 + v2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        // cout << sum << endl;
        v.push_back(sum);
        i--;j--;
    }
    
    //reverse algo;
    for (int i = 0,j = v.size() - 1;i < j;i++,j--)
        swap(v[i],v[j]);
}

void sumTwoArr2(vector<int> v1,vector<int> v2)
{
    int i = 0,j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
            i++;
        else
        {
            v1[i] = v2[j++];
        }
    }
}