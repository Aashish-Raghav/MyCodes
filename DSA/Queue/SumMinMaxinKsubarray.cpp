//we have to find sum of minimum and maximum
// elemenets of all subarrays of size k;

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
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

vector<int> solve(vector<int> v,int k){
    deque<int> maxi;
    deque<int> mini;
    maxi.push_back(0);
    mini.push_back(0);
    vector<int> ans;
    //traversing first window;
    //MY CODE
    for (int i = 0;i < k;i++){
        if (v[maxi.front()] < v[i]){
            maxi.pop_front();
            maxi.push_back(i);
        }
        if (v[mini.front()] > v[i]){
            mini.pop_front();
            mini.push_back(i);
        }
    }

    //BABBAR BHAIYA CODE;
    /*
    for (int i = 0;i < k;i++){
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        
        maxi.push_back();
        mini.push_back();
    }
    
    
    
    */
    cout << v[mini.front()] << " " << v[maxi.front()] << endl;
    int sum = v[mini.front()] + v[maxi.front()];
    ans.push_back(sum);

    //processing other windows;
    for (int i = k;i < v.size();i++){
        while (!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }
        while (!mini.empty() && i - mini.front() >= k){
            mini.pop_front();
        }
        if (v[maxi.front()] < v[i]){
            maxi.pop_front();
            maxi.push_back(i);
        }
        if (v[mini.front()] > v[i]){
            mini.pop_front();
            mini.push_back(i);
        }
        cout << v[mini.front()] << " " << v[maxi.front()] << endl;
        sum = v[mini.front()] + v[maxi.front()];
        ans.push_back(sum);
    }

    return ans;
}

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(-1);
    v.push_back(7);
    v.push_back(-3);
    v.push_back(-1);
    v.push_back(-2);

    vector<int> ans(4);
    ans = solve(v,4);
    for (int i = 0;i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}