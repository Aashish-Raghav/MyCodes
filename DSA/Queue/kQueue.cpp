#include <iostream>
#include <queue>
using namespace std;

class kQueue{
private:
    const int n;
    const int k;
    int *front;
    int *rear;
    int *arr;
    int* next;
    int freeSpot;
public:
    kQueue(int n,int k) : n(n) , k(k) , freeSpot(0) {
        front = new int[k];
        rear = new int[k];

        for (int i = 0;i < k;i++){
            front[i] = rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0;i < n-1;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;

        arr = new int[n];
        for (int i = 0;i < n;i++){
            arr[i] = 0;
        }
    }

    void enqueue(int element,int q){
        //check overflow;
        if (freeSpot == -1){
            cout << "Queue Overflow " << endl;
            return;
        }
        
        //create an index of free available slot;
        int index = freeSpot;
        //update freeSpot;
        freeSpot = next[index];

        //if first element;
        if (front[q-1] == -1){
            front[q-1] = index;
        }
        else{
            //create linkage b/w curr rear and new rear;
            next[rear[q-1]] = index;
        }
        //for pop fxn use we are making;
        next[index] = -1;

        //updating rear;
        rear[q-1] = index;

        //we are all done freespot , front,next,rear updated;
        //add element to arr;
        arr[index] = element;
        return;
    }

    int pop(int q){
        //check underflow;
        if (front[q-1] == -1){
            cout << "Queue underflow!" << endl;
            return -1;
        }

        //index of element to be delete is front of queue;
        int index = front[q-1];
        
        //updating front of that queue;
        front[q-1] = next[index];

        //updating index of next to freespot;
        next[index] = freeSpot;

        //update freespot;
        freeSpot = index;
        return arr[index];
    }
    friend void printNext(kQueue q){
        cout << "Next Array : " << endl;
        for (int i = 0;i< q.n;i++){
            cout << q.next[i] << " ";
        }
        cout << endl;
    }

    friend void printArr(kQueue q){
        cout << "arr Array : " << endl;
        for (int i = 0;i< q.n;i++){
            cout << q.arr[i] << " ";
        }
        cout << endl;
    }

    friend void printFront(kQueue q){
        cout << "Front array : " << endl;
        for (int i = 0;i< q.k;i++){
            cout << q.front[i] << " ";
        }
        cout << endl;
    }

    friend void printRear(kQueue q){
        cout << "Rear Array : " << endl;
        for (int i = 0;i< q.k;i++){
            cout << q.rear[i] << " ";
        }
        cout << endl;
    }

};


int main(){
    kQueue q(8,3);
    printArr(q);
    printFront(q);
    printRear(q);
    printNext(q);
    q.enqueue(12,1);
    q.enqueue(13,1);
    q.enqueue(14,2);
    q.enqueue(15,2);
    q.enqueue(16,1);
    q.enqueue(17,1);
    q.enqueue(18,3);
    q.enqueue(19,3);
    q.enqueue(20,3);

    printArr(q);
    printFront(q);
    printRear(q);
    printNext(q);

    q.pop(1);
    q.pop(2);
    q.pop(1);
    q.pop(3);
    q.pop(2);

    printArr(q);
    printFront(q);
    printRear(q);
    printNext(q);
 

    
    return 0;
}