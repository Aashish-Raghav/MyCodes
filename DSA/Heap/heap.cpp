#include <iostream>
using namespace std;

class heap{
public:
    int arr[100];
    int size;
    heap(){
        size = 0;
        arr[0] = -1;
    }
    void insert(int value){
        size++;
        int index = size;
        arr[size] = value;

        while (index > 1){
            if (arr[index/2] < arr[index]){
                swap(arr[index/2],arr[index]);
                index /= 2;
            }
            else    
                return;
        }
    }


    void print(){
        for (int i = 1;i <= size;i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void deleteFromHeap(){
        if (size < 1)
            return;
        //first node value to last node;
        arr[1] = arr[size];
        
        //removed last node;
        size--;

        //propagate to correct positon;
        int i = 1;
        while (i < size){
            int rightIndex = 2*i+1;
            int leftIndex = 2*i;

            //checking left;
            if (leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else    
                return;
        }
    }

    
};

void minHeapify(int arr[],int size,int index){
    int smallest = index;
    int left = 2*index ;
    int right = 2*index + 1;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;
    if (right < size && arr[right] < arr[smallest])
        smallest = right;
    

    if (smallest != index){
        swap(arr[index],arr[smallest]);
        minHeapify(arr,size,smallest);
    }
}

void maxHeapify(int arr[],int size,int index){
        int largest = index;

        //finding left and right;
        int left = 2*index;
        int right = 2*index+1;

        //comparing and getting maximum;
        if (left < size && arr[left] > arr[largest])  
            largest = left;
        if (right < size && arr[right] > arr[largest]) 
            largest = right;

        //if changes then swap;
        if (largest != index){
            swap(arr[index],arr[largest]);
            maxHeapify(arr,size,largest);
        }
    }

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();
    int arr[] = { -1,10, 30, 5, 63, 22, 12, 56, 33 };
    for (int i = 8;i > 0;i--){
        maxHeapify(arr,6,i);
    }

    for (int i = 0;i < 9;i++)
        cout << arr[i] << " ";
    cout << endl;

    for (int i = 4;i > 0;i--){
        minHeapify(arr,6,i);
    }
  
    for (int i = 0;i < 9;i++)
        cout << arr[i] << " ";
    cout << endl;


}