#include <iostream>
using namespace std;

//using two (start,end) pointer
void Rstring1(string &s,int start,int end)
{
    // cout << "START : " << start << " END : " << end << endl;
    //base case;
    if (start >= end)
        return;
    // cout << s << endl;
    swap(s[start],s[end]);
    Rstring1(s,start+1,end-1);
}
//using single pointer;
void Rstring2(string &s,int i)
{
    //base case;
    if (i > (s.size()-i-1))
        return;
    
    swap(s[i],s[s.size()-i-1]);
    Rstring2(s,i+1);
}

bool checkPallidrome(string& s,int i)
{
    //base case;
    if (i > (s.size()-i-1))
        return true;
        
    if (s[i] != s[s.size()-i-1])
        return false;
    checkPallidrome(s,i+1); 
}

int power(int a,int b)  //O(log n);
{
    //base case;
    if (b == 1)
        return a;
    if (b == 0)
        return 1;

    int ans = power(a,b/2);
    if (b%2 == 0)
        return ans*ans;
    else
        return a*ans*ans;
}

void bubbleSort(int* arr,int size)  //O(n^2);
{
    //base case;
    if (size == 1)
        return;
    
    for (int i = 0;i < size;i++)
    {
        if (arr[i] > arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    bubbleSort(arr,size-1);
}

void selectionSort(int* arr,int size)   //O(n^2)
{
    //base case;
    if (size == 1)
        return;

    int temp = 0;
    for (int i = 0;i < size;i++)
    {
        if (arr[i] > arr[temp])
            temp = i;
    }
    swap(arr[temp],arr[size-1]);
    selectionSort(arr,size-1);
}

void insertionSort(int* arr,int size,int i = 1)
{
    //base case;
    if (size == i)
        return;

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
    insertionSort(arr,size,i+1);
}

int main()
{
    string s;
    s = "Aashish";
    Rstring1(s,0,s.size()-1);
    cout << s << endl;
    Rstring2(s,0);
    cout << s << endl;

    cout.setf(ios_base::boolalpha);
    string s1 = "HelleH";
    cout << checkPallidrome(s1,0) << endl;

    cout << "power(5,3) : " << power(5,3) << endl;

    int arr1[5] = {5,4,3,2,1};
    insertionSort(arr1,5);
    for (int i = 0;i < 5;i++)
        cout << arr1[i] << " ";
    cout << endl;
}