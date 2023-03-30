#include <iostream>
#include <queue>
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

template <typename T>
void interleave(queue<T> &q){
    queue<T> firstHalf;
    queue<T> secondHalf;

    int size = q.size();
    for (int i = 0;i < size/2;i++){
        firstHalf.push(q.front());
        q.pop();
    }
    while (!q.empty()){
        secondHalf.push(q.front());
        q.pop();
    }
    while (!firstHalf.empty() && !secondHalf.empty()){
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(secondHalf.front());
        secondHalf.pop();
    }

    // if (!firstHalf.empty()){
    //     q.push(firstHalf.front());
    //     firstHalf.pop();
    // }

    if (!secondHalf.empty()){
        q.push(secondHalf.front());
        secondHalf.pop();
    }
    return;
}

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    printQueue(q);
    interleave(q);
    printQueue(q);
    return 0;
}