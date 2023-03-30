#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T>
void printQueue(queue<T> q){
    cout << "Your Queue : " << endl;
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

//approach1; using recursion
template <class T>
void reverseQueue1(queue<T> &q){
    if (q.empty())
        return;
    T temp = q.front();
    q.pop();
    reverseQueue1(q);
    q.push(temp);
    // insertAtBottom(q,temp);
}

//approach using stack
template <class T>
void reverseQueue2(queue<T> &q){
    stack<T> s;
    while (!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return;
}

int main(){
    queue<int> q;
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    printQueue(q);
    reverseQueue1(q);
    printQueue(q);
    reverseQueue2(q);
    printQueue(q);
    return 0;
}