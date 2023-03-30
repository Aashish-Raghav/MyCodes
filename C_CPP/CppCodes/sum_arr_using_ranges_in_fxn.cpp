#include<iostream>
int sum_arr(const int * begin,const int * end);
int main() 
{
    using namespace std;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    cout << "Sum of arr is : " << sum_arr(arr,arr+10) << endl;
    cout << "Sum of arr(first five elements) : " << sum_arr(arr,arr + 5) << endl;
    cout << "Sum of arr(last five elements) : " << sum_arr(arr +5,arr+10) << endl;
    return 0;
}
int sum_arr(const int * begin,const int* end){
    const int* pt;
    int total = 0;
    for (pt = begin;pt!=end;pt++){
        total += *pt;
    }
    return total;
}