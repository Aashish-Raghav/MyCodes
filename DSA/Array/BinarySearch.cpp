//Binary Search and its Application;
#include <iostream>
#include <iomanip>
using namespace std;

void print(int arr[],int size);
int binarySearch(int arr[],int size,int key);

//application
int leftOcc(int arr[],int size,int key);
int rightOcc(int arr[],int size,int key);

int peak(int arr[],int size);

int pivot(int arr[],int size);

int doBS(int arr[],int start,int end,int key);
int bsRotatedArr1(int arr[],int size,int key);
int bsRotatedArr2(int arr[],int start,int end,int key);

int squareRoot(int num);
double sqrtPrecise(int num,int precision);

bool isPossible(int arr[],int n,int m,int mid);
int bookAlloc(int arr[],int n,int m);   //n = no of books   m = no of students;

int AggressiveCow(int arr[],int n,int m);
bool isCowPossible(int arr[],int n,int m,int mid);
void selectionSort(int arr[],int size)
{
    for (int i = 0;i < size-1;i++)
    {
        int minIndex = i;
        for (int j = i+1;j < size;j++)
            if (arr[j] < arr[minIndex]) minIndex = j;
        swap(arr[i],arr[minIndex]);
    }
}

int main()
{
    int arr[4] = {10,20,30,40};
    int even[6] = {10,11,13,2,3,4};
    int odd[7] = {6,7,0,1,2,3,4};
    
    print(arr,4);
    cout << "the distance between agrressive cow is : " << AggressiveCow(arr,4,2) << endl;

    // cout << "sqrt(500) == " << squareRoot(500) << endl;
    // cout << setprecision(5) << endl;
    // cout << "sqrtPrecise(500) == " << sqrtPrecise(500,3) << endl;

}

void print(int arr[],int size)
{
    for (int i = 0;i < size;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

int leftOcc(int arr[],int size,int key)
{
    int start = 0,end = size -1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid -1;
        }
        else if (key < arr[mid])
            end = mid -1;
        else
            start = mid + 1;
        
        mid = start + (end - start)/2;
    }
    return ans;
}

int rightOcc(int arr[],int size,int key)
{
    int start = 0,end = size -1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid+1;
        }
        else if (key < arr[mid])
            end = mid -1;
        else    
            start = mid + 1;
        
        mid = start + (end - start)/2;
    }
    return ans;
}

int peak(int arr[],int size)
{
    int start = 0,end = size -1;
    int mid = start + (end - start)/2;

    while (start < end)
    {
        if (arr[mid] < arr[mid+1])
            start = mid + 1;
        else 
            end = mid;
        
        mid = start + (end - start)/2;
    }
    return start;
}

int pivot(int arr[],int size)
{
    int start = 0,end = size-1;
    int mid = start + (end - start)/2;

    while (start < end)
    {
        if (arr[mid] >= arr[0])
            start = mid +1;
        else
            end = mid;
        mid = start + (end - start)/2;
    }
    return start;
}

int doBS(int arr[],int start,int end,int key)
{
    int mid = start + (end - start)/2;
    int i = 1;
    while (start <= end)
    {
        
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;

        mid = start + (end - start)/2;
    }
    return -1;
}

int bsRotatedArr(int arr[],int size,int key)
{
    int start = 0,end = size - 1;
    int pivot_ = pivot(arr,size);
    int ans;

    if (key >= arr[pivot_] && key <= arr[end])
        ans = doBS(arr,pivot_,end,key);
    else    
        ans = doBS(arr,start,pivot_-1,key);
    
    return ans;
}



int squareRoot(int num)
{
    int start = 0,end = num;
    int mid = start + (end - start)/2;
    int ans = -1;

    while (start <= end)
    {
        int value = mid* mid;
        if (num == value)
        {
            return mid;
        }    
        else if (num < value)
        {    
            end = mid - 1;
        }
        else //num > mid * mid
        {
            ans = mid;  //store ans;
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }
    return ans;
}

double sqrtPrecise(int num,int precision)
{
    double ans = squareRoot(num);
    double factor = 1;
    

    for (int i = 1;i <= precision;i++)
    {
        factor /= 10;
        for (double j = ans;j*j <= num;j = j+factor)
        {
            ans = j;
        }
    }
    return ans;
}


int bsRotatedArr2(int arr[],int start,int end,int key)
{
    if (start > end)
        return -1;
    int mid = start + (end - start)/2;
    // cout << "step\n";
    //base case;
    // cout << "mid = " << mid << endl;
    if (arr[mid] == key)
        return mid;

    //mid element is already checked so no need to do it again in any
    //recursive call; 
    if (arr[start] <= arr[mid]) //part start.....mid is sorted;
    {
        //if key in sorted 1 part;
        if (key >= arr[start] && key <=arr[mid])
            return bsRotatedArr2(arr,start,mid-1,key);
        
        //if key in unsorted 2 part;
        return bsRotatedArr2(arr,mid+1,end,key);
    }
    //part start....mid is not sorted;
    //part mid.... end is sorted;
    if (key <= arr[end] && key >= arr[mid])
    {
        //key is in sorted part 2;
        return bsRotatedArr2(arr,mid+1,end,key);    
    }
    //key is in unsorted part 1;
    return bsRotatedArr2(arr,start,mid -1,key);
}

bool isPossible(int arr[],int n,int m,int mid)
{
    int stuCount = 1; 
    int sumPages = 0;
    for (int i = 0;i < n;i++)
    {
        if (sumPages + arr[i] <= mid)
        {
            sumPages += arr[i];
        }
        else
        {
            stuCount++;
            if (stuCount > m || arr[i] > mid)
            {
                return false;
            }
            sumPages = arr[i];
        }
    }
    return true;
}

int bookAlloc(int arr[],int n,int m)
{
    int start = 0;
    int sum = 0;
    for (int i = 0;i < n;i++)
    {
        sum += arr[i];
    }
    int end = sum;
    int mid = start + (end - start)/2;
    int ans = -1;

    while (start <= end)
    {
        if (isPossible(arr,n,m,mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else    
            start = mid + 1;

        // cout << mid << endl;
        mid = start + (end - start)/2;
    }
    return ans;
}

bool isCowPossible(int arr[],int n,int m,int mid)
{
    int cowCount = 1;
    int lastPos = arr[0];
    // print(arr,n);
    for (int i = 0;i < n;i++)
    {
        // cout << "mid = " << mid << endl;
        // cout << "cowCount = " << cowCount << endl;
        // cout << "lastPos = " << lastPos << endl;
        // cout << "arr[i] = " << arr[i] << endl << endl;

        if (arr[i] - lastPos >= mid)
        {
            // cout << "Yes In " << endl;
            cowCount++;
            if (cowCount == m)
                return true;
            lastPos = arr[i];
        }
    }
    return false;
}
int AggressiveCow(int arr[],int n,int m)
{
    selectionSort(arr,n);
    int start = 1,end = arr[n-1];
    // cout << "start = " << start << " end = " << end << endl;
    int mid = start + (end - start)/2;
    int ans = -1;
    while (start <= end)
    {
        cout << "ans = " << ans << endl;
        if (isCowPossible(arr,n,m,mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;

        mid = start + (end - start)/2;
    }
    return ans;
}