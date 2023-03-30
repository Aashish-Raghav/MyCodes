#include<iostream>
#include<cstring>

template <typename T>
T maxn(T arr[],int n){
    T max = arr[0];
    for (int i = 0;i < n;i++){
        if (max < arr[i]) max = arr[i]; 
    }
    return max;
}

template <> const char* maxn(const char* arr[],int n){
    const char* str = arr[0];
    for (int i = 0; i < n;i++){
        if (strlen(str) < strlen(arr[i])) str = arr[i];
    }
    return str;
}

int main() 
{
    using namespace std;
    int arr1[] = {1,3,4,5,3,7};
    double arr2[] = {12.34,23.7,32.34,33.5};
    const char* arr3[] = {"Aashish","Raghav","Hello","world","class"};
    
    cout << "Maximum of integer array : " << maxn(arr1,6) << endl;
    cout << "Maximum of double array : " << maxn(arr2,4) << endl;
    cout << "Maximum of char* array : " << maxn(arr3,5) << endl;

    return 0;
}