//we have to find the maximum occurence of element in array and which element;

#include <iostream>
using namespace std;
const int MaxSize = 12;

void printArr(int arr[],int size);
void findMaxOccu1(int arr[],int MaxSize);   //TC : O(n)  ,  SC : O(n)
void findMaxOccu2(int arr[],int MaxSize);

int main()
{
    //creating array of random size;
    int* arr = new int[10];
    // *arr = {0,0,0,0,0,0,0,0,0,0};
    printArr(arr,MaxSize);
    // for (int i = 0;i < MaxSize;i++)
    // {
    //     arr[i] = rand() % MaxSize;
    // }
    // printArr(arr,MaxSize);
    // findMaxOccu2(arr,MaxSize);
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

void findMaxOccu1(int arr[],int MaxSize)
{
     //storing occurence of count;
    int count[MaxSize] = {0};
    for (int i = 0;i < MaxSize;i++)
    {
        count[arr[i]]++;
    }

    //finding maximum occurence;
    int max = INT16_MIN;
    int index;
    for (int i = 0;i < MaxSize;i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            index = i;
        }
    }

    cout << "\nNumber = " << index << endl;
    cout << "Occurence = " << max << endl;
}

void findMaxOccu2(int arr[],int MaxSize)
{
    for (int i = 0;i < MaxSize;i++)
    {
        arr[arr[i] % MaxSize] += MaxSize;
    }

    printArr(arr,MaxSize);
    int max = 0;
    int repeating_item = 0;
    for (int i = 0;i < MaxSize;i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            repeating_item = i;
        }
    }
    cout << "Nummber = " << repeating_item << endl;
    cout << "Occurence = " << max /MaxSize << endl;
}