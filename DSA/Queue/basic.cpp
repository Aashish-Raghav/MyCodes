#include <iostream>
#include <queue>
using namespace std;

template <class T>
void printQueue(queue<T> q){
    cout << "Your Queue : " << endl;
    while (!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;
}

int main(){

    return 0;
}