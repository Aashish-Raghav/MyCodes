#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> q){
    cout << "Your queue : " << endl;
    int size = q.size();
    for (int i = 0;i < size;i++){
        cout << q.front() << endl;
        q.pop();
    }
    return;
}

int main(){
    queue<int> q;
    q.push(12);
    q.push(13);
    q.push(14);
    printQueue(q);
    cout.setf(ios_base::boolalpha);
    cout << q.back() << endl;
    cout << q.empty() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.empty() << endl;
    return 0;
}