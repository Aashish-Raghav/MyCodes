#include <iostream>
using namespace std;

void heapify(int arr[],int size,int index){
    int largest = index;
    int left = 2*index;
    int right = 2*index + 1;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
}

void heapSort(int arr[],int size){
    
    while (size > 1){
        swap(arr[1],arr[size-1]);
        size--;
        heapify(arr,size,1);
    }

}

int main(){
    int arr[6] = {-1,12,15,2,3,5};
    int size = 6;
    for (int i = size/2;i > 0;i--)
        heapify(arr,size,i);
    heapSort(arr,size);
    for (int i = 1;i < size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}