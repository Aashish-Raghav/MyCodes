#include <iostream>
using namespace std;

int ternarySearch(int arr[],int l,int r,int key){
    int mid1 = l + (r-l)/3;
    int mid2 = r - (r-l)/3;
    
    if (arr[mid1] == key)
        return mid1;
    if (arr[mid2] == key)
        return mid2;
    

    if (arr[mid1] > key){
        return ternarySearch(arr,l,mid1 - 1,key);
    }
    else if (arr[mid2] < key){
        return ternarySearch(arr,mid2+1,r,key);
    }
    else
        return ternarySearch(arr,mid+1,mid2 - 1,key);
}

int main(){

}