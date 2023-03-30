#include <iostream>
#include <iomanip>
#include <array>
using namespace std;
//under namespace std;
//static in natue;
//continuous memory allocation


template <class T>
void printArr(array<T,4> arr)
{
    for (int i = 0;i < 4;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    //initialisation;
    array<int,4> arr1 = {1,2,3,4};   //array<type,size> name;    
    array<int,4> arr2 = {1};    // 1 0 0 0 

    //traversing
    printArr(arr1);
    printArr(arr2);

    //methods;
    cout << "arr.size() = " << arr1.size() << endl;
    cout << "random access by arr.at(2) = " << arr1.at(2) << endl; 
    cout << "by arr[i] = " << arr1[2] << endl;
    cout << boolalpha ;
    cout << "arr.empty() return bool = " << arr1.empty() << endl;
    cout << "arr.front() = " << arr1.front() << endl;
    cout << "arr.back() = " << arr1.back() << endl;
    // cout << "arr.clear() = " << arr1.back() << endl;

    return 0;
}