#include <iostream>
#include <queue>
using namespace std;

template <class T>
void printQueue(queue<T> q){
    cout << "Your Queue : " << endl;
    while (!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    vector<long long> v;
    deque<long long int> dq;
    
    //creating first window;
    for (int i = 0;i < K;i++){
        if (A[i] < 0){
            dq.push_back(i);
        }
    }
    
    //storing element of the window;
    if (dq.empty())
        v.push_back(0);
    else
        v.push_back(A[dq.front()]);
    
    //traversing other windows;
    for (int i = K;i < N;i++){
        //removal of previous element;
        if (!dq.empty() && (i - dq.front() == K)){
            dq.pop_front();
        }
        
        //adding new element;
        if (A[i] < 0)
            dq.push_back(i);
            
        //storing element of the window;
        if (dq.empty())
            v.push_back(0);
        else
           v.push_back(A[dq.front()]);
    }
    return v;
                                                 
 }

int main(){

    return 0;
}