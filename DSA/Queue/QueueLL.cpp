//queue using linked list;
#include <iostream>
using namespace std;

class Queue{
private:
    struct Node{
        int data;
        Node* next;
    };
    Node* front;
    Node* rear;
    const int max_size;
    int size_;
public:
    Queue(int s) : max_size(s) ,size_(0){

    }

    ~Queue(){

    }

    int size(){
        return size_;
    }

    bool empty(){
        if (size_ == 0)
            return true;
        return false;
    }

    bool push(int element){
        if (size_ == max_size){
            cout << "Queue Overflow" << endl;
            return false;
        }
        Node* temp = new Node;
        temp->data = element;
        temp->next = NULL;
        if (size_ == 0){
            front = rear = temp;
            size_++;
            return true;
        }
        rear->next = temp;
        rear = rear->next;
        size_++;
        return true;
    }

    bool pop(){
        if (size_ == 0){
            cout << "Queue underflow" << endl;
            return false;
        }
        Node* temp = front;
        if (front == rear){
            delete front;
            size_--;
            return true;
        }
        while (temp->next != rear){
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = NULL;
        rear = temp;
        size_--;
        delete del;
    }

    void display(){
        if (this->empty())
            cout << "Queue is empty." << endl;
        else{
            Node* temp = front;
            cout << "Your Queue : " << endl;
            while (temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(){
    Queue q(20);
    q.push(10);
    q.push(12);
    q.push(14);
    cout << q.size() << endl;
    q.display();
    cout << q.empty() << endl;
    q.pop();
    q.pop();
    cout << q.size() << endl;
    q.display();
    q.pop();
    cout << q.size() << endl;
    q.display();
    return 0;
}