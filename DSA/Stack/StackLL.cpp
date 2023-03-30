//implementation of stack using linked list;
#include <iostream>
using namespace std;

struct Node{
public:
    int data;
    Node* next;    
};

Node* insertAtHead(Node* &head,int element){
    Node* newNode = new Node;
    newNode->next = head;
    newNode->data = element;
    return newNode;
}

Node* deleteAtHead(Node* &head){
    Node* del = head;
    head = head->next;
    delete del;
    return head;
}

class Stack{
private:
    Node* head;
    // Node* tail;
    int top;
    int max_size;
public:
    Stack(int size) : max_size(size),top(1) {}
    bool full() const {
        return (top == max_size)? true : false;
    }
    bool empty() const {
        return (top == 1)?true : false;
    }

    void push(const int element){
        if (full())
            cout << "stack overflow" << endl;
        else{
            head = insertAtHead(head,element);
            top++;
        }
    }
    
    void pop(){
        if (empty())
            cout << "Stack underflow" << endl;
        else {
            head = deleteAtHead(head);
            top--;
        }
    }

    int peek() const {
        if (empty()){
            cout << "Empty stack" << endl;
            return -1;
        }
        return head->data;
    }

    inline int size() const{
        return top-1;
    }

};

int main()
{
    Stack stack(30);
    cout << "top empty stack : " << stack.peek() << endl;
    stack.push(12);
    stack.push(13);
    stack.push(14);
    cout <<"top : " <<  stack.peek() << endl;
    cout << "size " << stack.size() << endl;
    cout.setf(ios_base::boolalpha);
    cout << stack.empty() << endl;
    stack.pop();
    cout << stack.peek() << endl;
    cout << stack.size() << endl;
    stack.pop();
    stack.pop();
    cout << stack.empty() << endl;
    cout << stack.size() << endl;
    stack.pop();
    cout << "reached" << endl;
    return 0;
}