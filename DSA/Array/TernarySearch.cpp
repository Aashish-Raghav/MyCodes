#include <iostream>
using namespace std;

int ternarySearch(int arr[],int l,int r,int key){
    if (l > r)
        return -1;
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
        return ternarySearch(arr,mid1+1,mid2 - 1,key);
}

int main(){
    int arr[10] = {10,21,30,46,54,60,71,87,945,1000};
    int key = 1000;
    int index = ternarySearch(arr,0,9,key);
    cout << key << " at " << index << endl;
}
