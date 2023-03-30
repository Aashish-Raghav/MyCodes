#include <iostream>
using namespace std;

class CircularQueue{
private:
    int* arr;
    int front_;
    int rear_;
    const int max_size;
public:
    CircularQueue(int size): max_size(size){
        arr = new int[max_size];
        front_ = rear_ = -1;
    }

    ~CircularQueue(){
        delete arr;
    }

    bool push(int element){
        //check overflow
        if ( (front_ == 0 && rear_ == max_size-1) || (rear_ == front_ - 1)){
            cout << "Queue Overflow " << endl;
            return false;
        }
        //first element insertion
        if (front_ ==  -1 && rear_ == -1){
            arr[rear_+1] = element;
            rear_ = front_ = 0;
            return true;
        }

        rear_ = (rear_+1)%max_size;
        arr[rear_] = element;
        return true;
    }

    bool pop(){
        //check underflow;
        if ( (front_ == -1 && rear_ == -1)){
            cout << "Stack Underflow" << endl;
            return false;
        }
        //only 1 element;
        if (front_ == rear_){
            arr[front_] = -1;
            rear_ = front_ = -1;
            return true;
        }

        //more than 1 element;
        arr[front_] == -1;
        front_ = (front_ + 1) % max_size;
        return true;
    }
    bool empty(){
        if (rear_ == -1){
            return true;
        }
        return false;
    }

    int front(){
        if (this->empty())
            return -1;
        return arr[front_];
    }

    int back(){
        if (this->empty())
            return -1;
        return arr[rear_];
    }

};
int main(){
    CircularQueue cq(5);
    cq.push(12);
    cq.push(13);
    cq.push(14);
    cq.push(15);
    cq.push(16);
    cout << cq.front() << endl;
    cout << cq.back() << endl;
    cout << cq.empty() << endl;
    cq.pop();

    cout << cq.front() << endl;
    cout << cq.back() << endl;
    cout << cq.empty() << endl;
    cq.pop();

    cout << cq.front() << endl;
    cout << cq.back() << endl;
    cout << cq.empty() << endl;
    cq.pop();

    cout << cq.front() << endl;
    cout << cq.back() << endl;
    cout << cq.empty() << endl;
    cq.pop();

    cq.push(17);
    cq.push(18);
    cq.push(19);
    cq.push(20);
    cq.push(21);
    cout << cq.front() << endl;
    cout << cq.back() << endl;
    
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();

    cout << cq.front() << endl;
    cout << cq.back() << endl;

    return 0;
}