//selection sort;
#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[],int size);
void selectionSort(int arr[],int size);
void bubbleSort1(int arr[],int size);
void bubbleSort2(int arr[],int size);
void bubbleSort3(int arr[],int size);
void insertionSort1(int arr[],int size);
void insertionSort2(int arr[],int size);

int beautifulTriplets(int d, vector<int> arr) {
    int count = 0;
    if (arr.size() < 3)
        return count;
    for (int i = 0;i < arr.size()-2;i++)
    {
        cout << "step 1" << endl;
        int j = i+1;
        while(arr[j] - arr[i] <= d)
        {
            cout << "step 2" << endl;
            if (arr[j] - arr[i] == d)
            {
                int k = j+1;
                while (arr[k] - arr[j] <= d)
                {
                    cout << "step 3" << endl;
                    if (arr[k] - arr[j] == d)
                    {
                        cout << "i = "<< arr[i] << " j = "<< arr[j] << " k = "<< arr[k] << endl;
                        count++;
                        break;
                    }
                    k++;
                }
            }
            j++;
        }
    }
    return count;
}

int main()
{
    vector <int> v = {1, 2, 4, 5, 7, 8, 10};
    cout << "No of Triplets = " <<beautifulTriplets(3,v) << endl;
    int arr[] = {1,5,2,3,4};
    printArr(arr,5);
    insertionSort2(arr,5);
    printArr(arr,5);
    return 0;
}

void printArr(int arr[],int size)
{
    for (int i = 0;i < size;i++)
        cout << arr[i] << " ";
    cout << endl;
}
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

void bubbleSort1(int arr[],int size)
{
    for (int i = size - 1;i > 0;i--) //i will run from size - 1  to i = 1 (total i -1 passes);
    {
        bool swapped = false;
        for (int j = 0;j < i;j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            return;
    }
}

void bubbleSort2(int arr[],int size)
{
    for (int i = 0;i < size-1;i++)  //i will run from 0 to size - 2 (total size - 1 passes);
    {
        bool swapped = false;
        for (int j = 0;j < size - i- 1;j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            return;
    }
}

void bubbleSort3(int arr[],int size)
{
    for (int i = 1;i < size;i++)    //i will go from 1 to size -1 ; (total size -1 passes);
    {
        bool swapped = false;
        for (int j = 0;j < size - i;j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap (arr[j] , arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            return;
    }
}

void insertionSort1(int arr[],int size)
{
    for (int i = 1;i < size;i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (;j >= 0;j--)
        {
            if (arr[j] > temp)
                arr[j+1] = arr[j]; 
            else
                break;
        }
        arr[j+1] = temp;
    }
}

void insertionSort2(int arr[],int size)
{
    int i = 1;
    while (i < size)
    {
        
        int temp = arr[i];
        int j = i-1;
        while (j >= 0)
        {
            if (arr[j] > temp)
                arr[j+1] = arr[j];
            else
                break;
            j--;
        }
        arr[j+1] = temp;
        cout << "After " << i << " run\n";
        printArr(arr,size);
        i++;
    }
}