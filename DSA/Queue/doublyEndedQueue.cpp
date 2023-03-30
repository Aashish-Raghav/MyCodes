#include <bits/stdc++.h> 
using namespace std;
class Deque
{
private:
    int* arr;
    int front_;
    int rear_;
    const int max_size;
public:
    // Initialize your data structure.
    Deque(int size) : max_size(size){
        arr = new int[max_size];
        front_ = rear_ = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int element)
    {
        //overflow
        if ( this->isFull()){
            // cout << "Queue Overflow" << endl;
            return false;
        }

        //if first element
        if (this->isEmpty()){
            front_ = rear_ = 0;
            arr[front_] = element;
            return true;
        }

        //front_ = 0;
        front_ = (front_ == 0) ? max_size-1 : front_-1;
        arr[front_] = element;
        return true; 
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int element)
    {
        //check overflow;
        if (this->isFull()){
            //  cout << "Queue overflow " << endl;
            return false;
        }

        //if first element;
        if (this->isEmpty()){
            front_ = rear_ = 0;
            arr[front_] = element;
            return true;
        }
        rear_ = (rear_+1)%max_size;
        arr[rear_] = element;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
    //check underflow;
        if (this->isEmpty()){
            // cout << "Queue Underflow" << endl;
            return -1;
        }
        //if one element only;
        int ans = arr[front_];
        if (front_ == rear_){
            arr[front_] = -1;
            front_ = rear_ = -1;
            return ans;
        }
        arr[front_] = -1;
        front_ = (front_ + 1) % max_size;
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        //check underflow;
        if (this->isEmpty()){
            // cout << "Queue Underflow" << endl;
            return -1;
        }
        int ans = arr[rear_];
        //if one element only;
        if (front_ == rear_){
            arr[front_] = -1;
            front_ = rear_ = -1;
            return ans; 
        }
        
        arr[rear_] = -1;
        rear_ = (rear_ == 0)? max_size -1 : rear_-1;
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (this->isEmpty())
            return -1;
        else
            return arr[front_];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (this->isEmpty())
            return -1;
        else
            return arr[rear_];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front_ == -1 && rear_ == -1)
            return true;
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front_ == 0 && rear_ == max_size -1)
                || (front_ != 0 && rear_ == front_ -1))
            return true;
        return false;
    }
};