#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T>
void printQueue(queue<T> q){
    cout << "Your Queue : " << endl;
    while (!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}

queue<int> modifyQueue(queue<int> q, int k) {
    if (k == 1)
        return q;
        
    int n = q.size();
    stack<int> s;
    int i = 0;
    //insert elements to be reversed in stack;
    while (i < k){
        s.push(q.front());
        q.pop();
        i++;
    }
    //insert stack element back into queue (ie in reversed format);
    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    i = 0;
    //insert first unreversed element in back of queue;
    while (i < (n-k)){
        q.push(q.front());
        q.pop();
        i++;
    }
    return q;
}

int main(){

    return 0;
}
