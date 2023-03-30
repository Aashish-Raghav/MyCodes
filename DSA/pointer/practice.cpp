#include<iostream>
using namespace std;

void printArr(int arr[],int size);

void updateDptr(int **p2)
{
    // p2 = p2 + 1;   
    //kch hoga ? //nhi....

    // *p2 = *p2 + 1;
    //kch hoga ? //yes ptrS will point to new memory;

    **p2 = **p2 + 1;
    //kch hoga ? //yes, actual value will be changed
}

int main()
{

    int arr[5] = {3,10,3,4,5};
    cout << "Address = " << arr << endl;
    cout << "Address = " << &arr[0] << endl;

    cout << "arr[i] = *(arr + i) : " << arr[1] << endl;
    cout << "i[arr] = *(i + arr) : " << 1[arr] << endl; //Totally unbelievable.....

    int * ptr = arr;
    cout << "sizeof(arr) = " << sizeof(arr) << endl;
    cout << "sizeof(&arr) = " << sizeof(&arr) << endl;  //same as above
    cout << "sizeof(ptr) = " << sizeof(ptr) << endl;
    cout << "sizeof(*ptr) = " << sizeof(*ptr) << endl;  //same as sizeof(double);
    cout << "sizeof(&ptr) = " << sizeof(&ptr) << endl;

    printArr(arr,5);
    cout << *ptr << endl;
    cout << *(ptr++) << endl;
    cout << (*ptr)++ << endl;
    cout << *ptr++ << endl;
    cout << *ptr << endl;

    printArr(arr,5);

    //character array;
    char ch[6] = "Hello";
    ch[5] = 't';
    cout << ch << endl;
    
    //double pointer;
    int value = 10;
    int* ptrS = &value;
    int** ptrD = &ptrS;

    //printing value by using ptr value and ptrD;
    cout << "value = " << value << endl;
    cout << "*ptrS = " << *ptrS << endl;
    cout << "**ptrD = " << **ptrD << endl;

    //printing address of value;
    cout << "&value = " << &value << endl;
    cout << "ptr = " << ptrS << endl;
    cout << "*ptrD = " << *ptrD << endl;

    //printing address of pointerS;
    cout << "&ptrS = " << &ptrS << endl;
    cout << "ptrD = " << ptrD << endl;
    // cout << "&&value = " << &&value << endl;

    //in function;
    cout << "Before update : \n";
    cout << "value = " << value << endl;
    cout << "ptrS = " << ptrS << endl;
    cout << "ptrD = " << ptrD << endl;
    updateDptr(ptrD);
    cout << "After update : \n";
    cout << "value = " << value << endl;
    cout << "ptrS = " << ptrS << endl;
    cout << "ptrD = " << ptrD << endl; 

    //constant keyword with pointer;
     int ans = 10;
    int* const pans = &ans;
    cout << "ans : " << ans << endl;
    cout << "pans : " << *pans << endl;
    // *pans = 12;
    cout << "ans : " << ans << endl;
    cout << "pans : " << *pans << endl;

    return 0;
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