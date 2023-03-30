#include <iostream>
using namespace std;

class Queue{
private:
    int* arr;
    int front_;
    int rear_;
    const int max_size;
public:
    Queue() : max_size(100001) {
        arr = new int[max_size];
        front_ = rear_ = 0;
    }

    ~Queue() {

    }

    bool push(int element){
        //overflow check;
        if (rear_ == max_size){
            cout << "Queue Overflow" << endl;
            return false;
        }
        arr[rear_++] = element;
        return true;
    }

    bool pop(){
        //check underflow
        if (front_ == rear_){
            cout << "Queue Underflow " << endl;
            return false;
        }
        arr[front_++] = -1;
        if (front_ == rear_){
            front_ = rear_ = 0;
        }
        return true;
    }
    
    int front(){
        if (front_ == rear_){
            return -1;
        }
        else 
            return arr[front_];
    }

    int back(){
        if (rear_ == front_){
            return -1;
        }
        return arr[rear_-1];
    }

    bool empty(){
        if (front_ == rear_){
            return true;
        }
        return false;
    }
};

int main(){
    Queue q;
    q.push(12);
    q.push(13);
    q.push(14);
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    cout << q.empty() << endl;

    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    cout << q.empty() << endl;

    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    cout << q.empty() << endl;

    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    cout << q.empty() << endl;
    return 0;
}